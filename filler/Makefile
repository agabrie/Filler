# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agabrie <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/09 11:23:02 by agabrie           #+#    #+#              #
#    Updated: 2018/08/09 14:33:03 by agabrie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler.a

BOT = ../players/Alec.filler

GCC = gcc -Wall -Werror -Wextra

SRC = algorithms.c tokens.c extra.c place.c

LIBFT = ../libft/libft.a

OBJ = $(SRC:.c=.o)

$(NAME):
	@$(GCC) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "library [$(NAME)] created"

fcompile: 
	@make re -C ../libft
	@echo "library [libft.a] created"
	@$(GCC) filler.c $(NAME) $(LIBFT) -o $(BOT)
	@echo "player [$(BOT)] created"

all: $(NAME)

clean:
	@/bin/rm -rf $(OBJ)
	@echo "objects [$(OBJ)] removed"

libclean:
	@/bin/rm -rf $(NAME)
	@echo "library [$(NAME)] removed"

fillclean:
	@/bin/rm -rf $(PLAYERS)$(BOT)
	@echo "player [$(BOT) removed]"

fclean: clean libclean

allclean: clean libclean fillclean
	make allclean -C ../libft
	make allclean -C ../Visualizer

re: allclean all fill libclean

fill: fcompile libclean

viz:
	make viz -C ../Visualizer
