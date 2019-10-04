/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabrie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 13:48:00 by agabrie           #+#    #+#             */
/*   Updated: 2018/08/09 13:56:40 by agabrie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	check_colour(t_play *p, char *str)
{
	if (ft_strequ(str, "GREEN"))
		p->colour = FGRN;
	else if (ft_strequ(str, "RED"))
		p->colour = FRED;
	else if (ft_strequ(str, "YELLOW"))
		p->colour = FYEL;
	else if (ft_strequ(str, "BLUE"))
		p->colour = FBLU;
	else if (ft_strequ(str, "CYAN"))
		p->colour = FCYN;
	else if (ft_strequ(str, "MAGENTA"))
		p->colour = FMAG;
	else if (ft_strequ(str, "WHITE"))
		p->colour = FWHT;
	else if (ft_strequ(str, "BLACK"))
		p->colour = FBLK;
	else
		p->colour = FBLK;
}

void	read_board(t_board *board)
{
	int		y;
	char	**line;

	y = 0;
	line = malloc(1000);
	*line = malloc(1000);
	while (y < board->v_size)
	{
		get_next_line(0, line);
		board->data[y] = ft_strdup(*line + 4);
		y++;
	}
	ft_strdel(line);
	free(line);
}

void	set_player(t_play *p, char *line, char *av)
{
	p->name = ft_strdup(ft_dup_conchar(line, '.') + 23);
	check_colour(p, av);
	if (ft_strnequ(line, "$$$ exec p1 : [players/", 22))
		p->chr = 'O';
	else
		p->chr = 'X';
}

int		read_player(char *line, t_play *p1, t_play *p2, char **av)
{
	if (ft_strnequ(line, "#", 1) || !line)
		return (1);
	if (ft_strnequ(line, "launched players/", 16))
		return (1);
	if (ft_strnequ(line, "$$$ exec p1 : [players/", 22))
	{
		set_player(p1, line, av[1]);
		return (1);
	}
	if (ft_strnequ(line, "$$$ exec p2 : [players/", 22))
	{
		set_player(p2, line, av[2]);
		return (1);
	}
	return (0);
}

void	set_board(t_board *board, char **line)
{
	board->v_size = ft_atoi(ft_strchr(*line, ' '));
	board->h_size = ft_atoi(ft_strchr(*line + 8, ' '));
	board->data = (char**)malloc(sizeof(char *) * board->v_size + 1);
	get_next_line(0, line);
	read_board(board);
}
