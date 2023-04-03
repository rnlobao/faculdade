Documentaçao do principais aprendizados, conceitos e algoritmos da área de IA


<p align="center">
  <img src="https://user-images.githubusercontent.com/66230142/209479583-c78228de-e5d5-4635-8cfd-7acdeef87f4c.png" width="400">
</p>

A maioria das respostas de definicoes foram retiradas do livro:\
https://www.cin.ufpe.br/~gtsa/Periodo/PDF/4P/SI.pdf

>Em seu livro de 1651, Leviatã, Thomas Hobbes sugeriu a ideia de um “animal artificial”, argumentando: “Pois o que é o coração, senão uma mola; e os nervos, senão tantas cordas; e as articulações, senão tantas rodas.”


<details>
  <summary>O que é inteligencia artificial?</summary>
    Estudo de agentes que recebem percepções do ambiente e executam acoes
</details>

<details>
  <summary>O que sao agentes</summary>
    Alguma coisa que atua em um ambiente e recebe seus estímulos, ele possui um corpo com sensores e atuadores (recebem estímulos e fornecem ações respectivamente<br>
    <img width="343" alt="image" src="https://user-images.githubusercontent.com/66230142/209480390-2dff8040-3976-4da1-afcf-70106ffdaf0b.png">

</details>

<details>
  <summary>Classificacao de agentes</summary>
    Utilizamos o PEAS para classificar o agente, ex:
<img width="711" alt="image" src="https://user-images.githubusercontent.com/66230142/209480762-5f55a5a7-ca4f-4bfa-9a0b-5b7401b6c63f.png"><br>
(Performance, Environment, Actuators e Sensors)
</details>

<details>
  <summary>Classificacao de ambientes de tarefa</summary>
  As definicoes sao bem intuitivas, basicamente:

  Obervavel: Parcialmente ou completamente de acordo com se ele pode ser totalmente averiguado ou nao\
  Agentes: Quantidade de agentes envolvidos no ambiente, seja único ou multi\
  Determinístico: se for é porque de acordo com o passo x certamente y vai acontecer, estocático é classificado quando nao podemos afirmar com certeza\
  Episodico: se ele é episodico quer dizer que acoes passadas nao interferiram para oq ocorreu atualmente no ambiente enquanto os sequenciais sao causais, por exemplo uma partida de xadrez é sequencial, cada tomada de decisao influencia no que acontece na proxima rodada da partida.\
  Estatico: ambiente pode alterar? Sim? Entao é dinamico, caso contrário, estático.
  Discreto versus contínuo: normalmente diz respeito ao estado e ao tempo do ambiente, discreto quando é finito e continuo quando é infinito.
  <img width="710" alt="image" src="https://user-images.githubusercontent.com/66230142/209480964-64eef4fc-0219-454f-b044-bfd5bf5a21bb.png">

</details>

<details>
  <summary>Trabalho de busca em grafos</summary>
  <h2>Busca em grafos</h2>

  No primeiro trabalho da disciplina foi dado um código e deveriamos colocar 4 algoritmos de busca para encontrar o fim de um labirinto



  BFS | DFS | Best First | A*
  :---------: | :---------: | :---------: | :---------:
  <img width="200" alt="image" src="https://user-images.githubusercontent.com/66230142/213942254-5447c9d7-f245-45c8-8972-add9b90bc195.gif"> | <img width="200" alt="image" src="https://user-images.githubusercontent.com/66230142/213942437-7deb180e-8b6d-4966-b86d-cf6cdc105615.gif"> | <img width="200" alt="image" src="https://user-images.githubusercontent.com/66230142/213942532-9406362f-3251-416e-98c4-f7cf88f162fb.gif"> | <img width="200" alt="image" src="https://user-images.githubusercontent.com/66230142/213942636-2700bc28-ecfb-43f7-8e96-fa511197fad8.gif">
</details>

<details>
  <summary> Previsao de falencia de uma empresa </summary>
    Com um csv disponibilizado pelo professor, e com o intuito de avaliacao final da disciplina, foi feito o desafio de identificacao e previsao da falencia ou nao de 100 empresas usando 3 metodos diferentes de treinamento, sendo eles Regressao Logistica, Arvores de Decisao e Floresta Aleatoria.<br><br> Maiores detalhes podem ser encontrados nas explicacoes do video com Pedro Lucas, Guilherme Augusto, Rafael Augusto e Gabriel Catizani: https://www.youtube.com/watch?v=UL9gmVBZiIo
</details>







