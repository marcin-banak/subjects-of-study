#lang racket

(require rackunit)

(define (square a b c)
  (cond [(and (> a b) (> a c)) (* a a)]
        [(and (> b a) (> b c)) (* b b)]
        [else (* c c)]))
(check-equal? (square 1 2 3) 9)
(check-equal? (square 1 5 3) 25)
(check-equal? (square 13 12 11) 169)