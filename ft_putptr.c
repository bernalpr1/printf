/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepinhei <bepinhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 09:23:32 by bepinhei          #+#    #+#             */
/*   Updated: 2024/08/12 12:51:18 by bepinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex_ptr(unsigned long n)
{
	int		result;
	char	*base;
	unsigned long	divisor;
	char	digit;

	result = 0;
	base = "0123456789abcdef";
	divisor = 1;

	while (n / divisor >= 16)
		divisor *= 16;

	while (divisor > 0)
	{
		digit = base[(n / divisor) % 16];
		result += ft_putchar(digit);
		divisor /= 16;
	}

	return (result);
}

int	ft_putptr(void *ptr)
{
	int	result;
	if(!ptr)
		return(write(1 ,"(nil)", 5));
	write(1, "0x", 2);
	result = 2;
	result += ft_putnbr_hex_ptr((unsigned long)ptr);
	return(result);
}
