#lang racket

(define (reverse! lst)
  (define (reverse current prev)
    (if (null? current)
        prev
        (let ([next (mcdr current)])
          (set-mcdr! current prev)
          (reverse next current))))
  (reverse lst '()))

(define example-mlist (mcons 1 (mcons 2 (mcons 3 '()))))
(reverse! example-mlist)