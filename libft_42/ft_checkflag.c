/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkflag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 23:16:29 by ckunimur          #+#    #+#             */
/*   Updated: 2022/11/10 17:26:21 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checkflag(char flag, va_list list)
{
	if (flag == 'c')
		return (ft_putchar(va_arg(list, int)));
	else if (flag == 's')
		return (ft_putstr(va_arg(list, char *)));
	else if (flag == 'p')
		return (ft_putpointer(va_arg(list, unsigned long int)));
	else if (flag == 'd' || flag == 'i')
		return (ft_putint(va_arg(list, int)));
	else if (flag == 'u')
		return (ft_putunsigned(va_arg(list, unsigned int)));
	else if (flag == 'x' || flag == 'X')
		return (ft_puthexa(va_arg(list, unsigned int), flag));
	else
		return (ft_putchar('%'));
}
