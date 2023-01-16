/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:57:48 by haghouli          #+#    #+#             */
/*   Updated: 2022/11/02 21:59:37 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_base(int nbr, int base)
{
	int	count;

	count = 0;
	if (nbr < 0)
		count++;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		count++;
		nbr /= base;
	}
	return (count);
}
