Avaliação empírica de 3 algoritmos para a Ordenação das chaves de um vetor.
Dado um vetor com n valores inteiros como entrada, os algoritmos devem retornar um
vetor com os valores do vetor de entrada, porém o valor de cada posição i deve ser menor
ou igual ao da posição i+1, com 1≤𝑖 < 𝑛.
Os 3 algoritmos a serem avaliados são o MergeSort, SelectionSort e RadixSort.

Inicialmente, deve-se fazer a análise de complexidade de cada algoritmo, mostrando
como se obteve a ordem de complexidade informada.
Depois, cada grupo deverá implementar e avaliar o tempo de execução de cada algoritmo
com as mesmas instâncias de entrada, ou seja, para cada tamanho n de instância:

1) Devem ser geradas 20 instâncias, cujos valores (chaves) devem ser preenchidos
aleatoriamente com valores entre 1 e n.
2) Para uma mesma instância (vetor), deve-se executar cada algoritmo de ordenação e
medir o tempo de execução.
3) Fazer o teste estatístico t pareado com 95% de confiança e verificar se houve empate
estatístico ou informar qual obteve estatisticamente o melhor desempenho.

Deve-se também apresentar um gráfico e analisá-lo, mostrando o tempo médio com
intervalo de confiança para a execução de cada algoritmo, considerando os tamanhos de
instâncias avaliados.

Comece com n=100 e vá aumentando-o em potência de 10. Ou seja, use n=100, 1.000,
10.000, 100.000, 1.000.000, ...

Entrega: Cada grupo deverá entregar um documento/relatório. O texto desse documento
deve conter, pelo menos, título, autores (alunos), resumo, introdução (descrever o
problema, o objetivo do trabalho, resumidamente os resultados obtidos e a organização do
trabalho), descrição dos métodos com suas análises de complexidades, avaliação
experimental (descrever a configuração dos experimentos (máquina, S.O., linguagem,
compilador, geração das instâncias,...), métrica de avaliação, resultados e
comentários/análises), conclusão e referências bibliográficas.

Apresentação: Cada grupo terá de 10 a 15 minutos para apresentar o trabalho à turma.
