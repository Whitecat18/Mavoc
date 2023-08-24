GREEN="\e[1;32m"
RED="\e[1;31m"
RESET="\e[0m"

echo -e "${GREEN}Terminating Process Please Wait..${RESET}"

ser_if=$(pgrep -f server.py)
if [ -n "$ser_if" ]; then
    kill $ser_if
fi

pkill tmux
pkill server

echo -e "${GREEN}DONE !${RESET}"
