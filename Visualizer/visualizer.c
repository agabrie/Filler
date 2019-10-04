/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabrie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 13:48:00 by agabrie           #+#    #+#             */
/*   Updated: 2018/08/09 12:19:56 by agabrie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int		main(int ac, char **av)
{
	char	**line;
	t_play	p1;
	t_play	p2;
	t_board	board;

	line = malloc(1000);
	*line = malloc(1000);
	if (ac < 2 || ac > 3)
		return (0);
	ft_putstr_fd(TOP, 2);
	ft_putstr_fd(CLR, 2);
	while ((get_next_line(0, line)) > 0)
	{
		if (read_player(*line, &p1, &p2, av))
			continue ;
		if (output(&board, line, &p1, &p2))
			continue ;
		if (output_scores(*line, &p1, &p2))
			continue ;
	}
	output_winner(&p1, &p2);
	return (0);
}
