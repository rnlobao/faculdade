//Robson Novato Lobao 20.1.4018
#include"Instructions.h"

struct memoria{
    int RAM[T];
    int memoriaInstrucoes[1000][4];
};

//Aqui a variavel ram é alocada e o campo dessa struct é preenchida com numero aleatorios
Memoria* montarMemoriaDados(void){
    Memoria* ram = malloc(sizeof(Memoria));
    //Auto - generated method sub
    for(int i=0; i<T; i++){
        ram->RAM[i]=rand()%1000;
    }
    return ram;
}

//Aqui o programa é montado de forma aleatoria caso o usuario opte por essa opção
void montarPrograma(Memoria *ram){

    //01:22:13:45 => isto é uma instrução na lingua CAVE LANGUAGE
    //0 => opcode => somar
    //1 => opcode => subtrair
    //-1 => halt

    for(int i=0; i<999; i++){
        ram->memoriaInstrucoes[i][0] = rand()%2;
        ram->memoriaInstrucoes[i][1] = rand()%100;
        ram->memoriaInstrucoes[i][2] = rand()%100;
        ram->memoriaInstrucoes[i][3]= rand()%100;
    }

    ram->memoriaInstrucoes[999][0] = -1;
    ram->memoriaInstrucoes[999][1] = -1;
    ram->memoriaInstrucoes[999][2] = -1;
    ram->memoriaInstrucoes[999][3]= -1;
}

//Se o usuario desejar realizar uma soma simples essa funcao e chamada e as instrucoes são encaminhadas para a maquina
void programaSoma(Memoria* ram, int parcela1, int parcela2){
    ram->memoriaInstrucoes[0][0] = 2;   //Leva pra RAM
    ram->memoriaInstrucoes[0][1]= parcela1;
    ram->memoriaInstrucoes[0][2] = 0;
    ram->memoriaInstrucoes[0][3] = -1;

    ram->memoriaInstrucoes[1][0] = 2;   //Leva pra RAM
    ram->memoriaInstrucoes[1][1] = parcela2;
    ram->memoriaInstrucoes[1][2]= 1;
    ram->memoriaInstrucoes[1][3]= -1;

    ram->memoriaInstrucoes[2][0] = 0;   //Realiza a operacao de soma uma vez
    ram->memoriaInstrucoes[2][1] = 0;
    ram->memoriaInstrucoes[2][2] = 1;
    ram->memoriaInstrucoes[2][3] = 1;

    ram->memoriaInstrucoes[3][0] = -1;    //Halt
    ram->memoriaInstrucoes[3][1] = -1;
    ram->memoriaInstrucoes[3][2] = -1;
    ram->memoriaInstrucoes[3][3] = -1;
    maquina(ram);
}

//Logica semelhante da funcao programaSoma, porem engloba a subtracao
void programaSubtracao(Memoria* ram, int minuendo, int subtraendo){
    ram->memoriaInstrucoes[0][0] = 2;   //Leva pra RAM
    ram->memoriaInstrucoes[0][1]= minuendo;
    ram->memoriaInstrucoes[0][2] = 0;
    ram->memoriaInstrucoes[0][3] = -1;

    ram->memoriaInstrucoes[1][0] = 2;   //Leva pra RAM
    ram->memoriaInstrucoes[1][1] = subtraendo;
    ram->memoriaInstrucoes[1][2]= 1;
    ram->memoriaInstrucoes[1][3]= -1;

    ram->memoriaInstrucoes[2][0] = 1;
    ram->memoriaInstrucoes[2][1] = 0;
    ram->memoriaInstrucoes[2][2] = 1;
    ram->memoriaInstrucoes[2][3] = 1;

    ram->memoriaInstrucoes[3][0] = -1;
    ram->memoriaInstrucoes[3][1] = -1;
    ram->memoriaInstrucoes[3][2] = -1;
    ram->memoriaInstrucoes[3][3] = -1;
    maquina(ram);
}

