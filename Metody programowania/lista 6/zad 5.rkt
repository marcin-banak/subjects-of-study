#lang plait

(define-type (NNF 'v)
  (nnf-lit [polarity : Boolean] [var : 'v])
  (nnf-conj [l : (NNF 'v)] [r : (NNF 'v)])
  (nnf-disj [l : (NNF 'v)] [r : (NNF 'v)]))

(define (sigma fi)
  (cond [(equal? fi 'p) #t]
        [(equal? fi 'q) #f]
        [(equal? fi 'r) #f]
        [(equal? fi 's) #t]))

(define psi (nnf-conj (nnf-lit #t 'p) (nnf-lit #f 'q)))

(define (<=> f1 f2)
  (or (and f1 f2) (and (not f1) (not f2))))

(define (eval-nnf sig fi)
  (cond [(nnf-lit? fi)
         (<=> (sig (nnf-lit-var fi)) (nnf-lit-polarity fi))]
        [(nnf-conj? fi) (and (eval-nnf sig (nnf-conj-l fi)) (eval-nnf sig (nnf-conj-r fi)))]
        [(nnf-disj? fi) (or (eval-nnf sig (nnf-disj-l fi)) (eval-nnf sig (nnf-disj-r fi)))]))