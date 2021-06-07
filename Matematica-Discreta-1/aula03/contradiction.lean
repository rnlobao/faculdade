-- exemplos envolvendo contradição

variables A B : Prop. 

lemma ex1 (H1 : A ∨ B)
          (H2 : ¬ A) : B := 
  (or.elim H1 
           (assume H : A, 
            show B, from false.elim (H2 H))
           (assume H : B, H)).