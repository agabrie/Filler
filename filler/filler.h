/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabrie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 12:44:21 by agabrie           #+#    #+#             */
/*   Updated: 2018/08/09 13:10:19 by agabrie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/libft.h"
# define T 1
# define M 0
# define P1 'O'
# define P2 'X'
# define NUM_GOALS 9
# define PAD 10

typedef struct	s_player
{
	t_point	start;
	char	chr;
}				t_player;

typedef struct	s_token
{
	int			h_size;
	int			v_size;
	int			type;
	t_point		offset;
	t_point		trim;
	t_player	player;
	t_player	enemy;
	char		**data;
	int			num_goals;
	int			area;
}				t_token;

typedef struct	s_game
{
	t_token	map;
	t_token	token;
	t_point	*goals;
	t_point	place;
	int		counter;
	int		i;
	char	**line;
}				t_game;

void			quarterfill(t_point *goals, t_token *map, t_point centre);
void			quarters(t_point *goals, t_token *map);
void			diags(t_point *goals, t_token *map);
void			isolate(t_point *goals, t_token *map, t_point *centre);
void			spider(t_point *goals, t_token *map);
void			check_player(char *line, t_player *player, int n);
void			ft_puttrim_fd(t_token *piece);
int				var(t_game *g);
void			init_game(t_game *g);
void			get_coords(char **data, t_player *player);
int				check_point(t_token *brd, t_token *piece, t_point *crd);
t_point			get_point(t_token *map, t_token *t, t_point *target);
int				enemy_quad(t_token *map, t_point *centre);
void			setgoals(t_game *g);
void			clear_token(t_token *token);
void			read_token(t_token *t, int skip);
void			get_token_size(t_token *t, int type);
void			trim_token(t_token *piece);
void			update_map(t_token *map);
#endif
