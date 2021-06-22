/-Robson Novato 20.1.4018-/
variable U: Type.
variables Q P A B C: U → Prop.


lemma ex1a (H : ∀ x, P x → Q x) : (∀ x, ¬Q x) → (∀ x, ¬P x) :=
  assume H1 : ∀ x, ¬ Q x,
  assume y,
  assume H2 : P y,
    have H3 : ¬ Q y, from H1 y,
    have H4 : P y → Q y, from H y,
    show false, from (H3(show Q y, from H4 H2)).

lemma ex1c (H : ∀ x, (A x → (B x ∨ C x)))
             (H1 : ¬ ∃ x, B x) : (∀ x, A x) → (∀ x, C x) :=
  assume H2 : ∀ x, A x,
    show ∀ x, C x, from (assume y,
      have H3 : A y, from H2 y,
      have H4 : A y → B y ∨ C y, from H y,
      have H5 : B y ∨ C y, from H4 H3,
      show C y,
        from (or.elim H5
          (assume H6 : B y,
          show C y, from false.elim (H1(exists.intro y H6)))
          (assume H7 : C y, H7))).


lemma ex1f (H : ∀ x, P x → Q x) : (∀ x, P x) → (∀ x, Q x) :=
  assume H1 : ∀  x, P x,
  assume A : U,
      have Hpq : P A → Q A, from H A,
      have Hpa : P A, from H1 A,
      show Q A, from Hpq Hpa.