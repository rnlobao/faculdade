void expoInstru (int guarda_memoria[][4], int base, int expoente, int *memoriadedados) {

    //2 ^ 3 = 2 * 2 * 2 = (2 + 2 + 2 + 2)

    //4 ^ 2 = 4 * 4 = ( 4 + 4 + 4 + 4)

    //int exp = expoente + 3;

    //int instrumMemoryexpo[exp][4];

    int umaInstrucao[4]; 

    int i, j;

    //leva para memoriadedados[0] o valor da base
    umaInstrucao[0] = 2;
    umaInstrucao[1] = base;
    umaInstrucao[2] = 0;
    umaInstrucao[3] = -1;


    maquinaOPERACOES(umaInstrucao, memoriadedados);

    //leva para memoriadedados[1] o valor 0 para realizar a primeira soma com a base
    umaInstrucao[0] = 2;
    umaInstrucao[1] = 0;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;

    maquinaOPERACOES(umaInstrucao, memoriadedados);

    // 2 ^ 3 : 2 * 2 * 2 -> (2 + 2) = 4 * 2 -> (4 + 4) = 8
    // 3 ^ 3 : 3 * 3 * 3 -> (3 + 3 + 3) = 9 * 3 -> (9 + 9 + 9) = 27


    //Vai fazer n somas para de acordo com as soma que ja ocorreram 

    for (i = 0; i < expoente - 1; i++) { /*Sao n expoentes e não n - 1 expoentes, pois passara uma vez 
                                        dentro do primeiro for para realizar uma primeira soma e depois 
                                        colocar valor novo para base*/

        if (i != 0){
            //trazer da memoria o valor da "nova base" criada com as somas 

            umaInstrucao[0] = 3;
            umaInstrucao[1] = -1;
            umaInstrucao[2] = 1;
            umaInstrucao[3] = -1;

            maquinaOPERACOES(umaInstrucao, memoriadedados);
            int novabase = umaInstrucao[1];


            //coloca um novo valor na memoriadados[0] para realizar somas com um "novo valor de base"
            umaInstrucao[0] = 2;
            umaInstrucao[1] = novabase;
            umaInstrucao[2] = 0;
            umaInstrucao[3] = -1;

            maquinaOPERACOES(umaInstrucao, memoriadedados);
        } 

        else {
            umaInstrucao[0] = 0;
            umaInstrucao[1] = 0;
            umaInstrucao[2] = 1;
            umaInstrucao[3] = 1;

            maquinaOPERACOES(umaInstrucao, memoriadedados);
        }

        for (j = 0; j < base - 1; j ++){ /*Serao realizar n base - 1 somas ja que para cada
                                            valor novo de base, sempre há n base - 1 somas*/
            umaInstrucao[0] = 0;
            umaInstrucao[1] = 0;
            umaInstrucao[2] = 1;
            umaInstrucao[3] = 1;

            maquinaOPERACOES(umaInstrucao, memoriadedados);

        }
    }

    //halt 
    umaInstrucao[0] = -1;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = -1;
    umaInstrucao[3] = -1;

    maquinaOPERACOES(umaInstrucao, memoriadedados);

    umaInstrucao[0] = 3;
    umaInstrucao[1] = -1;
    umaInstrucao[2] = 1;
    umaInstrucao[3] = -1;

    maquinaOPERACOES(umaInstrucao, memoriadedados);
    int resultadoEXPO = umaInstrucao[1];

    printf("\nO valor da expoenciaçao é igual a %d\n\n", resultadoEXPO);


}