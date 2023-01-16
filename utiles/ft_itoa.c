/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:20:13 by haghouli          #+#    #+#             */
/*   Updated: 2022/12/25 13:34:15 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	count(int n)
{
	size_t	counter;

	counter = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}

static void	rev(char *str, int len)
{
	int		i;
	char	mem;

	i = 0;
	while (i < len / 2)
	{
		mem = str[i];
		str[i] = str[((len - i) - 1)];
		str[((len - i) - 1)] = mem;
		i++;
	}
}

static char	*if_is_zero(char *str)
{
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

static char	*fill(char *str, int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		str[i++] = '-';
		n = n * -1;
	}
	while (n != 0)
	{
		str[i++] = n % 10 + '0';
		n /= 10;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;
	size_t	size_to_alloc;

	if (n == (-2147483648))
		return (ft_strdup("-2147483648"));
	i = 0;
	if (n >= 0)
		size_to_alloc = count(n) + 1;
	else
		size_to_alloc = count(n) + 2;
	str = (char *)malloc(size_to_alloc * sizeof(char));
	if (!str)
		return (0);
	if (n == 0)
		return (if_is_zero(str));
	str = fill(str, n);
	if (n < 0)
		rev(str + 1, count(n));
	else
		rev(str, count(n));
	return (str);
}
