---
author: Programação Funcional
title: Estudos de caso
date: Prof. Rodrigo Ribeiro
---

Setup
=====

\begin{code}
module Aula08 where

import Data.Char (chr, ord, isLower)

main :: IO ()
main = return ()
\end{code}

Objetivos
=========

- Utilizar o conteúdo visto até o momento
para solução de dois problemas:
criptografia e serialização


Cifra de César
=============

- Algoritmo simples para criptografia de textos

- Consiste em deslocar caracteres em $n$ posições.

- Exemplo: `encode 2 "abc" == "cde"`.

Cifra de César
==============

- Convertendo um caractere em inteiro.

\begin{code}
char2Int :: Char -> Int
char2Int c = ord c - ord 'a'

int2Char :: Int -> Char
int2Char n = chr (ord 'a' + n)
\end{code}


Cifra de César
==============

- Criptografando um caractere

\begin{code}
shift :: Int -> Char -> Char
shift n c
  | isLower c = int2Char ((char2Int c + n) `mod` 26)
  | otherwise = c
\end{code}

Cifra de César
==============

- Criptografando uma string

\begin{code}
encrypt :: Int -> String -> String
encrypt n s = map (shift n) s
\end{code}

Cifra de César
==============

- Descriptografando uma string

\begin{code}
decrypt :: Int -> String -> String
decrypt n s = encrypt (- n) s
\end{code}


Serialização
============

- Conversão de valores em sequências de bits.
- Como representar isso em Haskell?


Serialização
============

- Função `zip`.

~~~~{.haskell}
zip :: [a] -> [b] -> [(a,b)]
zip [] _ = []
zip _ [] = []
zip (x : xs) (y : ys) = (x,y) : zip xs ys
~~~~

Serialização
============

- Gerando uma lista infinita de valores.
     - Possível graças a _lazy evaluation_.

~~~~~{.haskell}
repeat :: a -> [a]
repeat x = x : repeat x

Prelude*> take 3 (repeat 2)
[2,2,2]
~~~~~~~


Serialização
============

- Função `iterate`.
      - Também faz uso de _lazy evaluation_.

~~~~{.haskell}
iterate :: (a -> a) -> a -> [a]
iterate f x = x : iterate (f x)
~~~~

Serialização
============

- Convertendo bits em números.

\begin{code}
type Bit = Int

bin2Int :: [Bit] -> Int
bin2Int bs = sum [w * b | (w,b) <- zip weights bs]
        where
          weights = iterate (* 2) 1
\end{code}

Serialização
============

- Convertendo números em bits.

\begin{code}
int2Bin :: Int -> [Bit]
int2Bin 0 = []
int2Bin n = n `mod` 2 : int2Bin (n `div` 2)
\end{code}

Serialização
============

- Gerando bytes

\begin{code}
make8 :: [Bit] -> [Bit]
make8 bs = take 8 (bs ++ repeat 0)
\end{code}

Serialização
============

- Dividindo em listas de bytes

\begin{code}
chop8 :: [Bit] -> [[Bit]]
chop8 [] = []
chop8 bs = take 8 bs : chop8 (drop 8 bs)
\end{code}

Serialização
============

- Codificando uma string

\begin{code}
encode :: String -> [Bit]
encode = concat . map (make8 . int2Bin . ord)
\end{code}

Serialização
============

- Decodificando uma string

\begin{code}
decode :: [Bit] -> String
decode = map (chr . bin2Int) . chop8
\end{code}

Exercício
=========

- Reimplemente a função `bin2Int` utilizando `foldr`.

- Um inconveniente da solução de serialização é a utilização
do tipo `Bit` como um sinônimo. Idealmente, deveríamos utilizar
um novo tipo, como se segue.

```haskell
data Bit = O | I deriving Show
```

Modifique a implementação da serialização para utilizar essa
versão do tipo `Bit`.

\begin{code}
bit2Int :: [Bit] -> Int
bit2Int = foldr (\x y -> x + 2 * y) 0

data Bin = O | I deriving Show

bin2Int' :: [Bin] -> Int
bin2Int bs = sum [w * b | (w,b) <- zipWith f weights bs]
    where
        weights = iterate (* 2) 1
        f p O = (p, 0)
        f p I = (p, 1)

int2Bin' :: Int -> [Bin]
int2Bin 0 = []
int2Bin n = calBit : int2Bin (n `div` 2)
    where
        calBit = if n `mod` 2 == 1 then I else O

make8' :: [Bin] -> [Bin]
make8 bs = take 8 (bs ++ repeat O)

chop8' :: [Bin] -> [[Bin]]
chop8 [] = []
chop8 bs = take 8 bs : chop8 (drop 8 bs)

encode' :: String -> [Bin]
encode = concatMap (make8 . int2Bin . ord)

decode' :: [Bin] -> String
decode = map (chr . bin2Int) . chop8
\end{code}