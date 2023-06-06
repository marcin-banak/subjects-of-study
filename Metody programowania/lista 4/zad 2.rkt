#lang racket

(define-struct leaf () #:transparent)
(define-struct node (l elem r) #:transparent)

(define t
  (node
   (node (leaf) 2 (leaf))
   5
   (node (node (leaf) 6 (leaf))
         8
         (node (leaf) 3 (leaf)))))


(define (fold-tree f var xs)
  (if (leaf? xs)
      var
      (f (fold-tree f var (node-l xs)) (node-elem xs) (fold-tree f var (node-r xs)))))


(define (tree-sum t)
  (fold-tree + 0 t))

(define (tree-flip t)
  (fold-tree (lambda (x y z) (node z y x)) (leaf) t))

(define (tree-height t)
  (fold-tree (lambda (l val r) (+ 1 (max l r))) 0 t))

(define (tree-span t)
  (fold-tree (lambda (l val r)
               (cons
                (if (leaf? (car l)) val (car l))
                (if (leaf? (cdr l)) val (cdr r))))
             (cons (leaf) (leaf)) t))

(define (flatten t)
  (fold-tree (lambda (l val r) (append l (cons val r))) '() t))
