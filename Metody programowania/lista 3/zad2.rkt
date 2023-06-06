#lang racket

(define (product xs)
  (foldl (lambda (x val) (* val x)) 1 xs))

(product '(1 2 3 4 5))