/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepinhei <bepinhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 09:23:30 by bepinhei          #+#    #+#             */
/*   Updated: 2024/08/12 13:04:07 by bepinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int i)
{
	int result;
	int nbr;
	int divisor;
	int digito;

	divisor = 1;
	result = 0;

	if(i == -2147483648)
	{
		result += write(1, "-2147483648", 11);
		return (result);
	}
	if (i == 0)
    {
        result += ft_putchar('0');
        return (result);
    }
	if (i < 0)
	{
		result += ft_putchar('-');
		i = -i ;
	}
	nbr = i;
	while (nbr >= 10)
	{
		nbr /= 10;
		divisor *= 10;
	}
	while (divisor > 0)
	{
		digito = i/divisor + '0';
		ft_putchar(digito);
		i %= divisor;
		divisor /= 10;
		result++;
	}
	return (result);
}