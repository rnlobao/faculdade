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


//Se o usuario desejar realizar uma soma simples essa funcao e chamada e as instrucoes são encaminhadas
// para a maquina
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


void raizquadrada(Memoria *ram, int num1){
    int count = 0;
    for (int i = 0; num1 >= (i*i); i++ ) {
        ram->memoriaInstrucoes[0][0] = 2;   //Leva pra RAM
        ram->memoriaInstrucoes[0][1]= count;
        ram->memoriaInstrucoes[0][2] = 1;
        ram->memoriaInstrucoes[0][3] = -1;

        ram->memoriaInstrucoes[1][0] = -1;    //Halt
        ram->memoriaInstrucoes[1][1] = -1;
        ram->memoriaInstrucoes[1][2] = -1;
        ram->memoriaInstrucoes[1][3] = -1;
        maquina(ram);
        count++;
    }
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
  printf("\n\n");
}

//ProgramaPotencia
void programaPotenciacao(Memoria* ram, int base, int expoente){
    
    int result = base;

    //so conferindo se o exp nao é 0, se for ja joga como sendo valor 1.
    if (expoente == 0) {
        ram->memoriaInstrucoes[0][0] = 2;   //Leva pra RAM
        ram->memoriaInstrucoes[0][1]= 1;
        ram->memoriaInstrucoes[0][2] = 1;
        ram->memoriaInstrucoes[0][3] = -1;

        ram->memoriaInstrucoes[1][0] = -1;    //Halt
        ram->memoriaInstrucoes[1][1] = -1;
        ram->memoriaInstrucoes[1][2] = -1;
        ram->memoriaInstrucoes[1][3] = -1;
        maquina(ram);
    }

    //adaptação do codigo feito com o prof
    //Multiplicacao dos items n-vezes, result insere o valor do produto para ser multiplicado novamente
    else {
        for (int i = 0; i < expoente -1; i++){
            programaMultiplicacao(ram,result,base);
            result = ram->RAM[1];
            ram->memoriaInstrucoes[0][0] = 2;
            ram->memoriaInstrucoes[0][1] = base;  
            ram->memoriaInstrucoes[0][2] = -1; //guardar o conteúdo da ram
            ram->memoriaInstrucoes[0][3] = -1;

            ram->memoriaInstrucoes[1][0] = -1; //halt
            ram->memoriaInstrucoes[1][1] = -1; 
            ram->memoriaInstrucoes[1][2] = -1;
            ram->memoriaInstrucoes[1][3] = -1;
            maquina(ram);
        }
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

void bhaskara (Memoria* ram, int a, int b, int c) {
    //a * c
    int valordea = a;
    programaMultiplicacao(ram, valordea, c);
    int avezesc = ram->RAM[1];
    ram->memoriaInstrucoes[0][0] = 2;  
    ram->memoriaInstrucoes[0][1] = avezesc;
    ram->memoriaInstrucoes[0][2] = -1;
    ram->memoriaInstrucoes[0][3] = -1;

    //4 * a * c
    programaMultiplicacao(ram, avezesc, 4);
    int quatroac = ram->RAM[1];
    ram->memoriaInstrucoes[1][0] = 2;  
    ram->memoriaInstrucoes[1][1] = quatroac;
    ram->memoriaInstrucoes[1][2] = -1;
    ram->memoriaInstrucoes[1][3] = -1;

    //b elevado a 2
    programaPotenciacao(ram, b, 2);
    int baoquadrado = ram->RAM[1];
    ram->memoriaInstrucoes[2][0] = 2;  
    ram->memoriaInstrucoes[2][1] = baoquadrado;
    ram->memoriaInstrucoes[2][2] = -1;
    ram->memoriaInstrucoes[2][3] = -1;

    //b^2 - 4ac
    programaSubtracao(ram, baoquadrado, quatroac);
    int subtracao = ram->RAM[1];
    ram->memoriaInstrucoes[3][0] = 1;  
    ram->memoriaInstrucoes[3][1] = subtracao;
    ram->memoriaInstrucoes[3][2] = 1;
    ram->memoriaInstrucoes[3][3] = 1;

    int delta, deltanegativo;
    int doisa;
    int menosb1, menosb2;
    int divisao1, divisao2;

    if (subtracao < 0) {
        printf("Erro");
        return;
    }
    
    else {
        //2a
        programaMultiplicacao(ram, 2, a);
        doisa = ram->RAM[1];
        ram->memoriaInstrucoes[4][0] = 1;  
        ram->memoriaInstrucoes[4][1] = doisa;
        ram->memoriaInstrucoes[4][2] = 1;
        ram->memoriaInstrucoes[4][3] = 1;


        //raiz de b^2 - 4ac, positivo e negativo
        raizquadrada(ram, subtracao);
        delta = ram->RAM[1];
        ram->memoriaInstrucoes[5][0] = 1;  
        ram->memoriaInstrucoes[5][1] = delta;
        ram->memoriaInstrucoes[5][2] = 1;
        ram->memoriaInstrucoes[5][3] = 1;

        deltanegativo = -ram->RAM[1];
        ram->memoriaInstrucoes[6][0] = 1;  
        ram->memoriaInstrucoes[6][1] = deltanegativo;
        ram->memoriaInstrucoes[6][2] = 1;
        ram->memoriaInstrucoes[6][3] = 1;

        programaSubtracao(ram, -b, delta);
        menosb1 = ram->RAM[1];
        ram->memoriaInstrucoes[7][0] = 1;  
        ram->memoriaInstrucoes[7][1] = menosb1;
        ram->memoriaInstrucoes[7][2] = 1;
        ram->memoriaInstrucoes[7][3] = 1;

        programaSubtracao(ram, -b, deltanegativo);
        menosb2 = ram->RAM[1];
        ram->memoriaInstrucoes[8][0] = 1;  
        ram->memoriaInstrucoes[8][1] = menosb2;
        ram->memoriaInstrucoes[8][2] = 1;
        ram->memoriaInstrucoes[8][3] = 1;

        programaDivisao(ram, menosb1, doisa);
        divisao1 = ram->RAM[1];
        ram->memoriaInstrucoes[9][0] = 1;  
        ram->memoriaInstrucoes[9][1] = divisao1;
        ram->memoriaInstrucoes[9][2] = 1;
        ram->memoriaInstrucoes[9][3] = 1;

        programaDivisao(ram, menosb2, doisa);
        divisao2 = ram->RAM[1];
        ram->memoriaInstrucoes[10][0] = 1;  
        ram->memoriaInstrucoes[10][1] = divisao2;
        ram->memoriaInstrucoes[10][2] = 1;
        ram->memoriaInstrucoes[10][3] = 1;  
    }
    
    ram->memoriaInstrucoes[11][0] = -1; //halt
    ram->memoriaInstrucoes[11][1] = -1; 
    ram->memoriaInstrucoes[11][2] = -1;
    ram->memoriaInstrucoes[11][3] = -1;
    maquina(ram);
    printf("Valor1: %d e valor2: %d\n", divisao1, divisao2);
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
