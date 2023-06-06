#lang racket

(define ((my-compose f g) x)
  (f (g x)))

(define (square x)
  (* x x))
(define (increment x)
  (+ x 1))

((my-compose square increment) 5)
((my-compose increment square) 5)

((my-compose square increment) 8)
((my-compose increment square) 8)

((my-compose square increment) 11)
((my-compose increment square) 11)