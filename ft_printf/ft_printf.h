/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:54:31 by haghouli          #+#    #+#             */
/*   Updated: 2022/11/02 23:15:45 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_put_base16_upper(unsigned int nbr);
int		ft_put_base16_lower(unsigned long nbr);
int		ft_putunbr_fd(unsigned long n);
size_t	ft_strlen(const char *s);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_count_base(unsigned long nbr, int base);
int		ft_count_ubase(unsigned long nbr, int base);

#endif
