/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:40:30 by haghouli          #+#    #+#             */
/*   Updated: 2023/01/10 11:14:25 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_block(char c)
{
	if (c == '1' || c == 'E' || c == 'T')
		return (1);
	return (0);
}

void	p1(t_data *data, int *c)
{
	char	*str;

	mlx_clear_window(data->mlx, data->mlx_win);
	create_map_bonus(data);
	str = ft_itoa(++(*c));
	mlx_string_put(data->mlx, data->mlx_win, 20, 20, 0xFF000000, str);
	free(str);
	data->counter = *c;
}

int	move_vertical_bonus(t_data *data, int *counter, int *c, int i)
{
	if (check_block(data->graph[(data->dim->x) + i][data->dim->y]))
	{
		if ((data->graph[(data->dim->x) + i][data->dim->y] == 'E'
			&& *counter == 0) || data->graph[(data->dim->x)
			+ i][data->dim->y] == 'T')
			exit(0);
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
		p1(data, c);
	}
	return (1);
}

int	move_horizontal_bonus(t_data *data, int *counter, int *c, int i)
{
	if (check_block(data->graph[data->dim->x][(data->dim->y) + i]))
	{
		if ((data->graph[data->dim->x][(data->dim->y) + i] == 'E'
			&& *counter == 0) || data->graph[data->dim->x][(data->dim->y)
			+ i] == 'T')
			exit(0);
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
		p1(data, c);
	}
	return (1);
}
