#lang racket

(define-struct matrix (a b c d))
(define A (make-matrix 1 2 3 4))
(define B (make-matrix 1 2 3 4))

(define (print-m m)
  (list (matrix-a m)
        (matrix-b m)
        (matrix-c m)
        (matrix-d m)))

(define (matrix-mult m n)
  (make-matrix (+ (* (matrix-a m) (matrix-a n)) (* (matrix-b m) (matrix-c n)))   ;a
               (+ (* (matrix-a m) (matrix-b n)) (* (matrix-b m) (matrix-d n)))   ;b
               (+ (* (matrix-c m) (matrix-a n)) (* (matrix-d m) (matrix-c n)))   ;c
               (+ (* (matrix-c m) (matrix-b n)) (* (matrix-d m) (matrix-d n))))) ;d

(print-m (matrix-mult A B))

(define matrix-id (make-matrix 1 0 0 1))
(print-m matrix-id)

(define (matrix-exp m k)
  (cond [(= k 0) matrix-id]
        [(matrix-mult m (matrix-exp m (- k 1)))]))
(print-m (matrix-exp A 5))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (fib-matrix k)
  (define C (make-matrix 1 1 1 0))
  (matrix-a (matrix-exp C (- k 1))))

(fib-matrix 9)