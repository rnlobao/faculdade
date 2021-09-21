-- exemplos envolvendo reduction ad absurdum.

open classical.

variables A B : Prop.

lemma ex1 : ¬ (¬ A) → A := 
  (assume H : ¬ (¬ A), 
   show A, 
   from by_contradiction
        (assume Hn : ¬ A,
         show false, from (H Hn))).

-- esse é um exemplo mais complicado
-- e que só é possível de ser demonstrado
-- usando reduction ad absurdum

lemma hard (H : A → B) : ¬ A ∨ B := 
  (by_contradiction 
    (assume Hn : ¬ (¬ A ∨ B), 
     show false, 
     from (Hn (or.intro_left B 
                  (assume H1 : A, 
                   show false, 
                   from (Hn (or.intro_right (¬ A)
                                (H H1)))))))).
