/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabrie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 13:48:00 by agabrie           #+#    #+#             */
/*   Updated: 2019/10/04 15:00:26 by agabrie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"
#include <stdio.h>
void	output_names(t_play *p1, t_play *p2)
{
	ft_putstr_fd(TOP, OUT);
	ft_putstr_fd("Player 1: ", OUT);
	col_endl_fd(p1->colour, p1->name, OUT);
	if (p2->chr == 'X')
	{
		ft_putstr_fd("Player 2: ", OUT);
		col_endl_fd(p2->colour, p2->name, OUT);
	}
}

void	output_board(t_board *map, t_play *p1, t_play *p2, t_point *t)
{
	int i;
	int j;

	i = t->y;
	j = t->x;
	// printf("%c", map->data[i][j]);
		// printf("%c", map->data[i][j]);
	if (map->data[i][j] == p1->chr || map->data[i][j] == p1->chr + 32)
		col_str_fd(p1->colour, "██", OUT);
	else if ((map->data[i][j] == p2->chr || map->data[i][j] == p2->chr + 32))
		col_str_fd(p2->colour, "██", OUT);
	else
		col_str_fd(FWHT, "[]", OUT);
}

int		output(t_board *board, char **line, t_play *p1, t_play *p2)
{
	t_point i;

	i = set_point(0, 0);
	if (ft_strnequ(*line, "Plateau", 7))
	{
		i.y = 0;
		set_board(board, line);
		output_names(p1, p2);
		while (i.y < board->v_size)
		{
			i.x = 0;
			while (i.x < board->h_size)
			{
				output_board(board, p1, p2, &i);
				i.x++;
			}
			ft_putchar_fd('\n', OUT);
			i.y++;
		}
		ft_putchar_fd('\n', OUT);
		return (1);
	}
	return (0);
}

int		output_scores(char *line, t_play *p1, t_play *p2)
{
	if (ft_strnequ(line, "==", 1))
	{
		if (ft_conchar(line, 'O'))
			p1->score = ft_atoi(line + 10);
		else if (ft_conchar(line, 'X'))
			p2->score = ft_atoi(line + 10);
		ft_putendl_fd(line, OUT);
		return (1);
	}
	return (0);
}

void	output_winner(t_play *p1, t_play *p2)
{
	int diff;

	diff = p1->score - p2->score;
	if (diff)
	{
		ft_putstr_fd("Winner : ", OUT);
		if (diff > 0)
		{
			col_str_fd(p1->colour, p1->name, OUT);
			ft_putstr_fd(" By ", 1);
			col_str_fd(p1->colour, ft_itoa(diff), OUT);
		}
		else
		{
			col_str_fd(p2->colour, p2->name, OUT);
			ft_putstr_fd(" By ", OUT);
			col_str_fd(p2->colour, ft_itoa(-diff), OUT);
		}
		ft_putendl_fd(" placements!!!", OUT);
	}
	else
		ft_putendl_fd("TIED", OUT);
}
