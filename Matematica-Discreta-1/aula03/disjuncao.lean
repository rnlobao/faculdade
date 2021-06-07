-- exemplos envolvendo disjunção.

variables A B C : Prop.

lemma ex1 (H : A ∧ B) : A ∨ B := 
  (or.intro_left B (and.elim_left H)).

lemma ex2 (H : A ∧ B) : A ∨ B :=
  (or.intro_right A (and.elim_right H)).

lemma ex3 (H1 : A ∨ B)
          (H2 : A → C)
          (H3 : B → C) : C :=
  (or.elim H1 
           (assume H : A, 
            show C, from (H2 H))
           (assume H : B, 
            show C, from (H3 H))).

lemma ex4 (H : (A ∧ B) ∨ (A ∧ C)) : B ∨ C := 
  (or.elim 
      H
      (assume H1 : A ∧ B, 
       show B ∨ C, 
       from (or.intro_left C 
                           (and.elim_right H1)))
      (assume H1 : A ∧ C, 
       show B ∨ C, 
       from (or.intro_right B 
                            (and.elim_right H1)))).
