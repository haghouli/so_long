/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 22:04:52 by haghouli          #+#    #+#             */
/*   Updated: 2022/11/02 22:10:03 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putunbr_fd(unsigned long n)
{
	if (n >= 0 && n < 10)
		ft_putchar_fd((n + '0'), 1);
	else
	{
		ft_putunbr_fd(n / 10);
		ft_putunbr_fd(n % 10);
	}
	return (ft_count_ubase(n, 10));
}
