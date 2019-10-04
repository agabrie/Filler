/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabrie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 08:27:59 by agabrie           #+#    #+#             */
/*   Updated: 2018/08/09 13:32:13 by agabrie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_coords(char **data, t_player *player)
{
	int x;
	int y;

	y = 0;
	while (data[y])
	{
		x = 0;
		while (data[y][x])
		{
			if (data[y][x] == player->chr)
			{
				player->start.x = x;
				player->start.y = y;
			}
			x++;
		}
		y++;
	}
}

int		check_point(t_token *brd, t_token *piece, t_point *crd)
{
	int i;
	int j;
	int ovl;

	i = 0;
	ovl = 0;
	if (((piece->trim.y - piece->offset.y + crd->y) >= brd->v_size)
			|| ((piece->trim.x - piece->offset.x + crd->x) >= brd->h_size))
		return (0);
	while (i <= (piece->trim.y - piece->offset.y))
	{
		j = 0;
		while (j <= (piece->trim.x - piece->offset.x))
		{
			if ((piece->data[piece->offset.y + i][piece->offset.x + j]) == '*')
			{
				if (brd->data[crd->y + i][crd->x + j] == brd->player.chr)
					ovl++;
				if (brd->data[crd->y + i][crd->x + j] == brd->enemy.chr)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (ovl == 1 ? 1 : 0);
}

t_point	get_point(t_token *map, t_token *t, t_point *target)
{
	t_point	val;
	int		dist;
	t_point	edge;
	t_point	end;

	val.y = -1;
	edge = set_point(map->v_size, map->h_size);
	end = set_point(-map->v_size, -map->h_size);
	dist = calc_dist(&end, &edge);
	while (val.y++ < map->v_size)
	{
		val.x = -1;
		while (val.x++ < map->h_size)
		{
			if (check_point(map, t, &val))
			{
				if (calc_dist(&val, target) <= dist)
				{
					dist = calc_dist(&val, target);
					end = set_point(val.y - t->offset.y, val.x - t->offset.x);
				}
			}
		}
	}
	return (end);
}

int		enemy_quad(t_token *map, t_point *centre)
{
	if (map->enemy.start.x <= centre->x)
	{
		if (map->enemy.start.y <= centre->y)
			return (1);
		else
			return (3);
	}
	else
	{
		if (map->enemy.start.y <= centre->y)
			return (2);
		else
			return (4);
	}
}

void	setgoals(t_game *g)
{
	t_point centre;

	centre = set_point(g->map.v_size / 2, g->map.h_size / 2);
	if (g->counter <= (var(g) + PAD) * (g->map.num_goals + 1))
	{
		if (g->map.area < 300 && g->map.player.chr == 'X')
			diags(g->goals, &g->map);
		else if (g->map.area < 5000 && g->map.player.chr == 'O')
			isolate(g->goals, &g->map, &centre);
		else
			quarters(g->goals, &g->map);
	}
	else if (g->counter <= (var(g) + PAD) * (g->map.num_goals + 1) * 2)
	{
		if (g->map.area < 300 && g->map.player.chr == 'X')
			quarters(g->goals, &g->map);
		else
			diags(g->goals, &g->map);
	}
	else if (g->counter <= (var(g) + PAD) * (g->map.num_goals + 1) * 3)
		quarterfill(g->goals, &g->map, centre);
	else
		g->counter = 0;
	g->counter++;
}
