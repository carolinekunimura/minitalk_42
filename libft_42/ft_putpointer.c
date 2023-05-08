/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:51:09 by ckunimur          #+#    #+#             */
/*   Updated: 2023/05/08 14:15:28 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putpointer(unsigned long int ptr)
{
	int	count;

	count = 0;
	if (!ptr)
	{
		count += write (1, "(nil)", 5);
		return (count);
	}
	else
	{
		count = write (1, "0x", 2);
		count += ft_puthexa(ptr, 'x');
	}
	return (count);
}
