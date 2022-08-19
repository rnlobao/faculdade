Trabalho com o intuito de distribuir um banco de dados entre diversas máquinas a fim de dar suporte e aprender conceitos de distribuiçao de sistemas.

Criamos um banco de dados em PostgreSQL e através de uma extensao chamada Citus pudemos distribuir entre 4 VM's o conteúdo do banco.
Uma das vm's é o coordinator que organiza os Nodes Workers e distribui o conteúdo.

Conectando nessa VM coordinator através da biblioteca psycopg2 do Python podemos trabalhar de forma remota em um banco que está armazendo em uma Vm
do Google Cloud.

Algumas funcionalidades permitidas pelo nosso programa foi a de consultar e cadastrar usuários:

<p align = "center">
  <img width="400" height="400" src="Faculdade/Banco de Dados Distribuído/Captura de Tela 2022-08-19 às 14.24.19.png">
 <\p>

Faculdade/Banco de Dados Distribuído/Captura de Tela 2022-08-19 às 14.24.19.png
