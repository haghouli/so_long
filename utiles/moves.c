/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:14:45 by haghouli          #+#    #+#             */
/*   Updated: 2023/01/07 17:10:31 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	move_vertical(t_data *data, int *counter, int *c, int i)
{
	if (data->graph[(data->dim->x) + i][data->dim->y] == '1'
		|| data->graph[(data->dim->x) + i][data->dim->y] == 'E')
	{
		if ((data->graph[(data->dim->x) + i][data->dim->y] == 'E'
			&& *counter == 0))
		{
			ft_printf("Game Ovrer\n");
			exit(0);
		}
	}
	else
	{
		if (data->graph[(data->dim->x) + i][data->dim->y] == 'E'
			&& *counter == 0)
			exit(0);
		if (data->graph[(data->dim->x) + i][data->dim->y] == 'C')
			(*counter)--;
		data->graph[(data->dim->x) + i][data->dim->y] = 'P';
		data->graph[data->dim->x][data->dim->y] = '0';
		data->dim->x = (data->dim->x) + i;
		mlx_clear_window(data->mlx, data->mlx_win);
		ft_printf("%d\n", (*c)++);
		create_map(data);
	}
	return (1);
}

int	move_horizontal(t_data *data, int *counter, int *c, int i)
{
	if (data->graph[data->dim->x][(data->dim->y) + i] == '1'
		|| data->graph[data->dim->x][(data->dim->y) + i] == 'E')
	{
		if ((data->graph[data->dim->x][(data->dim->y) + i] == 'E'
			&& *counter == 0))
		{
			ft_printf("Game Over\n");
			exit(0);
		}
	}
	else
	{
		if (data->graph[data->dim->x][(data->dim->y) + i] == 'E'
			&& *counter == 0)
			exit(0);
		if (data->graph[data->dim->x][(data->dim->y) + i] == 'C')
			(*counter)--;
		data->graph[data->dim->x][(data->dim->y) + i] = 'P';
		data->graph[data->dim->x][data->dim->y] = '0';
		data->dim->y = (data->dim->y) + i;
		mlx_clear_window(data->mlx, data->mlx_win);
		ft_printf("%d\n", (*c)++);
		create_map(data);
	}
	return (1);
}
