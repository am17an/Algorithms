(define (q-sort l)
  (cond ((null? l) (quote()))
        (else 
         (append (q-sort (filter (lambda (x) (< x (car l))) l))
             (list (car l)) (q-sort (filter (lambda (x) (> x (car l))) l))))))

(q-sort (list 3 4 1 5 7 8 6 10 2))

