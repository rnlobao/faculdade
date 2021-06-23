--Robson Novato Lobão // 20.1.4018
variables A B C: Prop.

lemma ex3a (H1: A → B ∨ C) : ¬B → (A → C) :=

    assume H2: ¬B, 
    assume H3: A,
      have H4: B ∨ C, from H1 H3,
      show C,
      from (or.elim H4 
            (assume H5: B,
            show C, 
            from false.elim(H2 H5))
            (assume H6: C, H6)).