/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabrie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 10:59:37 by agabrie           #+#    #+#             */
/*   Updated: 2018/08/09 08:47:31 by agabrie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				main(void)
{
	t_game	g;

	init_game(&g);
	while (1)
	{
		update_map(&g.map);
		get_token_size(&g.token, T);
		read_token(&g.token, 0);
		trim_token(&g.token);
		g.place = get_point(&g.map, &g.token, &g.goals[g.i]);
		clear_token(&g.token);
		if (g.place.x != -g.map.h_size)
		{
			put_coords_fd(&g.place, 1);
			if ((g.counter % (var(&g) + PAD) == 0))
				g.i++;
			get_next_line(0, g.line);
		}
		else
			exit(1);
		setgoals(&g);
		if (g.i > g.map.num_goals || !(g.counter % (var(&g) * 4) + PAD))
			g.i = 0;
	}
}
