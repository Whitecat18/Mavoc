
## Mavoc C2 Framework [ BETA RELEASE ]

<p align="center">
  <img src="https://github.com/Whitecat18/Mavoc/assets/96696929/ed74cd1e-1f9d-4293-95e6-399d2cd74078.jpg" height="300">
</p>

--------------------------------------

<img src="https://img.shields.io/badge/g%2B%2B-%E2%89%A5%20v12.3.0-darkcyan"> <img src="https://img.shields.io/badge/Python-%E2%89%A5%203.6-yellow.svg">
<img src="https://img.shields.io/badge/PowerShell-%E2%89%A5%20v3.0-blue">
<img src="https://img.shields.io/badge/Developed%20on-kali%20linux-darkblue">
<img src="https://img.shields.io/badge/Maintained%3F-Yes-Green">
![Visitors](https://visitor-badge.laobi.icu/badge?page_id=Whitecat18.Mavoc&title=Visitor )   
<!--Please Don't Forgot to Hit :star:-->

# Table of Context.

<b>
1. <a href="#introduction" >Introduction</a><br>
2. <a href="#working-methodology" > How it Works </a><br>
3. <a href="#working-methodology" > Attacking Linux </a><br>
4. <a href="#attcking-windows" > Attacking Windows </a><br>
4. <a href="#using-powershell-bible" > Powershell bible Hack </a><br>
</b>


## Introduction
Mavoc is an tool used to pentest Windows and Linux machine. This tool mainly Focuses on Pentesting Windows . Made with using  C++, Powershell and the server made with Python and go . This tool is Easy to use and the payloads are modifiable for your Needs . This tool is mainly Focuses on Windows Pentesing, and Automated Various Scripts to attack windows based System and can be used to add own scripts for ctf , attcking , debugging etc .. depens upon your needs .

Tested at : <b> UBUNTU , DEBIAN , KALI LINUX </b>
 
https://github.com/Whitecat18/Mavoc/assets/96696929/2518e411-7b3b-4259-bf0f-15bcec128e1f

<h3> Please Visit <b> <a href="https://www.smukx.site/tool-walkthrough/mavoc-tool-walkthrough" > Mavoc Documentation </a></b> for complete tutorial and Video Demonstration</h3>

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
Blog
After Entering ssh kench . Enter your local Ip addeess. eg:192.168.1.101 <br>

Entering yes ( y ) will start an server . For Now Lets continue with  no ( n ) . 
Entering help command will display the avaiable cmds to execute . From There , lets start the server using start server command .   

`generate windows payload` Alters and gives the powershell payload .

`generate linux payload` will give you the bash payload .

`connect server` command will open an mavoc-shell on an new tmux terminal. 


After Executing the payload given by the mavoc . you will get an connection to the mavoc-shell . 
Here's the Demo Video.

**Note : Mavoc Server supports tab completion . you can use it to connect machines using connect  and by pressing tab key to autocomplete .**

## Attacking Linux 

#### Open the ssh kench and generate the payload using generate linux payload. Execute in the Shell and exit . 

<center><img src="https://github.com/Whitecat18/Mavoc/assets/96696929/81af06a1-cca4-440c-8c4d-2f3712ac99ea.png" height="150"/></center>

#### exec the payload to linux shell and exit . 

<img src="https://github.com/Whitecat18/Mavoc/assets/96696929/c88913c5-f094-4886-b2e2-b18c77e58757.png" height="150"/>
<br>

#### check the mavoc-shell and connect 

<img src="https://github.com/Whitecat18/Mavoc/assets/96696929/5836e1d9-2ef9-4a0d-ab8f-95d4051b4876.png" height="150"/>
<br> <br>
<img src="https://github.com/Whitecat18/Mavoc/assets/96696929/38a4f75e-b0b9-480d-8678-493252a0f21f.png" height="150"/>

### Short Video Demo . 

Please Visit <b> <a href="https://www.smukx.site/tool-walkthrough/mavoc-tool-walkthrough" > Mavoc Documentation </a></b> for more Demo Videos .

## Attcking Windows.

So the main part begins 👿. Lets do it

`generate windows payload` and copy the payload and use your tricks and tips to deliver the payload.

<img src="https://github.com/Whitecat18/Mavoc/assets/96696929/8d6773cf-a5c1-4623-851e-4a96e02f0bf5.png" height="150"/>

Copy the powershell payload and execute in the victim machine. 

<img src="https://github.com/Whitecat18/Mavoc/assets/96696929/6b13f709-5588-479e-b4d3-64ee3e0ce18d.png" height="150"/>

After that check you server if you got an (RSSH) Reverse Shell connection . use ls command to check if it works and type and tab key to autocomplete the connection .

<img src="https://github.com/Whitecat18/Mavoc/assets/96696929/73f6ca44-5047-4540-815a-5e2a5c8535a7.png" height="80"/>
<br>
<img src="https://github.com/Whitecat18/Mavoc/assets/96696929/2cfc423b-517d-488e-8757-407565c0e7bb.png" height="150"/>
<br>

```
Tip: use Direct method or My Fav Part, use the Rubber Ducky or ATTINITY85 Digispark to execute the payload or bind the payload string to any know software or programs to os modules to exec it .   
```
Demo Video

Please Visit <b> <a href="https://www.smukx.site/tool-walkthrough/mavoc-tool-walkthrough" > Mavoc Documentation </a></b> for Demo Videos .



### Using Powershell Bible.

Powershell bible consists of 20+ Advance attcking and Enumeration commands that will execute at 
mavoc-shell at tmux shell .

Some scripts are not added because it can be unfair to execute such scripts agaist user .The Scripts are in the Test Mode and will be added once its compactable with all windows Machines . Powershell bible is only For Windows Operating Systems . 

Powershell bible is only For Windows Operating Systems .  use `ps bible` to load powershell modules 

after getting connection from the victim . Execute `ps bible` . Type `help` for more info .  


<img src="https://github.com/Whitecat18/Mavoc/assets/96696929/7e979ea2-0fdf-4a85-b7c2-a3b152fa2d94.png" height="250"/>

Ps bible can be used to Deliver the powershell scripts to perform actions . 

For Example if you need to see the installed Applications on victim pc . you can drop a powershell script . just type the `list exe apps` to list it . 

<img src="https://github.com/Whitecat18/Mavoc/assets/96696929/fd1ddacc-7d21-406c-9e30-b68847372c9f.png" height="250"/>

**Tip : There is an Nice Trick to get the admin shell by using get admin shell command .**

<img src="https://github.com/Whitecat18/Mavoc/assets/96696929/c25b934f-027a-4871-ae69-6781403b6cfc.png" height="250"/>

Copy the above scirpt and paste in the mavoc-shell (ie) tmux shell . Executing this will send an UAC Access Permission ;)

