NAME	= myteams_server

CC	= gcc

RM	= rm -f

SRCS	= ./main.c \
	  ./src/client.c \
	  ./src/commands/create.c \
	  ./src/commands/use.c \
	  ./src/commands/create_teams.c \
	  ./src/commands/create_channel.c \
	  ./src/commands/login.c \
	  ./src/commands/logout.c \
	  ./src/commands.c \
	  ./src/server.c \
	  ./src/utils/my_str_to_word_array.c \
	  ./src/utils/my_str_to_word_array_utils.c \
	  ./src/commands/send.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS) ../libs/myteams/libmyteams.so -luuid

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
