fn :: Int -> Int
fn n = go 0 1 n
  where
    go a b 0 = a
    go a b n = go b (a + b) (n - 1)