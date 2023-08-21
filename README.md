
## Info 
Mavoc is an tool used to pentest Windows and Linux machine . This tool mainly Focuses on Pentesting Windows . Made with using Powershell, C++ and Go .  This tool is Easy to use and the payloads are modifiable for your Needs .

For More info . Please Visit <b> <a href="https://www.smukx.site/tool-walkthrough/mavoc-tool-walkthrough" > Mavoc Blog </a></b>

## Installation 
The Tool can be used to get reverse shell in 3 various methods . SSH-Kench , Python and Low Func C++ (coming soon) .

```
git clone https://github.com/Whitecat18/Mavoc
bash install.sh (or) 
chmod +x install.sh ; ./install.sh
./mavoc
```

On Mavoc tool . There will be 2 options . SSH Hack , Python-Exin and Low-Func. <br>
For Now SSH-Kench and Python-Exin are avaiable.

Based on your Needs Select what you need.

### What is the Different between SSH-Kench and Python-Exin ?

* SSH-Kench is more stable , even when you disconnect from server on the attacker side and reopen the server with same config means , the payload can connect again.
* SSH-Kench is Well Suited to do Large Attacks and Good at stability connection.
* Python-Exin is an Powershell Payload prompter that alters the pre-payload (ie) Modifies it . When pasting the prompt payload script on .ps console will leads to get the reverse shell. 
* Python-Exin is not Good for Stability and cant be used for large tasks and attack process . 
* Python-Exin is an Older Version of Villain tool . Which i used to modify and keep it for my personal use . Now i am adding to the Tool .

## Working Methodology:

First You Will be Prompted to Enter into the shell . Based upon what you need . You can select depend upon your needs.

### SSH-Kench
After Entering ssh kench . Enter your local Ip addeess. eg:192.168.1.101 <br>

Entering yes ( y ) will start an server . For Now Lets continue with  no ( n ) . 
Entering help command will display the avaiable cmds to execute . From There , lets start the server using start server command .   

`generate windows payload` Alters and gives the powershell payload .<br>
`generate linux payload` will give you the bash payload .

`connect server` command will open an mavoc-server on an new terminal server. 


After Executing the payload given by the mavoc . you will get an connection to the mavoc-shell . 
Here's the Demo Video.

### Attacking Linux . 
Open the ssh kench and generate the payload . copy into an bash shell and exit . This is an Stable Payload written with Go . Short Video Demo 

### Attacking Windows . 

The Main Purpose of the Tool is to perform Various attacks . 

Demo Video ...

coming soon ...
