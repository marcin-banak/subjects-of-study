#lang racket

(define A '(1 34  23 34 23 43))

(define (elem x A)
  (cond[(null? A) #f]
       [(= x (first A)) #t]
       [else (elem x (rest A))]))

(elem 34 A)
(elem 12331 A)
  

