
## Mavoc C2 Framework [ BETA RELEASE ]

<img src="https://img.shields.io/badge/g%2B%2B-%E2%89%A5%20v12.3.0-darkcyan"> <img src="https://img.shields.io/badge/Python-%E2%89%A5%203.6-yellow.svg">
<img src="https://img.shields.io/badge/PowerShell-%E2%89%A5%20v3.0-blue">
<img src="https://img.shields.io/badge/Developed%20on-kali%20linux-darkblue">
<img src="https://img.shields.io/badge/Maintained%3F-Yes-Green">
![Visitors](https://visitor-badge.laobi.icu/badge?page_id=Whitecat18.Mavoc&title=Visitor )   
<!--Please Don't Forgot to Hit :star:-->



## Introduction
Mavoc is an tool used to pentest Windows and Linux machine. This tool mainly Focuses on Pentesting Windows . Made with using  C++, Powershell and the server made with Python and go . This tool is Easy to use and the payloads are modifiable for your Needs . This tool is mainly Focuses on Windows Pentesing, and Automated Various Scripts to attack windows based System and can be used to add own scripts for ctf , attcking , debugging etc .. depens upon your needs .

 
https://github.com/Whitecat18/Mavoc/assets/96696929/2518e411-7b3b-4259-bf0f-15bcec128e1f

<h3> Please Visit <b> <a href="https://www.smukx.site/tool-walkthrough/mavoc-tool-walkthrough" > Mavoc Blog </a></b> for complete tutorial and Video Demonstration</h3>

## Installation 

The Tool can be used to get reverse shell in 3 various methods . SSH-Kench aka using rev-ssh RSSH , Python and Low Func C++ (coming soon) .

```
git clone https://github.com/Whitecat18/Mavoc
cd Mavoc
bash install.sh 
./mavoc
```

On Mavoc tool . There will be 2 options . SSH Hack , Python-Exin and Low-Func. <br>
For Now SSH-Kench and Python-Exin are avaiable.

Based on your Needs Select what you need.

### What is the Different between SSH-Kench and Python-Exin ?

* SSH-Kench is more stable , even when you disconnect or shut the server,and start the server with same settings means, the victim can connect again.
* SSH-Kench is Well Suited to do Large Attacks and Good at stable connection.
* Python-Exin is an Powershell Payload prompter that alters the pre-payload (ie) Modifies it . When pasting the prompt payload script on .ps console will leads to get the reverse shell. 
* Python-Exin is not Good for Stability and cant be used for large tasks and attack process . 
* Python-Exin is an Older Version of Villain tool . Which i used to modify and keep it for my personal use . Now i am adding to the Tool .

## Working Methodology:

First You Will be Prompted to Enter into the shell . Based upon what you need . You can select depend upon your needs.

### SSH-Kench
After Entering ssh kench . Enter your local Ip addeess. eg:192.168.1.101 <br>

Entering yes ( y ) will start an server . For Now Lets continue with  no ( n ) . 
Entering help command will display the avaiable cmds to execute . From There , lets start the server using start server command .   

`generate windows payload` Alters and gives the powershell payload .

`generate linux payload` will give you the bash payload .

`connect server` command will open an mavoc-shell on an new tmux terminal. 


After Executing the payload given by the mavoc . you will get an connection to the mavoc-shell . 
Here's the Demo Video.

## Attacking Linux 

Open the ssh kench and generate the payload using generate linux payload. Execute in the Shell and exit . Short Video Demo . 

Please Visit <b> <a href="https://www.smukx.site/tool-walkthrough/mavoc-tool-walkthrough" > Mavoc Blog </a></b> for more Demo Videos .

## Attcking Windows.

So the main part begins  . Lets do it

`generate windows payload` and copy the payload and use your tricks and tips to deliver the payload.

```
Tip: use Direct method or My Fav Part, use the Rubber Ducky or ATTINITY85 Digispark to execute the payload or bind the payload string to any know software or programs to os modules to exec it .   
```
Demo Video

Please Visit <b> <a href="https://www.smukx.site/tool-walkthrough/mavoc-tool-walkthrough" > Mavoc Blog </a></b> for Demo Videos .



### Using Powershell Bible.

Powershell bible consists of 20+ Advance attcking and Enumeration commands that will execute at 
mavoc-shell at tmux shell .

Some scripts are not added because it can be unfair to execute such scripts agaist user .  The Scripts are in the Test Mode and will be added once its compactable with all windows Machines . Powershell bible is only For Windows Operating Systems .  

Use `ps bible` Command to load powershell modules after getting connection from the victim . Execute `ps bible` and Type `help` for more info .

Demo Video ....
  

## How to Copy an text from Mavoc-Shell (ie) Tmux terminal  !  

* Enter Copy Mode: Press Ctrl + b (the default tmux prefix) followed by [ to enter copy mode. This is similar to scrolling mode and allows you to navigate and select text.
* Navigate and Select Text: Once you're in copy mode, you can use the arrow keys, Page Up, Page Down, and other navigation keys to move around and select the text you want to copy. To start selecting, move the cursor to the beginning of the text you want to copy.
* Begin Selection: Press Space to start selecting text. Move the cursor to highlight the desired text.
* Copy Text: After selecting the text, press Enter to copy the selected text to the clipboard.
* Exit Copy Mode: Press q to exit copy mode. You'll be back in the normal tmux session.
* Paste Text: You can now paste the copied text outside the tmux session using the usual paste command for your terminal emulator (usually Ctrl + Shift + v or right-click and select "Paste").

For Step By Step Process . Please Visit this Blog where they Explain step by step <b><a href="https://www.fosslinux.com/105809/tmux-copy-paste-mode-tips-and-tricks-for-productivity.htm#:~:text=Once%20you%20have%20selected%20the,text%20you%20want%20to%20paste" > Tmux Blog </a></b>
