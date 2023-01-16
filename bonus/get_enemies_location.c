/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_enemies_location.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 05:32:15 by haghouli          #+#    #+#             */
/*   Updated: 2023/01/10 10:27:05 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_enemies_location(t_data *data)
{
	int	i;
	int	j;

	data->enemies_pos = NULL;
	i = 0;
	while (data->graph[i])
	{
		j = 0;
		while (data->graph[i][j])
		{
			if (data->graph[i][j] == 'T')
				ft_lstadd_back(&(data->enemies_pos), ft_lstnew(i, j));
			j++;
		}
		i++;
	}
}
