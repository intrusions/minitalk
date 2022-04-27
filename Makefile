SERVER_SRCS	=	srcs/server.c

CLIENT_SRCS	=	srcs/client.c

UTILS_SRCS	=	srcs/utils.c srcs/utils_print.c

OBJS		=	$(SERVER_SRCS:.c=.o) $(CLIENT_SRCS:.c=.o) $(UTILS_SRCS:.c=.o)

CC			=	gcc

RM			=	rm -f

CFLAGS		= 	-Wall -Wextra -Werror -I./includes

NAME		= 	minitalk

SERVER_NAME	= 	server

CLIENT_NAME	= 	client

all:		$(NAME)

$(NAME): 	$(OBJS)
	$(CC) $(CFLAGS) $(SERVER_SRCS) $(UTILS_SRCS) -o $(SERVER_NAME) 
	$(CC) $(CFLAGS) $(CLIENT_SRCS) $(UTILS_SRCS) -o $(CLIENT_NAME) 

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(SERVER_NAME)
	$(RM) $(CLIENT_NAME)

re:		fclean $(NAME)

.PHONY:		all clean fclean re bonus