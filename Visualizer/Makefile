# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agabrie <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/09 11:09:43 by agabrie           #+#    #+#              #
#    Updated: 2018/08/09 12:11:09 by agabrie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = visualizer.a

VNAME = ../viz.out

GCC = gcc -Wall -Werror -Wextra

SRC = output.c setup.c

LIBFT = ../libft/libft.a

OBJ = $(SRC:.c=.o)

$(NAME):
	$(GCC) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

vcompile: re
	$(GCC) visualizer.c $(NAME) $(LIBFT) -o $(VNAME)

all: $(NAME)

clean:
	/bin/rm -rf $(OBJ)

libclean:
	/bin/rm -rf $(NAME)

vclean:
	/bin/rm -rf $(VNAME)

fclean: clean libclean

allclean: clean libclean vclean

re: allclean all

viz: vcompile libclean
