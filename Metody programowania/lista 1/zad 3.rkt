#lang racket
(* (+ 2 2)      5) ; poprawne

; (* (+ 2 2) (5) ) znaki "()" oznaczają jakąś procedurę,
;                  którą program może wykonać, a (5) nią nie jest.

; (*(+(2 2) 5) ) to samo (2 2) to nie procedura

(*(+ 2
   2) 5) ; poprawne

; (5 * 4) zapisane w postaci infiksowej

; (5 * (2 + 2) ) to samo postać infiksowa

; ((+ 2 3) ) procedura przyjmująca tylko wartość 5.

+ ; poprawne

;(define + (* 2 3)) + ; poprawne

; (* 2 +) nie przekazujemy żadnych argumentów do procedury +

( define ( five ) 5) ; definiujemy nową procedurę.

( define four 4) ; poprawne

(five) ; poprawne
four ; poprawne
five ; poprawne
; (four) błędne wywołanie procedury