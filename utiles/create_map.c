/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:31:51 by haghouli          #+#    #+#             */
/*   Updated: 2023/01/01 08:36:54 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	fill_images(t_data *data, int k, int j)
{
	if (data->graph[k][j] == '1')
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
}

void	create_map(t_data *data)
{
	int	j;
	int	k;

	k = -1;
	while (data->graph[++k])
	{
		j = -1;
		while (data->graph[k][++j])
			fill_images(data, k, j);
	}
}
