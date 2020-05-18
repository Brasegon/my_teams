##
## EPITECH PROJECT, 2020
## NWP_myteams_2019 [WSL: Debian]
## File description:
## Makefile
##

CC	= gcc

RM	= rm -f

CFLAGS = -I ./client/include/
CFLAGS += -Wall -Wextra

all: launch

launch:
	 make -C serveur/
	 cp serveur/myteams_server .
	#  make -C client/
	#  cp serveur/myteams_cli .

clean:
	make clean -C serveur/
	# make clean -C client/

fclean: clean
	make fclean -C serveur/
	# make fclean -C client/
	rm myteams_server
	# rm myteams_cli

re: fclean all

.PHONY: all clean fclean re
