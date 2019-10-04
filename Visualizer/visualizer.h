/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabrie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 11:48:15 by agabrie           #+#    #+#             */
/*   Updated: 2018/08/09 11:57:07 by agabrie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H
# include "../libft/libft.h"
# define OUT 2
# define CENTRE "\033[30;30f"
# define CLR "\033[2J"
# define TOP "\033[0;0f"

typedef struct	s_play
{
	char	*colour;
	char	*name;
	char	chr;
	int		score;
}				t_play;

typedef struct	s_board
{
	int		h_size;
	int		v_size;
	char	**data;
}				t_board;

void			output_names(t_play *p1, t_play *p2);
void			output_board(t_board *map, t_play *p1, t_play *p2, t_point *t);
int				output(t_board *board, char **line, t_play *p1, t_play *p2);
int				output_scores(char *line, t_play *p1, t_play *p2);
void			output_winner(t_play *p1, t_play *p2);
void			check_colour(t_play *p, char *str);
void			read_board(t_board *board);
void			set_player(t_play *p, char *line, char *av);
int				read_player(char *line, t_play *p1, t_play *p2, char **av);
void			set_board(t_board *board, char **line);
#endif
