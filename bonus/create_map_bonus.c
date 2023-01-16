/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:38:59 by haghouli          #+#    #+#             */
/*   Updated: 2023/01/01 08:33:03 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	fill_image(t_data *data, int k, int j)
{
	if (j == 0 && k == 0)
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->imgs->board, j * 60, k * 60);
	else if (data->graph[k][j] == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->imgs->wall, j * 60, k * 60);
	else if (data->graph[k][j] == 'P')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->imgs->pers, j * 60, k * 60);
	else if (data->graph[k][j] == '0')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->imgs->back, j * 60, k * 60);
	else if (data->graph[k][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->imgs->collect, j * 60, k * 60);
	else if (data->graph[k][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->imgs->door, j * 60, k * 60);
	else if (data->graph[k][j] == 'T')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->imgs->enemy, j * 60, k * 60);
}

void	create_map_bonus(t_data *data)
{
	int	j;
	int	k;

	k = -1;
	while (data->graph[++k])
	{
		j = -1;
		while (data->graph[k][++j])
			fill_image(data, k, j);
	}
}