//Programa utilizado para multiplicar um numero n vezes
void programaMultiplicacao(Memoria *ram, int multiplicando, int multiplicador){
    //0 => opcode => somar
    //1 => opcode => subtrair
    //2 => salvar na memoria
    //-1 => halt

    ram->memoriaInstrucoes[0][0] = 2;   //Leva pra RAM
    ram->memoriaInstrucoes[0][1]= multiplicando;
    ram->memoriaInstrucoes[0][2] = 0;
    ram->memoriaInstrucoes[0][3] = -1;

    ram->memoriaInstrucoes[1][0] = 2;   //Leva pra RAM
    ram->memoriaInstrucoes[1][1] = 0;
    ram->memoriaInstrucoes[1][2]= 1;
    ram->memoriaInstrucoes[1][3]= -1;

    //Realiza multiplas somas salvando o resultado na RAM[1]
    for(int i=0; i<multiplicador; i++){

        ram->memoriaInstrucoes[i+2][0] = 0;
        ram->memoriaInstrucoes[i+2][1] = 0;
        ram->memoriaInstrucoes[i+2][2] = 1;
        ram->memoriaInstrucoes[i+2][3] = 1;
    }

    //instrucao para parar a maquina
    ram->memoriaInstrucoes[multiplicador+2][0] = -1;
    ram->memoriaInstrucoes[multiplicador+2][1] = -1;
    ram->memoriaInstrucoes[multiplicador+2][2] = -1;
    ram->memoriaInstrucoes[multiplicador+2][3]= -1;

    maquina(ram);
}

//Realiza a soma de dois números elevados ao quadrados
void somadosquadrados(Memoria *ram, int num1, int num2){

  //Variaveis auxiliares para alocar o quadrado de cada um dos números
  int result1, result2;

  //Chamando a função de potenciação para elevar ambos os valores ao quadrado
  programaPotenciacao(ram, num1, 2);
  result1=ram->RAM[1];

  programaPotenciacao(ram, num2, 2);
  result2=ram->RAM[1];

  // Chamando a função soma para somar os valores a serem somados
  programaSoma(ram, result1, result2);
}

void somadoscubos(Memoria *ram, int num1, int num2){

  //Variaveis auxiliares para alocar o quadrado de cada um dos números
  int result1, result2;

  //Chamando a função de potenciação para elevar ambos os valores ao quadrado
  programaPotenciacao(ram, num1, 3);
  result1=ram->RAM[1];

  programaPotenciacao(ram, num2, 3);
  result2=ram->RAM[1];

  // Chamando a função soma para somar os valores a serem somados
  programaSoma(ram, result1, result2);
}

//Realiza progressao aritmetica
void programaPA(Memoria* ram, int numero, int razao, int count){

    int aux;

    printf("%d  ", numero);

    ram->RAM[1]=numero;

    for(int i=0; i<count-1; i++){
      programaSoma(ram, razao, ram->RAM[1]);
      printf("%d  ", ram->RAM[1]);
    }

    printf("\n\n");

}

//Programa PG
void programaPG(Memoria* ram,int numero,int razao,int count){

  int aux = numero;

  //Imprime o primeiro numero da PG
  printf("%d  ",numero);

  //Multiplicacoes sucessivas para gerar a pg, o aux recupera o produto da multiplicacao e o adiciona na multiplicacao
  for(int i = 0; i<count-1; i++){
      programaMultiplicacao(ram, aux, razao);
      aux = ram->RAM[1];
      //Impressao dos diversos termos da pg
      printf("%d  ",ram->RAM[1]);
  }
}

//ProgramaPotencia
void programaPotenciacao(Memoria* ram, int num, int pot){

    int result = num;

    //Multiplicacao dos items n-vezes, result insere o valor do produto para ser multiplicado novamente
    for (int i = 0; i < pot -1; i++){
        programaMultiplicacao(ram,result,num);
        result = ram->RAM[1];
    }
}

