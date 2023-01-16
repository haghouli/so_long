/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_start_dim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 05:47:50 by haghouli          #+#    #+#             */
/*   Updated: 2023/01/02 05:30:20 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_start_dim(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (data->graph == NULL)
		return ;
	while (data->graph[i])
	{
		j = 0;
		while (data->graph[i][j])
		{
			if (data->graph[i][j] == 'P')
			{
				data->dim->x = i;
				data->dim->y = j;
			}
			j++;
		}
		i++;
	}
}
