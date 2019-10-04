/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabrie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 08:23:03 by agabrie           #+#    #+#             */
/*   Updated: 2018/08/09 09:24:43 by agabrie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	clear_token(t_token *token)
{
	int	i;

	i = 0;
	while (i < token->v_size)
		ft_strdel(&token->data[i++]);
	ft_strdel(token->data);
}

void	read_token(t_token *t, int skip)
{
	int		i;
	char	**line;
	char	*str;

	line = malloc(1000);
	*line = malloc(1000);
	i = 0;
	if (!t->type)
		get_next_line(0, line);
	while (i < t->v_size)
	{
		get_next_line(0, line);
		str = ft_strndup(*line + skip, t->h_size);
		ft_strdel(&t->data[i]);
		t->data[i] = ft_strndup(str, t->h_size);
		i++;
	}
	ft_strdel(line);
	free(line);
}

void	get_token_size(t_token *t, int type)
{
	char	**info;
	char	**line;

	line = malloc(1000);
	*line = malloc(1000);
	get_next_line(0, line);
	t->type = type;
	info = ft_strsplit(*line, ' ');
	t->v_size = ft_atoi(info[1]);
	t->h_size = ft_atoi(info[2]);
	t->area = t->v_size * t->h_size;
	t->data = (char **)ft_memalloc(sizeof(char*) * t->v_size + 1);
	ft_strdel(line);
	free(line);
}

void	trim_token(t_token *piece)
{
	int i;
	int j;

	i = 0;
	piece->offset.x = piece->h_size;
	piece->offset.y = piece->v_size;
	piece->trim.x = 0;
	piece->trim.y = 0;
	while (i < piece->v_size)
	{
		j = 0;
		while (j < piece->h_size)
		{
			if (piece->data[i][j] == '*')
			{
				if (i < piece->offset.y)
					(piece->offset.y = i);
				if (i > piece->trim.y)
					(piece->trim.y = i);
				if (j < piece->offset.x)
					(piece->offset.x = j);
				if (j > piece->trim.x)
					(piece->trim.x = j);
			}
			j++;
		}
		i++;
	}
}

void	update_map(t_token *map)
{
	char	**line;

	line = malloc(1000);
	*line = malloc(1000);
	read_token(map, 4);
	ft_strdel(line);
	free(line);
	get_coords(map->data, &map->enemy);
}
