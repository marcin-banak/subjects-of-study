#lang plait

(define (apply f x) (f x)) ; (('a -> 'b) 'a -> 'b)
(define (compose f g) (lambda (x) (f (g x)))) ; (('a -> 'b) ('c -> 'a) -> ('c -> 'b))
(define (flip f) (lambda (x y) (f y x))) ; (('a 'b -> 'c) -> ('b 'a -> 'c))
(define (curry f) (lambda (x) (lambda (y) (f x y)))) ; (('a 'b -> 'c) -> ('a -> ('b -> 'c)))

(define f1_1 (curry compose)) ; (('_a -> '_b) -> (('_c -> '_a) -> ('_c -> '_b)))
(define f1_2 (lambda (x) (lambda (y) (lambda (z) (x (y z))))))

(define f2_1 ((curry compose) (curry compose))) ; (('_a -> ('_b -> '_c)) -> ('_a -> (('_d -> '_b) -> ('_d -> '_c))))
(define f2_2 (lambda (y) (lambda (z) ((lambda (x) (lambda (y) (lambda (z) (x (y z))))) (y z)))))

