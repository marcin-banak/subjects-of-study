#lang racket

(define-struct leaf () #:transparent)
(define-struct node (l elem r) #:transparent)

(define (fold-tree f var xs)
  (if (leaf? xs)
      var
      (f (fold-tree f var (node-l xs)) (node-elem xs) (fold-tree f var (node-r xs)))))

(define (insert-bst x t)
  (cond [(leaf? t) (node (leaf) x (leaf))]
        [(node? t)
         (cond [(= x (node-elem t))
                (node (insert-bst x (node-l t))
                       (node-elem t)
                       (node-r t))]
                [(< x (node-elem t))
                 (node (insert-bst x (node-l t))
                       (node-elem t)
                       (node-r t))]
                [else
                 (node (node-l t)
                       (node-elem t)
                       (insert-bst x (node-r t)))])]))

(define (treesort xs)
  (fold-tree (lambda (l curr r) (append l (cons curr r))) '() (foldl (lambda (l res) (insert-bst l res)) (leaf) xs)))

(treesort '( 1 2 43 3 2 324 3 2 43 32 3 3 42))