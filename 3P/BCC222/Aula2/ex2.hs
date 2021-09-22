primes :: Int -> Bool
primes 2 = True 
primes 3 = True
primes n 
    |even n = False 
    |mod n 3 == 0 = False 
    |otherwise = True 

primosIntervalo :: Int -> [Int]
primosIntervalo n = [x | x <- [1 .. n], primes x]