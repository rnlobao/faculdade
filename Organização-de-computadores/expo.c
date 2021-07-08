void baskara (int **guarda_memoria, int a, int b, int c, int *memoriadedados) {

    int umaInstrucao[4];

    int instrumMemoryBaskara[100][4];

    int multiac;

    int quadradodeb;

    int delta;

    //resolvendo o delta primeiro
    multiplicaInstru(instrumMemoryBaskara, a, c, memoriadedados); // a * c

    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;
    
    maquinaOPERACOES(umaInstrucao, memoriadedados);
    multiac = umaInstrucao[1];

    multiplicaInstru(instrumMemoryBaskara, 4, multiac, memoriadedados); // ac * 4

    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;
    
    maquinaOPERACOES(umaInstrucao, memoriadedados);
    multiac = umaInstrucao[1];

    expoInstru(instrumMemoryBaskara, b, 2, memoriadedados);// b * b

    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;
    
    maquinaOPERACOES(umaInstrucao, memoriadedados);
    quadradodeb = umaInstrucao[1];

    //levo para memoriadedados[0] o valor de multiac
    umaInstrucao[0] = 2;
    umaInstrucao[1] = multiac;
    umaInstrucao[2] = 0;
    umaInstrucao[3] = -1;

    maquinaOPERACOES(umaInstrucao, memoriadedados);

    //levo para memoriadedados[1] o valor do quadrado de b
    umaInstrucao[0] = 2;
    umaInstrucao[1] = quadradodeb;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;

    maquinaOPERACOES(umaInstrucao, memoriadedados);


    //Subtraçao entre quadradodeb e multiac (memoriadados[1] - memoriadados[0])
    umaInstrucao[0] = 1;
    umaInstrucao[1] = 1;
    umaInstrucao[2] = 0;
    umaInstrucao[3] = 1;

    maquinaOPERACOES(umaInstrucao, memoriadedados);


    //trago da memoria o valor da subtraçao anterior
    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;

    maquinaOPERACOES(umaInstrucao, memoriadedados);
    delta = umaInstrucao[1];

    raizquadradaInstru(instrumMemoryBaskara, delta, memoriadedados); //Raiz quadrada de delta

    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;

    maquinaOPERACOES(umaInstrucao, memoriadedados);
    int raiz = umaInstrucao[1];

    //Agora vou dividir em dois resultaod: um onde a raiz de delta é positiva e outro onde a raiz de delta é negativa

    //levo para memoriadedados[0] o valor da raiz positiva
    umaInstrucao[0] = 2;
    umaInstrucao[1] = raiz;
    umaInstrucao[2] = 0;
    umaInstrucao[3] = -1;

    maquinaOPERACOES(umaInstrucao, memoriadedados);

    //levo para memoriadedados[1] o valor da raiz negativa
    umaInstrucao[0] = 2;
    umaInstrucao[1] = -raiz;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;

    maquinaOPERACOES(umaInstrucao, memoriadedados);

    //levo para memoriadedados[2] o valor de b
    umaInstrucao[0] = 2;
    umaInstrucao[1] = -b;
    umaInstrucao[2] = 2;
    umaInstrucao[3] = -1;

    maquinaOPERACOES(umaInstrucao, memoriadedados);

    //soma1 
    umaInstrucao[0] = 0;
    umaInstrucao[1] = 0;
    umaInstrucao[2] = 2;
    umaInstrucao[3] = 3;
    maquinaOPERACOES(umaInstrucao, memoriadedados);

    //trago da memoria o valor da primeira soma
    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 3;
    umaInstrucao[3] = -1;
    maquinaOPERACOES(umaInstrucao, memoriadedados);
    int soma1 = umaInstrucao[1]; 

    //soma2
    umaInstrucao[0] = 0;
    umaInstrucao[1] = 1;
    umaInstrucao[2] = 2;
    umaInstrucao[3] = 4;
    maquinaOPERACOES(umaInstrucao, memoriadedados);

    //trago da memoria o valor da segunda soma
    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 4;
    umaInstrucao[3] = -1;
    maquinaOPERACOES(umaInstrucao, memoriadedados);
    int soma2 = umaInstrucao[1]; 


    //faço a multiplicaçao de 2 * a 
    multiplicaInstru(instrumMemoryBaskara, a, 2, memoriadedados);

    //trago da memoria o valor da multiplicaçao entre 2 e a
    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;
    maquinaOPERACOES(umaInstrucao, memoriadedados);
    int multia = umaInstrucao[1]; 

    //Primeira raiz 
    divideInstru(instrumMemoryBaskara, -soma1, multia, memoriadedados);

    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 3;
    umaInstrucao[3] = -1;
    maquinaOPERACOES(umaInstrucao, memoriadedados);
    int result1 = -umaInstrucao[1];

    printf("\n1ª raiz = %d\n\n", result1);

    //Segunda raiz 
    divideInstru(instrumMemoryBaskara, -soma2, multia, memoriadedados);

    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 3;
    umaInstrucao[3] = -1;
    maquinaOPERACOES(umaInstrucao, memoriadedados);
    int result2 = -umaInstrucao[1];

    printf("\n2ª raiz = %d\n", result2);
}