<img src="https://github.com/Whitecat18/Mavoc/assets/96696929/8ce5ab07-aedb-4b5b-b5d4-07b2351338fb.png" height="250"/>

If an Allows means . then you will get an (Admin reverse shell) 👿

This is an bit hard . cuz many people wont allow it . you can use the send msg box to send a social Engineer msges to victim ;) . ie i got one of my teacher's (Admin shell) like that ;)

<img src="https://github.com/Whitecat18/Mavoc/assets/96696929/db98923e-3d63-4c50-8e3d-944340c72729.png" height="150"/>

you can check if you got an admin shell by executing check if admin on ps bible. 

<img src="https://github.com/Whitecat18/Mavoc/assets/96696929/07f0ed6f-b53c-40d4-9e25-e0bb797ce413.png" height="150"/>

<br>

Demo Video ....

Please Visit <b> <a href="https://www.smukx.site/tool-walkthrough/mavoc-tool-walkthrough" > Mavoc Documentation </a></b> for Demo Videos .


## How to Copy an text from Mavoc-Shell (ie) Tmux terminal  !  

For Step By Step Process . Please Visit this Blog where they Explain step by step <b><a href="https://www.fosslinux.com/105809/tmux-copy-paste-mode-tips-and-tricks-for-productivity.htm#:~:text=Once%20you%20have%20selected%20the,text%20you%20want%20to%20paste" > Tmux Blog </a></b>

Just an Referrence ...

* Enter Copy Mode: Press Ctrl + b (the default tmux prefix) followed by [ to enter copy mode. This is similar to scrolling mode and allows you to navigate and select text.
* Navigate and Select Text: Once you're in copy mode, you can use the arrow keys, Page Up, Page Down, and other navigation keys to move around and select the text you want to copy. To start selecting, move the cursor to the beginning of the text you want to copy.
* Begin Selection: Press Space to start selecting text. Move the cursor to highlight the desired text.
* Copy Text: After selecting the text, press Enter to copy the selected text to the clipboard.
* Exit Copy Mode: Press q to exit copy mode. You'll be back in the normal tmux session.
* Paste Text: You can now paste the copied text outside the tmux session using the usual paste command for your terminal emulator (usually Ctrl + Shift + v or right-click and select "Paste").


