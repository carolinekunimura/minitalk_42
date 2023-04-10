/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 00:34:26 by ckunimur          #+#    #+#             */
/*   Updated: 2022/11/10 17:28:51 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned long n, int flag)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count += ft_puthexa((n / 16), flag);
		count += ft_puthexa((n % 16), flag);
	}
	else
	{
		if (flag == 'x')
			return (ft_putchar(BASEISLOWER[n]));
		else
			return (ft_putchar(BASEISUPPER[n]));
	}
	return (count);
}
