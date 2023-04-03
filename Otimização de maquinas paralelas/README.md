<h1> Otimizaçao de Máquinas Paralelas Nao Identicas </h1>
O conceito de otimizacao abordado na disciplina BCC342 - Introduçao a Otimizacao, é de basicamente, dado um problema buscamos a melhor solucao
viavel, dado um conjunto de restricoes, as variaveis envolvidas no problema e o objetivo final do problema, que normalmente gira em torno de 
minimizar ou maximizar uma operacao, por exemplo, quando precisamos enviar varios caminhoes para diversas localidades buscamos minimizar a quantidade
de quilometros andados por cada caminhao. <br><br>
Tendo isso em vista, o trabalho da disciplina proposto foi otimizar um problema do mundo real, de acordo com algum artigo conceituado,
o artigo utilizado foi o "An iterated local search procedure for the job sequencing and tool switching problem with non-identical parallel machines"
da autora Dorothea Calmels em que, dada uma linha de producao, onde há varias maquinas com tempo de producao diferente e paralelamente dispostas nos
queremos minimizar a quantidade de trocas de ferramentas (tendo em vista que algumas ferramentas sao utilizadas em maquinas diferentes) entre essas maquinas <br><br>


<p align="center">
  <img width="400" alt="linhaProducao" src="https://user-images.githubusercontent.com/66230142/229389845-c49e80e4-8479-4045-84aa-6344b4a23946.png">
  <img width="300" alt="linhaProducao" src="https://user-images.githubusercontent.com/66230142/229390544-cf98f4f9-e948-4db5-bb3d-43621f1ef6df.gif">
</p>

O codigo foi disposto obedecendo as variaveis e parametros fornecidos no artigo e um conjunto de restricoes, como por exemplo, sempre deve haver uma 
maquina antes da outra, ou entao uma maquina so pode processar uma tarefa de cada vez, ou uma maquina so pode realizar uma tarefa caso todas ferramentas necessarias estejam dispostas, esse conjunto de restricoes pode ser obtido nessa parte do artigo:

<p align="center">
  <img width="300" alt="image" src="https://user-images.githubusercontent.com/66230142/229390981-a8fd9f93-fe99-451b-a4e0-7a23a1e068ba.png">
</p>

Em conclusao, utilizando o metodo exato do Gusek, O GUSEK (GLPK Under Scite Extended Kit) que é um aplicativo que traz uma interface para o usuário programar a modelagem, bem como a inserção de dados para o modelo resolver problemas de programacao linear. Obtivemos com uma entrada de instancias o numero minimo de 3 trocas de ferramentas, averiguadas pelo projeto de iniciacao cientifica de Pedro Lucas (que pode ser encontrado em: https://github.com/pedroldm/ic_ssp_npm ). Ou seja, com 2 maquinas, 9 tarefas e 8 ferramentas, o numero minimo de trocas entre elas é 3.




