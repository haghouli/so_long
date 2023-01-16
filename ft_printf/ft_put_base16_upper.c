/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_base16_upper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:55:57 by haghouli          #+#    #+#             */
/*   Updated: 2022/11/02 22:04:08 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_put_base16_upper(unsigned int nbr)
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
			ft_putchar_fd((nbr + 55), 1);
	}
	else
	{
		ft_put_base16_upper(nbr / 16);
		ft_put_base16_upper(nbr % 16);
	}
	return (ft_count_ubase(nbr, 16));
}
