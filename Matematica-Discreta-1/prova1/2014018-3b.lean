--Robson Novato Lobão // 20.1.4018
variable U: Type.

variables H F G: U → Prop.

lemma ex3b (H1: ∃ x, F x ∨ G x) 
            (H2: ∀ x, F x → H x) 
             (H3: ∀ x, G x → H x) :  ∃ x, H x :=
    assume z, 
        have H4: F z ∨ G z, exists.elim H1 (assume a (Hn : F a ∨ G a), Hn),
        have H5: F z → H z, from H2 z,
        have H6 : G z → H z, from H3 z,
        show H z, 
        from (or.elim H4
                (assume H7: F z,
                    show H z,
                    from H5 H7)

                (assume H8: G z,
                    show H z,
                    from H8)).