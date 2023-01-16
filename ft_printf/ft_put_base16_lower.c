/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_base16_lower.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:55:21 by haghouli          #+#    #+#             */
/*   Updated: 2022/11/02 22:02:19 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_put_base16_lower(unsigned long nbr)
{
	if (nbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (nbr < 16)
	{
		if (nbr < 10)
			ft_putchar_fd(nbr + '0', 1);
		else
			ft_putchar_fd((nbr + 87), 1);
	}
	else
	{
		ft_put_base16_lower(nbr / 16);
		ft_put_base16_lower(nbr % 16);
	}
	return (ft_count_ubase(nbr, 16));
}
