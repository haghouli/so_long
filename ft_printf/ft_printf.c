/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:55:04 by haghouli          #+#    #+#             */
/*   Updated: 2022/11/02 22:07:36 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	print_arg(const char *str, va_list ptr, int *count)
{
	if (*(str + 1) == 'c')
		*count += ft_putchar_fd((va_arg(ptr, int)), 1);
	else if (*(str + 1) == 's')
		*count += ft_putstr_fd(va_arg(ptr, char *), 1);
	else if ((*(str + 1) == 'd' || *(str + 1) == 'i'))
		*count += ft_putnbr_fd(va_arg(ptr, int), 1);
	else if (*(str + 1) == 'X')
		*count += ft_put_base16_upper(va_arg(ptr, unsigned int));
	else if (*(str + 1) == 'x')
		*count += ft_put_base16_lower(va_arg(ptr, unsigned int));
	else if (*(str + 1) == 'u')
		*count += ft_putunbr_fd(va_arg(ptr, unsigned int));
	else if (*(str + 1) == 'p')
	{
		write(1, "0x", 2);
		*count += 2;
		*count += ft_put_base16_lower(va_arg(ptr, unsigned long));
	}
	else if (*(str + 1) == '%')
		*count += ft_putchar_fd('%', 1);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		count;

	count = 0;
	va_start(ptr, str);
	while (*str)
	{
		if (*str == '%')
		{
			print_arg(str, ptr, &count);
			str++;
		}
		else
		{
			ft_putchar_fd(*str, 1);
			count++;
		}
		str++;
	}
	return (count);
}
