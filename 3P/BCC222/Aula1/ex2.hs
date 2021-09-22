calcfibonacci :: Int -> Int 
calcfibonacci 0 = 0
calcfibonacci 1 = 1
calcfibonacci n = calcfibonacci (n - 1) + calcfibonacci (n - 2)