/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_enemy_near.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 10:36:07 by haghouli          #+#    #+#             */
/*   Updated: 2023/01/11 05:37:41 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_near_enemy(t_data *data)
{
	if (data->graph[data->dim->x][data->dim->y - 1] == 'T')
	{
		ft_printf("Unplayable game\n");
		return (0);
	}
	return (1);
}
