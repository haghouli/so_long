/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:44:29 by haghouli          #+#    #+#             */
/*   Updated: 2022/10/15 15:09:38 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (s == 0)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (i < ft_strlen(s))
		write(fd, &s[i++], 1);
	return ((int)i);
}
