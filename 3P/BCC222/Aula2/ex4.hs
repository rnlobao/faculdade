vetor :: Float -> Float -> (Float, Float)
vetor x y = (x / termo x y, y / termo x y)

termo :: Float -> Float -> Float 
termo x y = sqrt ((x*x) + (y*y))