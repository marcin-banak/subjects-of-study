#lang racket

(define A (list 23 4 1 32 3 2 5 6 0 43 6 87 34))

(define (select A)
  (define (catch-up l x)
    (if (= (first l) x)
        null
        (append (list (first l)) (catch-up (rest l) x))))
  (define (find xs left right)
    (cond [(null? xs) (append (list (first right)) left (rest right))]
          [(< (first xs) (first right)) (find (rest xs) (catch-up A (first xs)) xs)]
          [else (find (rest xs) left right)]))
  (find A (first A) (rest A)))

(define (select-sort xs)
  (define A (select xs))
  (if (null? A)
      null
      (cons (first A) (select-sort (rest A)))))