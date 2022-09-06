module ParseLib ( Parser
                , runParser
                , symbol
                , token
                , sat
                , digitChar
                , digit
                , succeed
                , failure
                , (<|>)
                , option
                , many
                , many1
                , choice
                , natural
                , first
                , greedy
                , greedy1
                , identifier
                , whitespace
                , listOf
                , pack
                , endBy
                , chainl
                , chainr
                )where

import Data.Char

-- parser type definition

newtype Parser s a
  = Parser {runParser :: [s] -> [(a,[s])]}

-- [s] -> [(a, [s])]
-- [] => nenhum resultado => erro
-- [(x, s)] => Ok
-- (_ : _ : _) => não determinismo.

-- basic parsers

symbol :: Eq s => s -> Parser s s
symbol s
  = Parser (\ inp -> case inp of
                       [] -> []
                       (x : xs) -> if x == s
                                   then [(x,xs)]
                                   else [])

token :: Eq s => [s] -> Parser s [s]
token s
  = Parser (\ inp -> if s == (take n inp)
                     then [(s, drop n inp)]
                     else [])
    where
      n = length s


sat :: (s -> Bool) -> Parser s s
sat p = Parser (\ inp -> case inp of
                           [] -> []
                           (x : xs) -> if p x
                                       then [(x,xs)]
                                       else [])

digitChar :: Parser Char Char
digitChar = sat isDigit


instance Functor (Parser s) where
   fmap f (Parser p)
      = Parser (\ inp -> [(f x, xs) | (x,xs) <- p inp])


digit :: Parser Char Int
digit = f <$> digitChar
        where
          f c = ord c - ord '0'

-- processing the empty string

succeed :: a -> Parser s a
succeed v = Parser (\ inp -> [(v,inp)])

-- defining a parser that always fails

failure :: Parser s a
failure = Parser (\ _ -> [])


-- combinators: choice between two parsers

infixr 4 <|>

(<|>) :: Parser s a -> Parser s a -> Parser s a
(Parser p) <|> (Parser q)
   = Parser (\ inp -> p inp ++ q inp)

-- combinators: sequential execution of parsers

instance Applicative (Parser s) where
   pure = succeed
   (Parser p) <*> (Parser q)
     = Parser (\ inp -> [(f x, xs) | (f, ys) <- p inp
                                   , (x, xs) <- q ys])

-- combinators: optionally executing a parsing

option :: Parser s a -> a -> Parser s a
option p d = p <|> succeed d


-- generalized choice

choice :: [Parser s a] -> Parser s a
choice = foldr (<|>) failure

-- combinators: running a parser many times

many :: Parser s a -> Parser s [a]
many p = ((:) <$> p <*> many p) <|> succeed []

many1 :: Parser s a -> Parser s [a]
many1 p = (:) <$> p <*> many p

-- combinators: parsing natural numbers

natural :: Parser Char Int
natural = foldl f 0 <$> greedy1 digit
     where
       f ac d = ac * 10 + d

-- combinators: greedy repetition

first :: Parser s a -> Parser s a
first (Parser p)
   = Parser (\ inp -> let r = p inp
                      in if null r then []
                         else [head r])
greedy :: Parser s a -> Parser s [a]
greedy = first . many

greedy1 :: Parser s a -> Parser s [a]
greedy1 = first . many1

-- parsing identifiers

identifier :: Parser Char String
identifier = (:) <$> letter <*> greedy (sat isAlphaNum)
  where
    letter = sat isLetter

-- discarding white space

whitespace :: Parser Char ()
whitespace = const () <$> greedy (sat isSpace)

-- separators

listOf :: Parser s a -> Parser s b -> Parser s [a]
listOf p sep
   = (:) <$> p <*> many ((\ _ y -> y) <$> sep <*> p)

pack :: Parser s a -> Parser s b ->
        Parser s c -> Parser s b
pack p q r = (\ _ x _ -> x) <$> p <*> q <*> r


endBy :: Parser s a -> Parser s b -> Parser s [a]
endBy p sep = greedy ((\ x _ -> x) <$> p <*> sep)

-- separators with semantics

chainr :: Parser s a ->             -- expressão
          Parser s (a -> a -> a) -> -- operador
          Parser s a
chainr pe po
   = h <$> many (j <$> pe <*> po) <*> pe
     where
       j x op = op x
       h fs x = foldr ($) x fs

chainl :: Parser s a ->             -- expressão
          Parser s (a -> a -> a) -> -- operador
          Parser s a
chainl pe po
   = h <$> pe <*> many (j <$> po <*> pe)
     where
       j op x = \ y -> op y x
       h x fs = foldl (flip ($)) x fs
