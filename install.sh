#!/usr/bin/bash

echo -e "\e[1;32m
╔╦╗┌─┐┬  ┬┌─┐┌─┐  ╦┌┐┌┌─┐┌┬┐┌─┐┬  ┬  ┌─┐┌┬┐┬┌─┐┌┐┌
║║║├─┤└┐┌┘│ ││    ║│││└─┐ │ ├─┤│  │  ├─┤ │ ││ ││││
╩ ╩┴ ┴ └┘ └─┘└─┘  ╩┘└┘└─┘ ┴ ┴ ┴┴─┘┴─┘┴ ┴ ┴ ┴└─┘┘└┘
				  	mavoc.inc
\e[0m"

echo -e "\e[1;32mIn case if any anyerros while working with mavoc . Run installer script Again \e[0m"

#----Installing Dependencies----#
echo -e "\e[1;31mInstalling Dependencies\e[0m"

sudo apt update
sudo apt install libcurl4-openssl-dev xterm net-tools tmux gnome-terminal python3 python3-pip -y
pip3 install -r bin/python-exin/requirements.txt

#----Configure Files-----#
echo
echo
echo
echo -e "\e[1;33mConfiguring Files ...\e[0m"

rm -r ~/.ssh
rm bin/authorized_keys

ssh-keygen -t rsa -N "" -f ~/.ssh/id_rsa
cp ~/.ssh/id_rsa.pub bin/authorized_keys

echo 
echo
echo -e "\e[1;32mFiles configured Successfully\e[0m"

# Compiling Programs
echo -e "\e[1;31mCompiling ...\e[0m"

g++ mavoc-main.cpp -lcurl -o mavoc
g++ psw-bible.cpp -o psw-bible
g++ mavoc-exin.cpp -o mavoc-exin
unzip bin/python-exin.zip
unzip bin/python-exin/mavoc-req.zip
chmod +x bin/python-exin/mavoc-exin.py
chmod +x bin/server
chmod +x server/server
chmod +x scroll
chmod +x server.py

./files/loading

echo -e "\e[1;32mSuccessfully Installed Mavoc\e[0m"

echo -e "\e[1;34mIncase If you face any while working with mavoc . Run fix-mavoc.sh\e[0m"

echo -e "\e[1;36mRun ./mavoc to get started\e[0m"

