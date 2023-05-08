/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 00:10:06 by ckunimur          #+#    #+#             */
/*   Updated: 2023/05/08 14:15:57 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putint(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count += ft_putchar('-');
		count += ft_putchar('2');
		count += ft_putint(147483648);
	}
	else if (n < 0)
	{
		count += ft_putchar('-');
		count += ft_putint(-1 * n);
	}
	else if (n <= 9)
		count += ft_putchar(n + 48);
	else if (n > 9)
	{
		count += ft_putint(n / 10);
		count += ft_putchar((n % 10) + 48);
	}
	return (count);
}
