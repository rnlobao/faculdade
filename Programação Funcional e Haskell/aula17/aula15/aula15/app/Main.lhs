---
title: Estudo de caso - Parsing
author: Programação Funcional
date: Prof. Rodrigo Ribeiro
---

Setup
======

\begin{code}
import Data.Char

main :: IO ()
main = return ()
\end{code}


Parsing
=======

- Verificar se uma sequência de
entrada possui uma estrutura de
interesse

- Problema central em computação.


Objetivo
========

- Utilizar functores aplicativos
para projetar uma biblioteca de
parsing.


Parser?
=======

- Definindo um parser:

\begin{code}
newtype Parser s a
  = Parser {runParser :: [s] -> [(a,[s])]}
\end{code}

Parser
=====

- O tipo de um parser é uma função

~~~~{.haskell}
[s] -> [(a,[s])]
~~~~

- s : Tipo do símbolo de entrada. Normalmente, `Char`.
- a : Tipo do resultado produzido ao se processar a entrada `[s]`.

Parser
======

- O tipo `Parser` utiliza uma abordagem conhecida como
list of success
    - Falhas representadas como uma lista vazia de resultados.
    - Um resultado: determinismo.
    - Mais de um resultado: backtracking implícito (não determinismo).


Exemplo
=======

- Um parser para um símbolo.

\begin{code}
symbol :: Eq s => s -> Parser s s
symbol s
  = Parser (\ inp -> case inp of
                       [] -> []
                       (x : xs) -> if x == s
                                   then [(x,xs)]
                                   else [])
\end{code}


Parser simples
=============

- Processando o caractere 'a':

\begin{code}
a :: Parser Char Char
a = symbol 'a'
\end{code}

- Executando no interpretador

~~~~{.haskell}
Main*> runParser a "a"
[('a',"")]
~~~~~~


Strings
=======

- Processando uma sequência de símbolos

\begin{code}
token :: Eq s => [s] -> Parser s [s]
token s
  = Parser (\ inp -> if s == (take n inp)
                     then [(s, drop n inp)]
                     else [])
    where
      n = length s
\end{code}


SAT
===

- O parser sat processa um símbolo que atende uma
certa condição.

\begin{code}
sat :: (s -> Bool) -> Parser s s
sat p = Parser (\ inp -> case inp of
                           [] -> []
                           (x : xs) -> if p x
                                       then [(x,xs)]
                                       else [])
\end{code}

Digit Parser
============

- Podemos usar sat para construir um parser para
processar um dígito da entrada.

\begin{code}
digitChar :: Parser Char Char
digitChar = sat isDigit
\end{code}


Digit Parser
===========

- Como converter o carater em seu dígito correspondente?
- Para isso, precisamos aplicar uma
função sobre o resultado de um parser.
- Isto é, fazer o tipo `Parser s a` uma instância de `Functor`.


Functor
======

\begin{code}
instance Functor (Parser s) where
   fmap f (Parser p)
      = Parser (\ inp -> [(f x, xs) | (x,xs) <- p inp])
\end{code}


Digit Parser
===========

- Usando functor, podemos converter o caractere
em dígito facilmente.

\begin{code}
digit :: Parser Char Int
digit = f <$> digitChar
        where
          f c = ord c - ord '0'
\end{code}

Outros Parsers
==============

- `succeed` é um parser que nunca falha.

- `failure` é um parser que sempre falha.

\begin{code}
succeed :: a -> Parser s a
succeed v = Parser (\ inp -> [(v,inp)])

failure :: Parser s a
failure = Parser (\ _ -> [])
\end{code}

Combinadores
============

- Escolha entre dois parsers:

\begin{code}
infixr 4 <|>

(<|>) :: Parser s a -> Parser s a -> Parser s a
(Parser p) <|> (Parser q)
   = Parser (\ inp -> p inp ++ q inp)
\end{code}


Combinadores
============

- Execução sequencial: Modelamos esse fato usando
`<*>`.

\begin{code}
instance Applicative (Parser s) where
   pure = succeed
   (Parser p) <*> (Parser q)
     = Parser (\ inp -> [(f x, xs) | (f, ys) <- p inp
                                   , (x, xs) <- q ys])
