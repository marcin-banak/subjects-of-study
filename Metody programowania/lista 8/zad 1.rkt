#lang racket
(define (append! xs ys)
  (if (equal? (mcdr xs) '())
      (set-mcdr! xs ys)
      (append! (mcdr xs) ys)))

(define (cycle! xs)
  (if (null? xs)
      '()
      (append! xs xs)))

(define x (mcons 1 (mcons 2 (mcons 3 (mcons 4 '())))))

x