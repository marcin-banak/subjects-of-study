#lang racket

(define (negatives x)
  (build-list x (lambda (x) (- -1 x))))

(negatives 10)

;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (reciprocals x)
  (build-list x (lambda (x) (/ 1 (+ x 1)))))

(reciprocals 10)

;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (evens x)
  (build-list x (lambda (x) (* x 2))))

(evens 10)

;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (identityM n)
  (define (iter n i)
  (if (= i n)
      null
      (cons (build-list n (lambda (x) (if (= 0 (- i x)) 1 0))) (iter n (+ i 1)))))
  (iter n 0))


(identityM 5)