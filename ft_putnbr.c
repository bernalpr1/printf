/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepinhei <bepinhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 09:23:30 by bepinhei          #+#    #+#             */
/*   Updated: 2024/08/11 11:25:18 by bepinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int i)
{
	int result;
	int nbr;
	int c;
	int p;

	c = 1;
	nbr = i;
	result = 0;

	if(i == -2147483648)
	{
		result += write(1, "-2147483648", 11);
		return (result);
	}
	if (i < 0)
	{
		result += ft_putchar('-');
		i = i * -1;
	}
	while (nbr >= 10)
	{
		nbr = nbr / 10;
		c = c * 10;
	}
	while (i >= 10)
	{
		p = i/c + 48;
		ft_putchar(p);
		i = i % c;
		c = c / 10;
		result++;
	}
	if(i < 10)
	{
		ft_putchar(i + 48);
		result += 1;
	}
	return (result);
}