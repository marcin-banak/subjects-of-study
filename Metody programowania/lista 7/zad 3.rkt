#lang racket

(define/contract (suffixes1 xs)
  (parametric->/c [a] (-> (listof a) (listof (listof a))))
  (if (null? xs)
      '()
      (cons xs (suffixes1 (rest xs)))))

(define (suffixes2 xs)
  (if (null? xs)
      '()
      (cons xs (suffixes2 (rest xs)))))

(time (suffixes1 (range 3000)) 0)
(time (suffixes2 (range 3000)) 0)