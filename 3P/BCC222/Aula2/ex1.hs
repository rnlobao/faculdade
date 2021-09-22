achadivisiveis :: Int -> [Int]
achadivisiveis n = [x | x <- [1..n-1], mod n x == 0]

ehPerfeito :: Int -> Bool 
ehPerfeito n 
    |sum(achadivisiveis n) == n = True 
    |otherwise = False 

listaDePerfeitos :: Int -> [Int]
listaDePerfeitos n = [x | x <- [1 .. n], ehPerfeito x]


