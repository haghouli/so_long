/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stuck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:37:20 by haghouli          #+#    #+#             */
/*   Updated: 2023/01/02 05:43:30 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free(char **tab, char **graph)
{
	int	i;

	i = 0;
	while (i < count_col(graph))
		free(tab[i++]);
	free(tab);
}

static char	**make_area(char **zone, t_dim *size)
{
	char	**new;
	int		i;
	int		j;

	i = 0;
	new = malloc(sizeof(char *) * size->y);
	while (i < size->y)
	{
		j = 0;
		new[i] = malloc(size->x + 1);
		while (j < size->x)
		{
			new[i][j] = zone[i][j];
			j++;
		}
		new[i][size->x] = '\0';
		i++;
	}
	return (new);
}

static int	fill(char **tab, t_dim *size, t_dim *begin, char c)
{
	int static	check;
	int static	count;

	if (begin->y < 0 || begin->y >= size->y || begin->x < 0
		|| begin->x >= size->x || (tab[begin->y][begin->x] != c
		&& tab[begin->y][begin->x] != 'E'
		&& tab[begin->y][begin->x] != '0' && tab[begin->y][begin->x] != 'C'))
		return (0);
	if (tab[begin->y][begin->x] == 'E')
	{
		if (check == 0)
			check = 1;
		return (0);
	}
	if (tab[begin->y][begin->x] == 'C')
		count++;
	tab[begin->y][begin->x] = '@';
	fill(tab, size, &((t_dim){begin->x - 1, begin->y}), c);
	fill(tab, size, &((t_dim){begin->x + 1, begin->y}), c);
	fill(tab, size, &((t_dim){begin->x, begin->y - 1}), c);
	fill(tab, size, &((t_dim){begin->x, begin->y + 1}), c);
	return (count + check);
}

int	check_stuck(char **graph, t_dim *size, t_dim *begin)
{
	char	**tab;
	int		counter;

	tab = make_area(graph, size);
	counter = fill(tab, size, begin, tab[begin->y][begin->x]);
	return (ft_free(tab, graph), counter);
}
