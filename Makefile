##
## EPITECH PROJECT, 2020
## NWP_myteams_2019 [WSL: Debian]
## File description:
## Makefile
##

NAME	= myteams_server

CC	= gcc

RM	= rm -f

SRCS	= ./serveur/main.c \
	  ./serveur/src/client.c \
	  ./serveur/src/commands/create.c \
	  ./serveur/src/commands/use.c \
	  ./serveur/src/commands/create_teams.c \
	  ./serveur/src/commands/create_channel.c \
	  ./serveur/src/commands/login.c \
	  ./serveur/src/commands/logout.c \
	  ./serveur/src/commands/users.c \
	  ./serveur/src/commands.c \
	  ./serveur/src/server.c \
	  ./common/my_str_to_word_array.c \
	  ./common/my_str_to_word_array_utils.c \
	  ./serveur/src/commands/send.c \
	  ./common/list.c \
	  ./common/create_list.c \
	  ./common/pop_push.c

OBJS	= $(SRCS:.c=.o)

NAME1	= myteams_cli

SRCS1	= 	./client/main.c \
			./client/input.c \
			./client/commands.c \
			./client/init.c \
			./common/my_str_to_word_array.c \
	  		./common/my_str_to_word_array_utils.c \
			./client/rfc/login_client.c \
			./client/rfc/rfc2.c \
			./client/rfc/create.c

OBJS1	= $(SRCS1:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra


all: $(NAME) $(NAME1)

$(NAME1): $(OBJS1)
	 $(CC) $(OBJS1) -o $(NAME1) $(LDFLAGS) -L./libs/myteams -lmyteams

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS) -luuid -L./libs/myteams -lmyteams

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS1)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME1)

re: fclean all

.PHONY: all clean fclean re
