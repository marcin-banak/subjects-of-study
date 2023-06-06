#lang plait

(define (f1 a b)
  a)

(define (f2 f g x)
  (f x (g x)))

(define (f3 f)
  (f (lambda (x) (f (lambda (x) x)))))

(define (f4 f g x)
  ((lambda (x) (pair (f x) (g x))) x))

(define (f5 f x)
  (if (some? (f x))
      (cons (snd (some-v (f x))) (f5 f (fst (some-v (f x)))))
      '()))
