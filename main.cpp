#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  // Create an infinite loop that prompts the user to enter a command.
  while (true) {
    cout << "Enter a command: ";
    string command;
    getline(cin, command);

    // Parse the user's input into a command and its arguments.
    vector<string> arguments;
    size_t i = 0;
    while (i < command.size() && command[i] != ' ') {
      arguments.push_back(command[i]);
      i++;
    }

    // Check if the command is a built-in command.
    if (arguments[0] == "exit") {
      break;
    } else if (arguments[0] == "help") {
      cout << "Available commands: exit, help" << endl;
    } else {
      // Execute the command in a child process.
      int pid = fork();
      if (pid == 0) {
        // Child process
        try {/*This is a Script used to automate things Better and save time */
/*Real Hackers Save Time */

#include <iostream>

using namespace std;

/*imac mailmc*/

void banner(){
    string cutoff="Welcome to Trix board";
    cout << cutoff << endl;
}

void rev_shell(){
    
}
int main(){
   
    banner();
   
    int x;

    cout << "Enter the Number you Need to Execute :" << endl;
    cout << "1. Generate Reverse shell !" << endl;
    cout << "2. Execute Commands on Reverse shell" << endl;
    cout << "3. Exit"<< endl;
    cout << "Choice : ";
    cin >> x;
    

    if(x==1){
        cout << "worked 1";
        cout << "Checking Packges pease wait !"
        exit(0);
    }

    if (x==2){
        cout << "worked 2" ;
    }

    if(x==3){
        exit(0);
    }

    else{
        main();
    }
    return 0;
}
          execvp(arguments[0].c_str(), &arguments[0]);
        } catch (const std::exception& e) {
          cout << "Error: " << e.what() << endl;
        }
      } else {
        // Parent process
        waitpid(pid, NULL, 0);
      }
    }
  }

  return 0;
}
