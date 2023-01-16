/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 08:07:48 by haghouli          #+#    #+#             */
/*   Updated: 2023/01/11 06:47:10 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./ft_printf/ft_printf.h"
# include "./utiles/gnl/get_next_line.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				x;
	int				y;
	int				b;
	struct s_list	*next;
}					t_list;

typedef struct s_img
{
	void			*wall;
	void			*pers;
	void			*back;
	void			*collect;
	void			*door;
	void			*board;
	void			*enemy;
}					t_img;

typedef struct s_dim
{
	int				x;
	int				y;
}					t_dim;

typedef struct s_data
{
	void			*mlx;
	void			*mlx_win;
	char			**graph;
	t_dim			*dim;
	t_img			*imgs;
	int				counter;
	t_list			*enemies_pos;
}					t_data;

/********************* utiles *********************/
char				**ft_split(char const *s, char c);
void				create_map(t_data *data);
int					is_map_error(char **graph);
int					check_elements_count(char **graph);
int					check_elements(char **graph);
char				*ft_itoa(int n);
int					check_stuck(char **graph, t_dim *size, t_dim *begin);
int					animation(t_data *data);
int					count_collectors(t_data *data);
int					count_col(char **graph);
char				**read_file(int fd);
void				get_start_dim(t_data *data);
int					ft_exit(t_data *data);
int					check_nl(char *str);
int					check_extention(char *str);
int					check_near_enemy(t_data *data);

/********************* moves *********************/
int					move_vertical(t_data *data, int *counter, int *c, int i);
int					move_horizontal(t_data *data, int *counter, int *c, int i);
int					move_vertical_bonus(t_data *data, int *counter, int *c,
						int i);
int					move_horizontal_bonus(t_data *data, int *counter, int *c,
						int i);
void				create_map_bonus(t_data *data);
int					check_elements_bonus(char **graph);

t_list				*ft_lstnew(int x, int y);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				get_enemies_location(t_data *data);

#endif