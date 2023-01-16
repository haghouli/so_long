/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:55:32 by haghouli          #+#    #+#             */
/*   Updated: 2022/12/28 15:56:24 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_collectors(t_data *data)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (data->graph[i])
	{
		j = 0;
		while (data->graph[i][j])
		{
			if (data->graph[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	count_col(char **graph)
{
	int	count;

	count = 0;
	while (*graph)
	{
		count++;
		graph++;
	}
	return (count);
}
