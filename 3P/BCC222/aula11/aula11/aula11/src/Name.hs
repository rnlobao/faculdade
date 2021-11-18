module Name ( Name
            , mkName
            , render
            ) where

import Data.Char (toUpper, toLower)

-- definition of a name

data Name
  = MkName String
  deriving Eq

mkName :: String -> Name
mkName [] = MkName []
mkName (x : xs) = MkName (x' : xs')
  where
    x' = toUpper x
    xs' = map toLower xs

render :: Name -> String
render (MkName s) = s
