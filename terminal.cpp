#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h> 

int main() {
    const char* serverIP = "127.0.0.1";
    const int serverPort = 12345;

    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(serverPort);
    inet_pton(AF_INET, serverIP, &(serverAddr.sin_addr));

    if (connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        perror("Error connecting to server");
        return 1;
    }

    std::string command;
    while (true) {
        std::cout << "Mavoc > ";
        std::getline(std::cin, command);

        if (command == "exit") {
            break;
        }
        send(clientSocket, command.c_str(), command.size(), 1);
    }

    // Close the socket
    close(clientSocket);

    return 0;
}
