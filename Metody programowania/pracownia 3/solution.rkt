#lang plait

(define-type-alias Value Number)

(define (run [s : S-Exp]) : Value
  (valD-val (eval (parse s) mt-env)))

; -------- Składnia abstrakcyjna --------

(define-type Op
  (add) (sub) (mul) (leq))

(define-type Exp
  (numE [n : Number])
  (varE [x : Symbol])
  (opE [op : Op] [l : Exp] [r : Exp])
  (ifE [b : Exp] [l : Exp] [r : Exp])
  (letE [x : Symbol] [e1 : Exp] [e2 : Exp])
  (funE [xs : (Listof Symbol)] [e : Exp])
  (appE [name : Symbol] [es : (Listof Exp)])
  (defE [fs : (Listof (Symbol * Exp))] [e : Exp]))

; -------- Parser --------

; Funkcja, która sparsuje główne wyrażenie, jeżeli zostało ono poprawnie wpisane przez użytkownika.
(define (parse [s : S-Exp]) : Exp
  (if (valid-inp? s) (parse-def s)
      (error 'parse "invalid input")))

; Funckja parsująca wyrażenie typu S-Exp na Exp
(define (parse-exp [s : S-Exp]) : Exp
  (cond
    [(s-exp-match? `NUMBER s)
     (numE (s-exp->number s))]
    [(s-exp-match? `{ANY SYMBOL ANY} s)
     (opE (parse-op (s-exp->symbol (second (s-exp->list s))))
          (parse-exp (first (s-exp->list s)))
          (parse-exp (third (s-exp->list s))))]
    [(s-exp-match? `{ifz ANY then ANY else ANY} s)
     (ifE (parse-exp (second (s-exp->list s)))
          (parse-exp (fourth (s-exp->list s)))
          (parse-exp (fourth (rest (rest (s-exp->list s))))))]
    [(s-exp-match? `{let SYMBOL be ANY in ANY} s)
     (letE (s-exp->symbol (second (s-exp->list s)))
           (parse-exp (fourth (s-exp->list s)))
           (parse-exp (fourth (rest (rest (s-exp->list s))))))]
    [(s-exp-match? `{SYMBOL (ANY ...)} s)
     (appE (s-exp->symbol (first (s-exp->list s)))
           (map parse-exp (s-exp->list (second (s-exp->list s)))))]
    [(s-exp-match? `SYMBOL s)
     (varE (s-exp->symbol s))]
    [else (begin (display s) (error 'parse "invalid input"))]))

; Funkcja parsująca wyrażenie typu S-Exp na (Symbol * funE)
(define (parse-fun [s : S-Exp]) : (Symbol * Exp)
  (let ((func-exp
         (funE (map s-exp->symbol (s-exp->list (third (s-exp->list s))))
          (parse-exp (fourth (rest (s-exp->list s)))))))
    (if (free-var? func-exp)
        (error 'parse-fun "free variables")
        (pair (s-exp->symbol (second (s-exp->list s))) func-exp))))

; Funkcja parsująca wyrażenie typu S-Exp na defE
(define (parse-def [s : S-Exp]) : Exp
  (let ((funcs (map parse-fun (s-exp->list (second (s-exp->list s)))))
        (exp (parse-exp (fourth (s-exp->list s)))))
    (defE funcs exp)))

; Funkcja parsująca operator.
(define (parse-op [op : Symbol]) : Op
  (cond
    [(eq? op '+) (add)]
    [(eq? op '-) (sub)]
    [(eq? op '*) (mul)]
    [(eq? op '<=) (leq)]
    [else (error 'parse "unknown operator")]))

; Funkcja sprawdzająca, czy główne wyrażenie wpisane przez użytkownika jest poprawne.
(define (valid-inp? [s : S-Exp]) : Boolean
  (s-exp-match? `(define ((fun SYMBOL (SYMBOL ...) = ANY) ...) for ANY) s))

; Funkcja, która sprawdza, czy w ciele funkcji są jakieś zmienne wolne.
(define (free-var? [f : Exp]) : Boolean
  (let ([vs (funE-xs f)] [func-body (funE-e f)])
    (not (foldl (lambda (x a) (and a (member x vs))) #t (find-var func-body)))))

; Funkcja znajdująca wszystkie zmienne w wyrażeniu.
(define (find-var [e : Exp]) : (Listof Symbol)
  (type-case Exp e
    [(numE n) '()]
    [(opE op l r) (append (find-var l) (find-var r))]
    [(ifE b l r) (append (find-var b) (append (find-var l) (find-var r)))]
    [(varE x) (list x)]
    [(letE x e1 e2) (append (find-var e1) (remove-from-list (find-var e2) x))]
    [(appE name es) (foldr (lambda (e a) (append a (find-var e))) '() es)]
    [else (error 'find-var "invalid type")]))

; Funkcja usuwająca element z listy, jeżeli się w niej znajduje.
(define (remove-from-list [l : (Listof 'a)] [x : 'a]) : (Listof 'a)
  (cond
    [(empty? l) '()]
    [(equal? (first l) x) (rest l)]
    [else (cons (first l) (remove-from-list (rest l) x))]))

; -------- Środowisko --------

(define-type Data
  (valD [val : Value])
  (funD [xs : (Listof Symbol)] [e : Exp]))

(define-type Binding
  (bind [name : Symbol]
        [data : Data]))

(define-type-alias Env (Listof Binding))

(define mt-env empty)

(define (extend-env [env : Env] [x : Symbol] [d : Data]) : Env
  (cons (bind x d) env))

(define (extend-env-list [env : Env] [xs : (Listof (Symbol * Data))]) : Env
  (if (empty? xs) env
      (let ([p (first xs)])
        (extend-env-list (extend-env env (fst p) (snd p)) (rest xs))))) 
  
(define (lookup-env [n : Symbol] [env : Env]) : Data
  (type-case (Listof Binding) env
    [empty (error 'lookup "unbound variable")]
    [(cons b rst-env) (cond
                        [(eq? n (bind-name b)) (bind-data b)]
                        [else (lookup-env n rst-env)])]))

; -------- Ewaluator --------

; Funkcja obliczająca wartość wyrażenia typu Exp z wykorzystaniem środowiska Env.
(define (eval [e : Exp] [env : Env]) : Data
  (type-case Exp e
    [(numE n)
     (valD n)]
    [(opE op l r)
     (valD (eval-op op (valD-val (eval l env)) (valD-val (eval r env))))]
    [(ifE b l r) (if (= (valD-val (eval b env)) 0) (eval l env) (eval r env))]
    [(varE x) (lookup-env x env)]
    [(letE x e1 e2) (eval e2 (extend-env env x (eval e1 env)))]
    [(funE xs b) (funD xs b)]
    [(appE name es) (apply-func (lookup-env name env) es env)]
    [(defE fs e)
     (eval e (extend-env-list env (map (lambda (p) (pair (fst p) (eval (snd p) env))) fs)))]))

; Funkcja obliczająca wartość wyrażeń postaci (Op Value Value).
(define (eval-op [op : Op] [l : Value] [r : Value]) : Value
  (type-case Op op
    [(add) (+ l r)]
    [(sub) (- l r)]
    [(mul) (* l r)]
    [(leq) (if (<= l r) 0 1)]))

; Funkcja "składająca" dwie listy w listę par kolejnych elementów obu list.
(define (pair-lists l1 l2)
  (if (empty? l1) '()
      (cons (pair (first l1) (first l2)) (pair-lists (rest l1) (rest l2)))))

; Funkcja dostaje funkcję w postaci funD i wywołuje ewaluator dla jej ciała i środowisko rozszerzonego o wyliczone argumenty.
(define (apply-func [f : Data] [es : (Listof Exp)] [env : Env]) : Data
  (let ((names (funD-xs f)) (vals (map (lambda (e) (eval e env)) es)))
    (eval (funD-e f) (extend-env-list env (pair-lists names vals)))))


#; (run `{define
         {[fun fact (n) = {ifz n then 1 else {n * {fact ({n - 1})}}}]}
         for
         {fact (5)}})

#; (run `{define
        {[fun even (n) = {ifz n then 0 else {odd ({n - 1})}}]
         [fun odd (n) = {ifz n then 42 else {even ({n - 1})}}]}
        for
        {even (1024)}})

#; (run `{define
        {[fun gcd (m n) = {ifz n
                               then m
                               else {ifz {m <= n}
                                         then {gcd (m {n - m})}
                                         else {gcd ({m - n} n)}}}]}
        for
        {gcd (81 63)}})
