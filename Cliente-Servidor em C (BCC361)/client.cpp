#include <iostream>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <cmath>

#define BUFFER_SIZE 2048

using namespace std;

void readEntries (char *serverIP, char *filePath, int *serverPort);

int main (int argc, char *argv[]){
    char serverIP[15], filePath[75];
    char buffer[BUFFER_SIZE];
    int serverPort, clientSocket;
    long int fileSize, sentSize = 0, sentPackage;
    struct sockaddr_in serverAddr;
    socklen_t addr_size;
    FILE *arquivo;

    readEntries(serverIP, filePath, &serverPort);
    clientSocket = socket(PF_INET, SOCK_STREAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(serverPort);
    serverAddr.sin_addr.s_addr = inet_addr(serverIP);
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  
    addr_size = sizeof serverAddr;
    connect(clientSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

    send(clientSocket,filePath,sizeof(filePath),0);

    arquivo = fopen(filePath, "rb");
    if (!arquivo){
        printf("ERRO : Arquivo inexistente.\n");
        close(clientSocket);
        exit(1);
    }

    fseek(arquivo, 0, SEEK_END);
    fileSize = ftell(arquivo);
    fseek(arquivo, 0, SEEK_SET);
    snprintf(buffer, BUFFER_SIZE, "%ld", fileSize);

    send(clientSocket,buffer,sizeof(buffer),0);

    for (int i = 0 ; i < ceil ((double)fileSize / (double)BUFFER_SIZE) ; i++){
        sentSize += fread(buffer, sizeof(char), BUFFER_SIZE, arquivo);
        send(clientSocket,buffer,sizeof(buffer),0);
    }

    printf("Bytes enviados: %ld\n", sentSize);

    close(clientSocket);
    return 0;
}

void readEntries (char *serverIP, char *filePath, int *serverPort){
    cout << "Server IP:";
    cin >> serverIP;
    cout << "Server Port:";
    cin >> *serverPort;
    cout << "File Path:";
    cin >> filePath;
}