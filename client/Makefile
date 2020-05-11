##
## EPITECH PROJECT, 2020
## NWP_myteams_2019 [WSL: Debian]
## File description:
## Makefile
##

NAME	= myteams_cli

CC	= gcc

RM	= rm -f

SRCS	= ./main.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
