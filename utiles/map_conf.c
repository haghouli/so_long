/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_conf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 07:51:45 by haghouli          #+#    #+#             */
/*   Updated: 2023/01/07 17:05:01 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	is_valid_element(char c)
{
	if (c == 'C' || c == 'E' || c == '0' || c == '1' || c == 'P')
		return (1);
	return (0);
}

int	check_elements(char **graph)
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
			{
				ft_printf("The map can be composed of only\
these 5 characters : {0 1 C E P}\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_elements_count(char **graph)
{
	int	i;
	int	j;
	int	count_c;
	int	count_p_e;

	i = -1;
	count_c = 0;
	count_p_e = 0;
	while (graph[++i])
	{
		j = -1;
		while (graph[i][++j])
		{
			if (graph[i][j] == 'C')
				count_c++;
			else if (graph[i][j] == 'P')
				count_p_e++;
			else if (graph[i][j] == 'E')
				count_p_e++;
		}
	}
	if (count_c > 0 && count_p_e == 2)
		return (1);
	ft_printf("The map must contain 1 exit, at least 1\
	collectible, and 1 starting position.\n");
	return (0);
}

int	is_wall_open(char *str)
{
	while (*str)
	{
		if (*str != '1')
		{
			ft_printf("The map must be closed/surrounded by walls.\n");
			return (1);
		}
		str++;
	}
	return (0);
}

int	is_map_error(char **graph)
{
	int		i;
	size_t	len;

	len = ft_strlen(graph[0]);
	i = 0;
	while (graph[i])
	{
		if (len != ft_strlen(graph[i]))
		{
			ft_printf("The map must be rectangular.\n");
			return (1);
		}
		if (i == 0 && is_wall_open(graph[i]))
			return (1);
		if (graph[i][0] != '1' || graph[i][ft_strlen(graph[i]) - 1] != '1')
		{
			ft_printf("The map must be closed/surrounded by walls.\n");
			return (1);
		}
		if (graph[i + 1] == NULL && is_wall_open(graph[i]))
			return (1);
		i++;
	}
	return (0);
}
