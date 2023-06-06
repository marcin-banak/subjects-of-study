#lang racket

(provide (struct-out column-info)
         (struct-out table)
         (struct-out and-f)
         (struct-out or-f)
         (struct-out not-f)
         (struct-out eq-f)
         (struct-out eq2-f)
         (struct-out lt-f)
         table-insert
         table-project
         table-sort
         table-select
         table-rename
         table-cross-join
         table-natural-join)

(define-struct table (schema rows) #:transparent)
(define-struct column-info (name type) #:transparent)

(define-struct and-f (l r)) ; koniunkcja formuł
(define-struct or-f (l r)) ; dysjunkcja formuł
(define-struct not-f (e)) ; negacja formuły
(define-struct eq-f (name val)) ; wartość kolumny name równa val
(define-struct eq2-f (name name2)) ; wartości kolumn name i name2 równe
(define-struct lt-f (name val)) ; wartość kolumny name mniejsza niż val

(define cities
   (table
     (list (column-info 'city 'string)
            (column-info 'country 'string)
            (column-info 'area 'number)
            (column-info 'capital 'boolean))
     (list (list "Wrocław" "Poland" 293 #f)
            (list "Warsaw" "Poland" 517 #t)
            (list "Poznan" "Poland" 262 #f)
            (list "Berlin" "Germany" 892 #t)
            (list "Munich" "Germany" 310 #f)
            (list "Paris" "France" 105 #t)
            (list "Rennes" "France" 50 #f))))

(define countries
   (table
     (list (column-info 'country 'string)
            (column-info 'population 'number))
     (list (list "Poland" 38)
            (list "Germany" 83)
            (list "France" 67)
            (list "Spain" 47))))

(define (empty-table columns) (table columns '()))

; Funkcje pomocnicze:
(define (in x xs) 
    (cond [(null? xs) #f]
          [(equal? x (first xs)) #t]
          [else (in x (rest xs))]))

(define (get-<-operator var)
  (cond [(string? var) string<?]
        [(symbol? var) symbol<?]
        [(number? var) <]
        [(boolean? var) (lambda (v1 v2) (cond [(= v1 v2) #f]
                                              [v1 #f]
                                              [else #t]))]))

(define (get-row-value col row schema)
  (if (equal? (column-info-name (first schema)) col)
      (first row)
      (get-row-value col (rest row) (rest schema))))
      

; =================================================================

(define  (table-insert row tab)
  (define (equal-columns row tab)
    (if (equal? (length row) (length (table-schema tab)))
        #t
        (error "błędna ilość kolumn")))
  (define (it row info)
    (if (null? row)
        #t
        (cond [(equal? (column-info-type (first info)) 'number)
               (if (number? (first row))
                   (it (rest row) (rest info))
                   (error "niepoprawny typ"))]
              [(equal? (column-info-type (first info)) 'string)
               (if (string? (first row))
                   (it (rest row) (rest info))
                   (error "niepoprawny typ"))]
              [(equal? (column-info-type (first info)) 'symbol)
               (if (symbol? (first row))
                   (it (rest row) (rest info))
                   (error "niepoprawny typ"))]
              [(equal? (column-info-type (first info)) 'boolean)
               (if (boolean? (first row))
                   (it (rest row) (rest info))
                   (error "niepoprawny typ"))])))

  (if (and (equal-columns row tab) (it row (table-schema tab)))
      (table (table-schema tab) (cons row (table-rows tab)))
      tab))

; =================================================================

(define (table-project cols tab)
  (define (rec-info info)
    (if (null? info)
        '()
        (if (in (column-info-name (first info)) cols)
            (cons (first info) (rec-info (rest info)))
            (rec-info (rest info)))))
  (define (rec-cols info row) 
    (if (null? info)
        '()
        (if (in (column-info-name (first info)) cols)
            (cons (first row) (rec-cols (rest info) (rest row)))
            (rec-cols (rest info) (rest row)))))
  (define (rec-rows rows) 
    (if (null? rows)
        '()
        (cons (rec-cols (table-schema tab) (first rows)) (rec-rows (rest rows)))))
  (table (rec-info (table-schema tab)) (rec-rows (table-rows tab))))

; =================================================================

(define (table-rename col ncol tab) 
  (define (it-info info)
    (cond [(null? info) '()]
          [(equal? col (column-info-name (first info))) (cons (column-info ncol (column-info-type (first info))) (rest info))]
          [else (cons (first info) (it-info (rest info)))]))
  (table (it-info (table-schema tab)) (table-rows tab)))

; =================================================================

(define (table-sort cols tab)
  (define (sort-rows cols)
    (if (null? cols)
        (table-rows tab)
        (sort (sort-rows (rest cols)) (lambda (r1 r2)
                                             ((get-<-operator (get-row-value (first cols) r1 (table-schema tab)))
                                              (get-row-value (first cols) r1 (table-schema tab))
                                              (get-row-value (first cols) r2 (table-schema tab)))))))
  (table (table-schema tab) (sort-rows cols)))

; =================================================================

(define (table-select form tab)
  (let ([schema (table-schema tab)])
    (define (formula-to-function form)
      (cond [(and-f? form) (lambda (row)
                             (and
                              ((formula-to-function (and-f-l form)) row)
                              ((formula-to-function (and-f-r form)) row)))]
            [(or-f? form) (lambda (row)
                             (or
                              ((formula-to-function (or-f-l form)) row)
                              ((formula-to-function (or-f-r form)) row)))]
            [(not-f? form) (lambda (row)
                             (not ((formula-to-function (not-f-e form)) row)))]
            [(eq-f? form) (lambda (row)
                            (equal?
                             (get-row-value (eq-f-name form) row schema)
                             (eq-f-val form)))]
            [(eq2-f? form) (lambda (row)
                             (equal?
                              (get-row-value (eq2-f-name form) row schema)
                              (get-row-value (eq2-f-name2 form) row schema)))]
            [(lt-f? form) (lambda (row)
                            ((get-<-operator (lt-f-val form))
                             (get-row-value (lt-f-name form) row schema)
                             (lt-f-val form)))]))

    (table schema (filter (formula-to-function form) (table-rows tab)))))
  
; =================================================================

(define (table-cross-join tab1 tab2)
  (table (append (table-schema tab1) (table-schema tab2))
         (map flatten (cartesian-product (table-rows tab1) (table-rows tab2)))))

; +

(define (table-natural-join x) #f)


