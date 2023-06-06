#lang plait

(define-type Op
  (op-add) (op-mul) (op-sub) (op-div) (op-pow))

(define-type Op-un
  (op-fact) (op-min))

(define-type Exp
  (exp-number [n : Number])
  (exp-op [op : Op] [e1 : Exp] [e2 : Exp])
  (exp-op-un [op : Op-un] [e : Exp]))

(define (length xs acc)
  (if (empty? xs)
      acc
      (length (rest xs) (+ 1 acc))))

(define (pow x n)
  (if (= n 0)
      1
      (* x (pow x (- n 1)))))

(define (factorial x)
  (if (= x 0)
      1
      (* x (factorial (- x 1)))))

(define (minus x)
  (* -1 x))

(define (parse-Op s)
  (let ([sym (s-exp->symbol s)])
  (cond
    [(equal? sym '+) (op-add)]
    [(equal? sym '-) (op-sub)]
    [(equal? sym '*) (op-mul)]
    [(equal? sym '/) (op-div)]
    [(equal? sym '^) (op-pow)])))

(define (parse-Op-un s)
  (let ([sym (s-exp->symbol s)])
    (cond
      [(equal? sym '!) (op-fact)]
      [(equal? sym '~) (op-min)])))

(define (parse-Exp s)
  (cond
    [(s-exp-number? s) (exp-number (s-exp->number s))]
    [(s-exp-list? s)
     (if (= (length (s-exp->list s) 0) 3)
         (let ([xs (s-exp->list s)])
           (exp-op (parse-Op  (first  xs))
                   (parse-Exp (second xs))
                   (parse-Exp (third  xs))))
         (let ([xs (s-exp->list s)])
           (exp-op-un (parse-Op-un (first xs))
                      (parse-Exp (second xs)))))]))
                   

; ==============================================

(define (eval-op op)
  (type-case Op op
    [(op-add) +]
    [(op-sub) -]
    [(op-mul) *]
    [(op-div) /]
    [(op-pow) pow]))

(define (eval-op-un op)
  (type-case Op-un op
    [(op-fact) factorial]
    [(op-min) minus]))

(define (eval e)
  (type-case Exp e
    [(exp-number n) n]
    [(exp-op op e1 e2)
     ((eval-op op) (eval e1) (eval e2))]
    [(exp-op-un op e)
     ((eval-op-un op) (eval e))]))

(define exp (parse-Exp `(+ (^ 2 (~ -2)) (! 3))))
(eval exp)