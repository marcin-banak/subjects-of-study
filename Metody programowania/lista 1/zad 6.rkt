#lang racket
(define (if warunek iftrue iffalse)
  (or(and warunek iftrue) iffalse))