variables A B C P Q R: Prop.
-- 
lemma teste 
      (H : A ∧ B → C) :
      A → B → C := 
  assume HA : A,
  assume HB : B, 
  show C, from (H (and.intro HA HB)).

lemma duvida (H1 : P)
             (H2 : P -> (P -> Q)) : Q
    := H2 H1 H1.         
