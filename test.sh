clear
export MESSAGE=$1
make re
alias client='./client $(pidof server)'
terminator --layout 'New Layout'
#terminator -e ./server & terminator -e 'echo  ./client $(pidof server) > /dev/stdin'
#tmux\
#	new-session './server ; bash' \; \
#	split-window './client $(pidof server) $MESSAGE; bash'

