/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_Ubase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:57:37 by haghouli          #+#    #+#             */
/*   Updated: 2022/11/02 22:00:56 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_ubase(unsigned long nbr, int base)
{
	int	count;

	count = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		count++;
		nbr /= base;
	}
	return (count);
}
