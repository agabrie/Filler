/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabrie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 08:32:41 by agabrie           #+#    #+#             */
/*   Updated: 2018/08/09 09:08:59 by agabrie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	check_player(char *line, t_player *player, int n)
{
	player->chr = ((line[10] == n + '0') ? P1 : P2);
}

void	ft_puttrim_fd(t_token *piece)
{
	int x;
	int y;

	y = piece->offset.y;
	ft_putchar_fd('\n', 2);
	while (y <= piece->trim.y)
	{
		x = piece->offset.x;
		while (x <= piece->trim.x)
		{
			ft_putchar_fd(piece->data[y][x], 2);
			x++;
		}
		ft_putchar_fd('\n', 2);
		y++;
	}
}

int		var(t_game *g)
{
	return (ft_root(g->map.area, 2) / 3);
}

void	init_game(t_game *g)
{
	g->goals = ft_memalloc(sizeof(t_point) * NUM_GOALS);
	g->map.num_goals = 0;
	g->counter = 0;
	g->i = 0;
	g->line = malloc(1000);
	*g->line = malloc(1000);
	get_next_line(0, g->line);
	check_player(*g->line, &g->map.player, 1);
	check_player(*g->line, &g->map.enemy, 2);
	get_token_size(&g->map, M);
	setgoals(g);
}
