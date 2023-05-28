/****************** SERVER CODE ****************/

#include <stdio.h>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <cmath>
#include <stdlib.h>

#define BUFFER_SIZE 2048

using namespace std;

int main()
{
    int welcomeSocket, newSocket;
    long int fileSize, writeSize = 0;
    char recvBuffer[BUFFER_SIZE], recvSize[BUFFER_SIZE];
    char filePath[75] = "receive/";
    struct sockaddr_in serverAddr;
    socklen_t addr_size;
    FILE *destinyFile;

    welcomeSocket = socket(PF_INET, SOCK_STREAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(7891);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);
    bind(welcomeSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr));

    (listen(welcomeSocket, 5) == 0) ? printf("Listening...\n") : printf("Error.\n");

    newSocket = accept(welcomeSocket, (struct sockaddr *)NULL, NULL);
    printf("OK -> Cliente conectado!\n");

    printf("Esperando o nome  do arquivo.\n");
    recv(newSocket, recvBuffer, sizeof(recvBuffer), 0);
    strcat(filePath, recvBuffer);
    printf("Nome do arquivo: %s\n", filePath);

    destinyFile = fopen(filePath, "wb");
    if (!destinyFile){
        printf("ERRO : Arquivo inexistente.\n");
        close(newSocket);
        exit(1);
    }

    printf("Esperando comprimento do arquivo.\n");
    recv(newSocket, recvBuffer, sizeof(recvBuffer), 0);
    fileSize = atol(recvBuffer);
    printf("Comprimento do arquivo: %ld\n", fileSize);

    for (int i = 0 ; i < ceil((double)fileSize / BUFFER_SIZE) ; i++){
        recv(newSocket, recvBuffer, sizeof(recvBuffer), 0);
        if(writeSize + BUFFER_SIZE > fileSize){
            writeSize += fwrite(recvBuffer, sizeof(char), fileSize - writeSize, destinyFile);
            break;
        }
        writeSize += fwrite(recvBuffer, sizeof(char), BUFFER_SIZE, destinyFile);
    }

    printf("Bytes recebidos: %ld\n", writeSize);

    close(newSocket);
    return 0;
}