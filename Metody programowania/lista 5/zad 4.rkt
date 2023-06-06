#lang plait

(define (remove xs x)
  (filter (lambda (y) (not (= x y))) xs))
;(remove '(1 2 3 4) 1)

(define (append-to-all x xs)
  (cond [(empty? xs) '()]
        [else (cons (append (list x) (first xs)) (append-to-all x (rest xs)))]))
;(all-possible 1 '((1 2 3) (1 2 5)))

(define (connect xs ys)
  (if (empty? xs)
      ys
      (connect (rest xs) (cons (first xs) ys))))

(define (perms xs)
  (if (empty? xs)
      '(())
      (local
        [(define (perms-it ys acc)
           (if (empty? ys)
               acc
               (perms-it
                (rest ys)
                (connect
                 (append-to-all (first ys) (perms (remove xs (first ys))))
                 acc))
               ))]
        (filter (lambda (y) (not (empty? y))) (perms-it xs '(()))))))