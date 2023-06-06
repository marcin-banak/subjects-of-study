#lang racket

(define A (list 1 2 3 4))

(define (suffixes A)
  (cond [(null? A) (list null)]
        [else (cons A (suffixes (rest A)))]))

(suffixes A)
