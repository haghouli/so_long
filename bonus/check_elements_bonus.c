/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 05:33:50 by haghouli          #+#    #+#             */
/*   Updated: 2023/01/01 08:00:47 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	is_valid_element(char c)
{
	if (c == 'C' || c == 'E' || c == '0' || c == '1' || c == 'P' || c == 'T')
		return (1);
	return (0);
}

int	check_elements_bonus(char **graph)
{
	int	i;
	int	j;

	i = 0;
	while (graph[i])
	{
		j = 0;
		while (graph[i][j])
		{
			if (!is_valid_element(graph[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
