#lang racket
(define (foldr-reverse xs)
  (foldr (lambda (y ys) (append ys (list y))) null xs))

(define (foldl-reverse xs)
  (foldl (lambda (y ys) (cons y ys)) null xs))

(foldr-reverse '(1 2 3 4 5 6 7 8 9 10))
(length (foldr-reverse (build-list 100000 identity)))