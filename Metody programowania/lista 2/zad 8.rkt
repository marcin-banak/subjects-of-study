#lang racket

(define A '( 1 23 23 4 32 1 34 2 23))
(define B '(1 23 43 45 46 234 355))

(define (sorted A)
  (cond [(null? (rest A)) #t]
        [(> (first A) (first (rest A))) #f]
        [else (sorted (rest A))]))

(sorted A)
(sorted B)
