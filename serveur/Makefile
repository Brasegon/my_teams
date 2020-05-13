NAME	= myteams_server

CC	= gcc

RM	= rm -f

SRCS	= ./main.c \
	  ./src/client.c \
	  ./src/commands/login.c \
	  ./src/commands/logout.c \
	  ./src/commands.c \
	  ./src/server.c \
	  ./src/test.c 

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS) libmyteams.so -luuid

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
