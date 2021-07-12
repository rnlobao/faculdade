import data.set 
open set 

variable {U : Type}
variables A B C : set U 

variable F : set (set U)

theorem ex3
    : A ⊆ B → 𝒫(A) ⊆ 𝒫(B) :=
    assume A ⊆ B,
    assume X,
    assume (HX : X ∈ A),
    assume Y,
    assume (HY : Y ∈ A),
    have (Hf: Y ∈ 𝒫(A)),
        from exists.intro X (and.intro HA, HY),
    show Y ∈ B, from Hf