/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:03:47 by ckunimur          #+#    #+#             */
/*   Updated: 2023/05/08 14:15:06 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunsigned(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr <= 9)
		return (ft_putchar(nbr + 48));
	else
	{
		count += ft_putunsigned(nbr / 10);
		count += ft_putchar((nbr % 10) + 48);
	}
	return (count);
}
