# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agabrie <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/09 14:35:10 by agabrie           #+#    #+#              #
#    Updated: 2018/08/09 14:41:17 by agabrie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@make all -C filler

re:
	@make re -C filler

clean:
	@make clean -C filler

fclean:
	@make fclean -C filler

fcompile:
	@make fcompile -C filler

libclean:
	@make libclean -C filler

fillclean:
	@make fillclean -C filler

allclean:
	@make allclean -C filler

fill:
	@make fill -C filler

viz:
	@make viz -C filler