\end{code}


Exemplo
=======

- Reconhecendo "ab" ou "ba"

\begin{code}
ex1 :: Parser Char String
ex1 = token "ab" <|> token "ba"
\end{code}


Exemplo
=======

- Reconhecendo parêntesis balanceados. Strings pertencentes a
gramática:

$$
\begin{array}{lcl}
S & \to & (S)\,S\:\mid\epsilon
\end{array}
$$

Modelando
=========

- Usaremos um tipo de dados para representar palavras de
parêntesis balanceados

\begin{code}
data Paren = Match Paren Paren | Empty

instance Show Paren where
   show Empty = ""
   show (Match p p') = "(" ++ show p ++ ")" ++ show p'
\end{code}

Parser para Paren
==============

\begin{code}
open :: Parser Char Char
open = symbol '('

close :: Parser Char Char
close = symbol ')'

parens :: Parser Char Paren
parens = (f <$> open <*> parens <*> close <*> parens)
         <|> succeed Empty
         where
           f _ p _ p' = Match p p'
\end{code}

Exercício
=========

- Implemente um parser que calcula o número de pares de
parêntesis balanceados em uma string de entrada.

~~~~{.haskell}
pairs :: Parser Char Int
~~~~~

\begin{code}
--pairs :: Parser Char Int
--pairs = do{ char '(' ; n <- pairs ; char ')' ; m <- pairs ; return ((n+m)/2)}
--          <|> succeed 0     
-- Não consegui entender
\end{code}

Mais combinadores
================

- O parser `option p d` reconhece a entrada aceita por `p`
ou retorna o valor padrão `d`.

\begin{code}
option :: Parser s a -> a -> Parser s a
option p d = p <|> succeed d
\end{code}

Mais combinadores
=================

- Repetindo a execução de um parser.

\begin{code}
many :: Parser s a -> Parser s [a]
many p = ((:) <$> p <*> many p) <|> succeed []

many1 :: Parser s a -> Parser s [a]
many1 p = (:) <$> p <*> many p
\end{code}

Natural
=======

\begin{code}
natural :: Parser Char Int
natural = foldl f 0 <$> many digit
     where
       f ac d = ac * 10 + d
\end{code}

Combinadores
============

- Descartando resultados intermediários.

\begin{code}
first :: Parser s a -> Parser s a
first (Parser p)
   = Parser (\ inp -> let r = p inp
                      in if null r then []
                         else [head r])
\end{code}

Combinadores
============

\begin{code}
greedy :: Parser s a -> Parser s [a]
greedy = first . many

greedy1 :: Parser s a -> Parser s [a]
greedy1 = first . many1
\end{code}


Identificadores
===============

\begin{code}
identifier :: Parser Char String
identifier
   = (:) <$> letter <*> greedy (sat isAlphaNum)
     where
       letter = sat isLetter
\end{code}

Separadores
===========

- Parser `listOf p sep` processa elementos usando `p`
usando como separador `sep`.

\begin{code}
listOf :: Parser s a -> Parser s b -> Parser s [a]
listOf p sep
   = (:) <$> p <*> many ((\ x y -> y) <$> sep <*> p)
\end{code}


Separadores
===========

- Parser `pack p q r` processa o parser `q` usando os separadores
`p` e `r`, descartando-os.

\begin{code}
pack :: Parser s a -> Parser s b ->
        Parser s c -> Parser s b
pack p q r = (\ _ x _ -> x) <$> p <*> q <*> r
\end{code}

Exemplo
=======

- Processando conteúdo entre parêntesis.

\begin{code}
parenthesized :: Parser Char a -> Parser Char a
parenthesized p = pack (symbol '(') p (symbol ')')
\end{code}


Separadores
===========

- O parser `endBy p q` processa listas de elementos
reconhecidos por `p` usando como separadores o que
é processado por `q`.

\begin{code}
endBy :: Parser s a -> Parser s b -> Parser s [a]
endBy p sep = greedy ((\ x _ -> x) <$> p <*> sep)
\end{code}

Exemplo
=======

- Processando arquivos CSV

- Arquivos CSV: representação textual de dados
em tabelas (planilhas)
    - Dados representados como strings.
    - Separadores para dividir colunas.
    - Linhas no arquivo denotam linhas na tabela.


Modelagem
=========

- Tipos para representar dados CSV.

\begin{code}
type CSV = [Line]
type Line = [Cell]
type Cell = String
\end{code}

Células
=======

- Qualquer string sem `\n` e `,`.

\begin{code}
cellParser :: Parser Char Cell
cellParser = greedy valid
    where
       valid = sat (\ c -> notElem c ",\n")
\end{code}

Linhas
======

- Usaremos o parser `listOf`, seperando colunas

\begin{code}
lineParser :: Parser Char Line
lineParser = listOf cellParser (symbol ',')
\end{code}

CSV
===

\begin{code}
csvParser :: Parser Char CSV
csvParser = endBy lineParser eol
   where
     eol = symbol '\n'
\end{code}


Exemplo
=======

\begin{code}
parseCSV :: FilePath -> IO ()
parseCSV file
   = do
       content <- readFile file
       print (runParser csvParser content)
\end{code}


Separadores
===========

- No que vimos, separadores não possuem significado.

- Mas, seperadores podem possuir significado?
    - Sim! Expressões com operadores binários.


Chainr
======

- Operador associativo a direita

\begin{code}
chainr :: Parser s a ->             -- expressão
          Parser s (a -> a -> a) -> -- operador
          Parser s a
chainr pe po
   = h <$> many (j <$> pe <*> po) <*> pe
     where
       j x op = op x
       h fs x = foldr ($) x fs
\end{code}

Chainl
======

- Operador associativo a esquerda

\begin{code}
chainl :: Parser s a ->             -- expressão
          Parser s (a -> a -> a) -> -- operador
          Parser s a
chainl pe po
   = h <$> pe <*> many (j <$> po <*> pe)
     where
       j op x = \ y -> op y x
       h x fs = foldl (flip ($)) x fs
\end{code}

Exemplo
=======

- Processando expressões.
- Sintaxe de expressões:

$$
\begin{array}{lcl}
e & \to  & t + e \\
  & \mid & t \\
t & \to & f * t \\
  & \mid & f \\
f & \to & n \\
  & \mid & (e)\\
\end{array}
$$

Sintaxe
=======

- Tipo de dados para representar a árvore de sintaxe
de expressões.

\begin{code}
data Exp
   = Const Int
   | Exp :+: Exp
   | Exp :*: Exp
   | Exp :-: Exp
   deriving (Eq, Ord, Show)
\end{code}

Parser
======

- Regras $f \to n \mid (e)$:

\begin{code}
factorParser :: Parser Char Exp
factorParser
   =  parenthesized (expParser) <|>
      (Const <$> natural)
\end{code}

Parser
======

- Regras $t \to f + t \mid t$:

\begin{code}
termParser :: Parser Char Exp
termParser
   = chainr factorParser pmult
     where
       pmult = const (:*:) <$> symbol '*'
\end{code}


Parser
======

- Regras $e \to t * e \mid t$:

\begin{code}
expParser :: Parser Char Exp
expParser
  = chainr termParser pplus
    where
      pplus = const (:+:) <$> symbol '+'
\end{code}


Exercício
=========

- Implemente um parser para strings da forma:

$$
(id_1, ... , id_n)
$$

em que cada $id_i$ é um identificador. Note que a lista
de identificadores usa como separador o caractere ','.

\begin{code}
--identParser :: Parser String
--Não entendi
\end{code}

Exercício
=========

- Modifique o tipo de dados `Exp` para incluir
a operação de subtração. Altere o parser de forma
a reconhecer expressões evolvendo subtração.

\begin{code}
--Mudei Exp

subParser :: Parser Char Exp
subParser
  = chainr termParser psub
    where
      psub = const (:-:) <$> symbol '-'
\end{code}

Exercício
=========

- O parser de expressões utiliza a função `natural`
que reconhece um número natural qualquer. Implemente um
parser `integer :: Parser Char Int` que seja capaz de
reconhecer números negativos. _Dica_: Use o combinador
`option`.

\begin{code}
{--
integer :: Parser Char Int
integer = do{Char '-';
            n <- natural;
            return (-n)}
          <|> natural
--}
\end{code}