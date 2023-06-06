#lang plait

(module+ test
  (print-only-errors #t))

;; abstract syntax -------------------------------

(define-type Op
  (add)
  (sub)
  (mul)
  (div))

(define-type Exp
  (numE [n : Number])
  (opE [op : Op]
       [l : Exp]
       [r : Exp]))

;; parse ----------------------------------------

(define (parse [s : S-Exp]) : Exp
  (cond
    [(s-exp-match? `NUMBER s)
     (numE (s-exp->number s))]
    [(s-exp-match? `{SYMBOL ANY ANY} s)
     (opE (parse-op (s-exp->symbol (first (s-exp->list s))))
          (parse (second (s-exp->list s)))
          (parse (third (s-exp->list s))))]
    [else (error 'parse "invalid input")]))

(define (parse-op [op : Symbol]) : Op
  (cond
    [(eq? op '+) (add)]
    [(eq? op '-) (sub)]
    [(eq? op '*) (mul)]
    [(eq? op '/) (div)]
    [else (error 'parse "unknown operator")]))
                 
(module+ test
  (test (parse `2)
        (numE 2))
  (test (parse `{+ 2 1})
        (opE (add) (numE 2) (numE 1)))
  (test (parse `{* 3 4})
        (opE (mul) (numE 3) (numE 4)))
  (test (parse `{+ {* 3 4} 8})
        (opE (add)
             (opE (mul) (numE 3) (numE 4))
             (numE 8)))
  (test/exn (parse `{{+ 1 2}})
            "invalid input")
  (test/exn (parse `{+ 1})
            "invalid input")
  (test/exn (parse `{^ 1 2})
            "unknown operator"))
  
;; eval --------------------------------------

(define-type-alias Value Number)

(define (op->proc [op : Op]) : (Value Value -> Value)
  (type-case Op op
    [(add) +]
    [(sub) -]
    [(mul) *]
    [(div) /]))

(define (eval [e : Exp]) : Value
  (type-case Exp e
    [(numE n) n]
    [(opE o l r) ((op->proc o) (eval l) (eval r))]))

(define (run [e : S-Exp]) : Value
  (eval (parse e)))

(module+ test
  (test (run `2)
        2)
  (test (run `{+ 2 1})
        3)
  (test (run `{* 2 1})
        2)
  (test (run `{+ {* 2 3} {+ 5 8}})
        19))

;; printer ———————————————————————————————————-

(define (print-value [v : Value]) : Void
  (display v))

(define (main [e : S-Exp]) : Void
  (print-value (eval (parse e))))

(define-type Instr
  (pushI [n : Value])
  (opI [op : Op]))
 
(define-type-alias Code (Listof Instr))

;; compiler

(define (compile [e : Exp]) : Code
  (type-case Exp e
    [(numE n)
     (list (pushI n))]
    [(opE op e1 e2)
     (append (compile e1)
             (append (compile e2)
                     (list (opI op))))]))

(define (update-stack stack exp)
  (cons exp (rest (rest stack))))

(define (parse-instr stack ins)
  (if (empty? ins)
      (first stack)
      (type-case Instr (first ins)
        [(pushI n) (parse-instr (cons (numE n) stack) (rest ins))]
        [(opI o) (parse-instr (update-stack stack (opE o (second stack) (first stack))) (rest ins))])))

(define (decompile ins)
  (parse-instr '() ins))

(module+ test
  (test (compile (parse `2))
        (list (pushI 2)))
  (test (compile (parse `{+ {* 2 3} {+ 5 8}}))
        (list (pushI 2) (pushI 3) (opI (mul)) (pushI 5) (pushI 8) (opI (add)) (opI (add)))))
