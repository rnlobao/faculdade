funcaosomaquadrado :: Int -> Int -> Int 
funcaosomaquadrado x y = (x*x) + (y*y)

funcaoachamaior :: Int -> Int -> Int -> Int 
funcaoachamaior n1 n2 n3 = do
    if n1 > n2                                          
        then if n2 > n3
            then funcaosomaquadrado n1 n2 
        else if n1 > n3 
            then funcaosomaquadrado n1 n3
        else funcaosomaquadrado n3 n1                                                
    else if n2 > n3                                       
        then if n1 > n3 
            then funcaosomaquadrado n2 n1
        else funcaosomaquadrado n2 n3       
    else funcaosomaquadrado n3 n2

