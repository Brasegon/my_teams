##
## EPITECH PROJECT, 2020
## NWP_myteams_2019 [WSL: Debian]
## File description:
## Makefile
##

NAME	= myteams_cli

CC	= gcc

RM	= rm -f

SRCS	= ./main.c \
			./input.c \
			./commands/log.c \
			./commands.c \
			./init.c \
			../common/my_str_to_word_array.c \
	  		../common/my_str_to_word_array_utils.c \
			./rfc/login_client.c \
			./rfc/rfc2.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	#  $(CC) $(OBJS) -o $(NAME) $(LDFLAGS) ../libs/myteams/libmyteams.so
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
