SERVER_SRCS	=	srcs/server.c

CLIENT_SRCS	=	srcs/client.c

UTILS_SRCS	=	srcs/utils.c srcs/utils_print.c

SERVER_OBJS		=	$(SERVER_SRCS:.c=.o)

CLIENT_OBJS		=	$(CLIENT_SRCS:.c=.o)

UTILS_OBJS		=	$(UTILS_SRCS:.c=.o)

OBJS			=	$(SERVER_OBJS) $(CLIENT_OBJS) $(UTILS_OBJS)

CC			=	gcc

RM			=	rm -f

CFLAGS		= 	-Wall -Wextra -Werror -I./includes


SERVER_NAME	= 	server

CLIENT_NAME	= 	client


all:		$(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME): 	$(OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(UTILS_SRCS:.c=.o) -o $(SERVER_NAME) 

$(CLIENT_NAME): 	$(OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(UTILS_SRCS:.c=.o) -o $(CLIENT_NAME) 

bonus: all

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(SERVER_NAME)
	$(RM) $(CLIENT_NAME)

re:		fclean all

.PHONY:		all clean fclean re bonus

