#lang racket

(define A '(1 23 23 4 32 1 34 2 23 324))
(define (maximum xs)
  (define (max A curr)
    (cond [(null? A) curr]
          [(> (first A) curr) (max (rest A) (first A))]
          [else (max (rest A) curr)]))
  (define maks (first A))
  (if (null? A)
      "-inf.0"
      (max xs maks)
      ))

(maximum A)

