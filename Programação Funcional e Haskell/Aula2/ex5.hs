import GHC.List (length)

jeito1 :: [a] -> Bool 
jeito1 [] = True
jeito1 [_] = True 
jeito1 [_, _] = True 
jeito1 _ = False 

jeito2 :: [a] -> Bool
jeito2 y = GHC.List.length y <= 2