//Programa divisao
void programaDivisao(Memoria *ram, int dividendo, int divisor){

    int cont = 0;

    ram->memoriaInstrucoes[0][0] = 2;   //Leva pra RAM
    ram->memoriaInstrucoes[0][1] = dividendo;
    ram->memoriaInstrucoes[0][2] = 0;
    ram->memoriaInstrucoes[0][3] = -1;

    ram->memoriaInstrucoes[1][0] = 2;   //Leva pra RAM
    ram->memoriaInstrucoes[1][1] = divisor;
    ram->memoriaInstrucoes[1][2] = 1;
    ram->memoriaInstrucoes[1][3] = -1;

    ram->memoriaInstrucoes[2][0] = -1;   //Halt
    ram->memoriaInstrucoes[2][1] = -1;
    ram->memoriaInstrucoes[2][2] = -1;
    ram->memoriaInstrucoes[2][3] = -1;

    maquina(ram);

    //Looping para realizar a divisão
    while (ram->RAM[0] >= ram->RAM[1]){

        ram->memoriaInstrucoes[0][0] = 1;   //Leva pra RAM
        ram->memoriaInstrucoes[0][1] = 0;
        ram->memoriaInstrucoes[0][2] = 1;
        ram->memoriaInstrucoes[0][3] = 0;

        ram->memoriaInstrucoes[1][0] = -1;  //Halt
        ram->memoriaInstrucoes[1][1] = -1;
        ram->memoriaInstrucoes[1][2] = -1;
        ram->memoriaInstrucoes[1][3] = -1;

        maquina(ram);

        //Cont para armazenar quantas vezes o looping foi executado
        //Cont = Resultado da divisão
        cont++;
    }

    ram->RAM[0]=cont;
}

//Programa Paralelepido
void volumeParalelepipedo(Memoria* ram, int altura, int largura, int comprimento){

    int aux;
    //Multiplicacao de duas dimensoe do paralelepipedo
    programaMultiplicacao(ram, altura, comprimento);
    //Aux coleta o resultado da multiplicacao
    aux = ram->RAM[1];
    //Multiplicacao subsequente das tres dimensoes
    programaMultiplicacao(ram, aux, largura);

}

//Programa Fatorial
void programaFatorial(Memoria* ram, int start){

    //Criação de variáveis auxiliares
    int aux,aux2;
    int cont=1;

    //Iniciando aux2 com o valor do número que será feito o fatorial
    aux2 = start;

    while(cont < start){

        //Subtraindo cont no número inicial
        programaSubtracao(ram, start, cont);
        //Guardando o resultado no aux1
        aux =  ram->RAM[1];
        //Multiplicando o valor obtido anteriormente com o seu sucessor
        programaMultiplicacao(ram, aux, aux2);
        //Guardando o resultado no aux2 para atualizar o termo aux2
        aux2 = ram->RAM[1];

        cont++;
    }
}

//Codigos de retorno de memoria
int* retornaRAM(Memoria* ram){
  return ram->RAM;
}

//Liberar Memoria
void liberaRam(Memoria* ram){
    free(ram);
}

void maquina(Memoria* ram){

    //Mantém Endereço da próxima instrução a buscar
    int PC = 0;
    int opcode = TMP_MAX;
    while(opcode != -1){
        opcode = ram->memoriaInstrucoes[PC][0];
        switch (opcode){

        //leva para a RAM a instrucao

        case 0:{
            //somar
            int end1 = ram->memoriaInstrucoes[PC][1];
            int end2 = ram->memoriaInstrucoes[PC][2];
            int end3 = ram->memoriaInstrucoes[PC][3];
            //Buscar na RAM e realizar a operacao desejada
            int soma = ram->RAM[end1] + ram->RAM[end2];

            //Salva os resultados na RAM
            ram->RAM[end3] = soma;
            break;
        }

        case 1:{

            //subtrai
            int end1 = ram->memoriaInstrucoes[PC][1];
            int end2 = ram->memoriaInstrucoes[PC][2];
            int end3 = ram->memoriaInstrucoes[PC][3];
            //Buscar na RAM
            int sub = ram->RAM[end1] - ram->RAM[end2];

            //Salva na RAM
            ram->RAM[end3] = sub;
            break;
        }

        case 2:{

            int end1 = ram->memoriaInstrucoes[PC][1];
            int end2 = ram->memoriaInstrucoes[PC][2];
            ram->RAM[end2] = end1;
            //Levando para a RAM no endereco umaInstrucao[2] o valor de umaInstrucao[1]
            break;
        }
        }

        PC++;
    }
}
