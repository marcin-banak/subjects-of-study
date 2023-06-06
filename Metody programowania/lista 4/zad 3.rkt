#lang racket

(define-struct leaf () #:transparent)
(define-struct node (l elem r) #:transparent)

(define (insert-bst x t)
  (cond [(leaf? t) (node (leaf) x (leaf))]
        [(node? t)
         (cond [(= x (node-elem t)) t]
                [(< x (node-elem t))
                 (node (insert-bst x (node-l t))
                       (node-elem t)
                       (node-r t))]
                [else
                 (node (node-l t)
                       (node-elem t)
                       (insert-bst x (node-r t)))])]))

(define bst1 (foldl (lambda (l res) (insert-bst l res)) (leaf) '(1 4 2 3 5 35 56 34)))
(define bst2 (foldl (lambda (l res) (insert-bst l res)) (leaf) '(35 56 34 11 4 2 3 5)))



(define (bst? t)
  (define (it t f acc)
    (if (leaf? t)
        #t
        (if (f acc (node-elem t))
            (and (it (node-l t) > (node-elem t))
                 (it (node-r t) < (node-elem t)))
            #f)))
  (it t = (node-elem t)))

(bst? bst1)
(bst? bst2)

(define (sum-paths t)
  (define (it t acc)
    (if (leaf? t)
        (leaf)
        (node (it (node-l t) (+ acc (node-elem t))) (+ acc (node-elem t)) (it (node-r t) (+ acc (node-elem t))))))
  (it t 0))

bst1
(sum-paths bst1)