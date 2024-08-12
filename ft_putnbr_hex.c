/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepinhei <bepinhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 09:23:26 by bepinhei          #+#    #+#             */
/*   Updated: 2024/08/12 10:09:08 by bepinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned int n, char format)
{
	int		result;
	char	*base;
	unsigned int	divisor;
	char	digit;

	result = 0;
	if (format == 'x')
		base = "0123456789abcdef";
	if (format == 'X')
		base = "0123456789ABCDEF";
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