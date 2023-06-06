#lang plait

(define-type (NNF 'v)
  (nnf-lit [polarity : Boolean] [var : 'v])
  (nnf-conj [l : (NNF 'v)] [r : (NNF 'v)])
  (nnf-disj [l : (NNF 'v)] [r : (NNF 'v)]))

(define-type (Formula 'v)
  (var [var : 'v ])
  (neg [f : (Formula 'v) ])
  (conj [l : (Formula 'v)] [r : (Formula 'v)])
  (disj [l : (Formula 'v)] [r : (Formula 'v)]))

(define (<=> f1 f2)
  (or (and f1 f2) (and (not f1) (not f2))))

(define (eval-nnf sig fi)
  (cond [(nnf-lit? fi)
         (<=> (sig (nnf-lit-var fi)) (nnf-lit-polarity fi))]
        [(nnf-conj? fi) (and (eval-nnf sig (nnf-conj-l fi)) (eval-nnf sig (nnf-conj-r fi)))]
        [(nnf-disj? fi) (or (eval-nnf sig (nnf-disj-l fi)) (eval-nnf sig (nnf-disj-r fi)))]))

(define (neg-nnf v)
  (cond [(nnf-lit? v) (nnf-lit (not (nnf-lit-polarity v)) (nnf-lit-var v))]
        [(nnf-conj? v) (nnf-disj (neg-nnf (nnf-conj-l v)) (neg-nnf (nnf-conj-r v)))]
        [(nnf-disj? v) (nnf-conj (neg-nnf (nnf-disj-l v)) (neg-nnf (nnf-disj-r v)))]))

(define (to-nnf formula)
  (cond
    [(var? formula) (nnf-lit #t (var-var formula))]  
    [(conj? formula) (nnf-conj (to-nnf (conj-l formula)) (to-nnf (conj-r formula)))]
    [(disj? formula) (nnf-disj (to-nnf (disj-l formula)) (to-nnf (disj-r formula)))]
    [(neg? formula)
     (let ((f (neg-f formula)))
       (cond
         [(var? f) (nnf-lit #f (var-var f))]
         [(neg? f) (to-nnf (neg-f f))]
         [(conj? f) (nnf-disj (neg-nnf (to-nnf (conj-l f))) (neg-nnf (to-nnf (conj-r f))))]
         [(disj? f) (nnf-conj (neg-nnf (to-nnf (disj-l f))) (neg-nnf (to-nnf (disj-r f))))]))]))

(define (eval-formula sig formula)
  (cond
    [(var?  formula) (sig (var-var formula))]
    [(conj? formula) (and (eval-formula sig (conj-l formula)) (eval-formula sig (conj-r formula)))]
    [(disj? formula) (or (eval-formula sig (disj-l formula)) (eval-formula sig (disj-r formula)))]
    [(neg? formula) (not (eval-formula sig (neg-f formula)))]))