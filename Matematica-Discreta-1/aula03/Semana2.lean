/-Robson Novato 20.1.4018-/

variables A B P Q R S : Prop.

lemma umL (H1 : P → Q) (H2 :  R → S) : (P ∨ R) → (Q ∨ S) :=
          assume H3 : (P ∨ R),
          (or.elim H3
                   (assume H : P, show Q ∨ S,
                    from (or.intro_left S (H1 (show P, from (H)))))
                   (assume H : R, show Q ∨ S,
                    from (or.intro_right Q (H2 (show R, from (H)))))).


lemma umM (H1 : Q → R) : (P → Q) → (P → R) :=
          assume H2 : (P → Q),
          assume H3 : P,
          show R, from (H1 (show Q, from (H2 (show P, from (H3))))).


lemma doisA (H1 : ¬(A ∨ B)) : ¬A ∧ ¬B :=
          and.intro (assume H2 : A, (show false,
                    from (H1 (or.intro_left B H2))))
                    (assume H3 : B, show false,
                     from (H1(or.intro_right A H3))).
                    

lemma doisB (H1 : (¬A) ∧ (¬B)) : ¬ (A ∨ B) :=
     assume H2 : (A ∨ B),
     show false, 
     from ( (and.elim_left H1)
            (or.elim H2
                      (assume H3 : A, H3)
                      (assume H4 : B, false.elim (and.elim_right H1 H4)))).
