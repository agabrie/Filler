/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabrie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 08:20:08 by agabrie           #+#    #+#             */
/*   Updated: 2018/08/09 13:21:33 by agabrie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	quarterfill(t_point *goals, t_token *map, t_point centre)
{
	goals[0] = centre;
	goals[3] = set_point(map->v_size * 1 / 4, map->h_size * 1 / 4);
	goals[2] = set_point(map->v_size * 3 / 4, map->h_size * 3 / 4);
	goals[1] = set_point(map->v_size * 3 / 4, map->h_size * 1 / 4);
	if (enemy_quad(map, &centre) == 3)
		goals[3] = set_point(map->v_size * 1 / 4, map->h_size * 3 / 4);
	map->num_goals = 3;
}

void	quarters(t_point *goals, t_token *map)
{
	goals[0] = set_point(map->v_size / 2, 0);
	goals[1] = set_point(0, map->h_size / 2);
	goals[2] = set_point(map->v_size / 2, map->h_size);
	goals[3] = set_point(map->v_size, map->h_size / 2);
	if (map->player.chr == 'O' && map->area < 5000)
	{
		goals[2] = set_point(0, map->h_size / 2);
		goals[1] = set_point(map->v_size / 2, map->h_size);
		goals[3] = set_point(map->v_size, map->h_size / 2);
	}
	if (map->player.chr == 'X' && map->area >= 5000)
	{
		goals[0] = set_point(map->v_size / 2, map->h_size);
		goals[1] = set_point(map->v_size, map->h_size / 2);
		goals[2] = set_point(0, map->h_size / 2);
		goals[3] = set_point(map->v_size / 2, 0);
	}
	map->num_goals = 3;
}

void	diags(t_point *goals, t_token *map)
{
	t_point start;
	t_point end;

	start = set_point(0, 0);
	end = set_point(map->v_size, map->h_size);
	goals[0] = start;
	goals[1] = end;
	goals[2] = set_point(end.y, start.x);
	goals[3] = set_point(start.y, end.x);
	map->num_goals = 3;
}

void	isolate(t_point *goals, t_token *map, t_point *centre)
{
	goals[2] = *centre;
	if (enemy_quad(map, centre) == 1)
	{
		goals[0] = set_point(map->v_size / 2, 0);
		goals[1] = set_point(0, map->h_size / 2);
	}
	if (enemy_quad(map, centre) == 2)
	{
		goals[0] = set_point(map->v_size / 2, map->h_size);
		goals[1] = set_point(0, map->h_size / 2);
	}
	if (enemy_quad(map, centre) == 3)
	{
		goals[0] = set_point(map->v_size / 2, 0);
		goals[1] = set_point(map->v_size, map->h_size / 2);
	}
	if (enemy_quad(map, centre) == 4)
	{
		goals[0] = set_point(map->v_size / 2, map->h_size);
		goals[1] = set_point(map->v_size, map->h_size / 2);
	}
	map->num_goals = 2;
}

void	spider(t_point *goals, t_token *map)
{
	t_point start;
	t_point edge;
	t_point centre;

	centre = set_point(map->v_size / 2, map->h_size / 2);
	start = set_point(0, 0);
	edge = set_point(map->v_size, map->h_size);
	goals[0] = centre;
	goals[4] = set_point(edge.y, 0);
	goals[3] = edge;
	goals[2] = set_point(0, edge.x);
	goals[1] = start;
	goals[5] = set_point(centre.y, edge.x);
	goals[6] = set_point(centre.y, 0);
	goals[7] = set_point(edge.y, centre.x);
	goals[8] = set_point(0, centre.x);
	map->num_goals = 8;
}
