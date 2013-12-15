(define (merge l1 l2)
  (cond ( (null? l1) l2)
        ( (null? l2) l1)
        ( (if(< (car l1) (car l2)) 
          (cons (car l1) (merge (cdr l1) l2))
          (cons (car l2) (merge l1 (cdr l2)))))))
(define (length l)
  (if (null? l)
    0
    (+ 1 (length (cdr l)))))

(define (first-half l n)
  (if (>=  n (/ (length l) 2))
    (quote())
    (cons (car l) (first-half (cdr l) (+ n 1)))))

(define (second-half l n)
  (cond ( (< n (/ (length l) 2)) (second-half (cdr l) (+ n 1)))
        ( (null? l) (quote()))
        ( else ( cons (car l) (second-half (cdr l) (+ n 1))))))

(define (merge-sort l)
  (if (= 1 (length l)) 
    l
    (merge (merge-sort (first-half l 0)) (merge-sort (second-half l 0)))))

(merge-sort (list 3 2 1 4 5 7 9 12 14 18 23))
