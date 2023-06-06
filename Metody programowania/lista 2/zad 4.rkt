#lang racket

(define (% x m) (- x (* (floor (/ x m)) m)))
  
(define-struct matrix (a b c d))
(define matrix-id (make-matrix 1 0 0 1))
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

(define (matrix-exp-fast m n)
  (define (exp m n res)
    (cond [(= n 0) res]
          [(= (% n 2) 1) (exp (matrix-mult m m) (floor (/ n 2)) (matrix-mult res m))]
          [else (exp (matrix-mult m m) (floor (/ n 2)) res)]))
  (exp m n matrix-id))
(print-m (matrix-exp-fast (make-matrix 1 2 3 4) 5))

(define (fib-fast k)
  (define C (make-matrix 1 1 1 0))
  (matrix-a (matrix-exp-fast C (- k 1))))

(fib-fast 9)
