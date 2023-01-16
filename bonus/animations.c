/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:42:12 by haghouli          #+#    #+#             */
/*   Updated: 2023/01/10 10:25:57 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_left(t_data *data, t_list *tmp)
{
	if (data->graph[tmp->x][tmp->y - 1] == 'P')
	{
		ft_printf("Game Over\n");
		exit(0);
	}
	else if (data->graph[tmp->x][tmp->y - 1] == 'C'
			|| data->graph[tmp->x][tmp->y - 1] == 'T'
			|| data->graph[tmp->x][tmp->y - 1] == 'E'
			|| data->graph[tmp->x][tmp->y - 1] == '1')
	{
		tmp->b = 0;
	}
	else
	{
		data->graph[tmp->x][tmp->y - 1] = 'T';
		data->graph[tmp->x][tmp->y] = '0';
		tmp->y = tmp->y - 1;
	}
}

void	move_right(t_data *data, t_list *tmp)
{
	if (data->graph[tmp->x][tmp->y + 1] == 'P')
	{
		ft_printf("Game Over\n");
		exit(0);
	}
	else if (data->graph[tmp->x][tmp->y + 1] == 'C'
			|| data->graph[tmp->x][tmp->y + 1] == 'T'
			|| data->graph[tmp->x][tmp->y + 1] == 'E'
			|| data->graph[tmp->x][tmp->y + 1] == '1')
	{
		tmp->b = 1;
	}
	else
	{
		data->graph[tmp->x][tmp->y + 1] = 'T';
		data->graph[tmp->x][tmp->y] = '0';
		tmp->y = tmp->y + 1;
	}
}

void	enemy_patrol(t_data *data)
{
	int static	g;
	char		*str;
	t_list		*tmp;

	tmp = data->enemies_pos;
	if (g == 301)
		g = 0;
	if (g == 300)
	{
		while (tmp)
		{
			if (tmp->b == 0)
				move_right(data, tmp);
			if (tmp->b == 1)
				move_left(data, tmp);
			tmp = tmp->next;
		}
		create_map_bonus(data);
		str = ft_itoa(data->counter);
		mlx_string_put(data->mlx, data->mlx_win, 20, 20, 0xFF000000, str);
		free(str);
	}
	g++;
}

void	change_image(t_data *data, void *anime)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->imgs->back,
		data->dim->y * 60, data->dim->x * 60);
	mlx_put_image_to_window(data->mlx, data->mlx_win, anime, data->dim->y * 60,
		data->dim->x * 60);
}

int	animation(t_data *data)
{
	int			t;
	int static	i;
	void		*anime1;
	void		*anime2;

	anime1 = mlx_xpm_file_to_image(data->mlx, "./textures/peranim.xpm", &t, &t);
	anime2 = mlx_xpm_file_to_image(data->mlx, "./textures/anime2.xpm", &t, &t);
	if (!anime1 || !anime2)
	{
		ft_printf("Error\n");
		exit(0);
	}
	if (i == 301)
		i = 0;
	if (i == 100)
		change_image(data, data->imgs->pers);
	if (i == 200)
		change_image(data, anime1);
	if (i == 300)
		change_image(data, anime2);
	i++;
	enemy_patrol(data);
	return (1);
}
