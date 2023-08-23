#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstring>

int main() {
    int inPipe[2], outPipe[2];
    pid_t pid;
    
    if (pipe(inPipe) == -1 || pipe(outPipe) == -1) {
        perror("pipe");
        return 1;
    }
    
    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }
    
    if (pid == 0) { 
        close(inPipe[1]);
        close(outPipe[0]);
        
        dup2(inPipe[0], STDIN_FILENO);
        dup2(outPipe[1], STDOUT_FILENO);
        
        close(inPipe[0]);
        close(outPipe[1]);
        
        execl("/bin/bash", "/bin/bash", nullptr);
        return 1;
    } else {
        close(inPipe[0]);
        close(outPipe[1]);
        
        
        std::string command;
        char buffer[128];
        
        while (true) {
            std::cout << "Enter a command: ";
            std::getline(std::cin, command);
            
            if (command == "exit") {
                break;
            }
            
            write(inPipe[1], command.c_str(), command.size());
            write(inPipe[1], "\n", 1);
            
            memset(buffer, 0, sizeof(buffer));
            while (read(outPipe[0], buffer, sizeof(buffer)) > 0) {
                std::cout << buffer;
                memset(buffer, 0, sizeof(buffer));
            }
        }
        
        close(inPipe[1]);
        close(outPipe[0]);
        
        wait(nullptr);
    }
    
    return 0;
}
