/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berpinhe <berpinhe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 02:00:21 by berpinhe          #+#    #+#             */
/*   Updated: 2026/11/18 18:32:02 by berpinhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_c(int c)
{
	return (write(1, &c, 1));
}

int	ft_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_dig(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n = -n;
		count += ft_c('-');
	}
	if (n >= 10)
		count += ft_dig(n / 10);
	return (ft_c('0' + (n % 10)) + count);
}

int	ft_ptr(void *ptr)
{
	if (!ptr)
		return (ft_str("(nil)"));
	return (ft_str("0x") + ft_hex((unsigned long)ptr, 'p'));
}

int	ft_hex(unsigned long n, char flag)
{
	int	count;

	count = 0;
	if (flag == 'p' || flag == 'x')
	{
		if (n >= 16)
			count += ft_hex(n / 16, 'x');
		count += write(1, &"0123456789abcdef"[n % 16], 1);
	}
	else if (flag == 'X')
	{
		if (n >= 16)
			count += ft_hex(n / 16, 'X');
		count += write(1, &"0123456789ABCDEF"[n % 16], 1);
	}
	return (count);
}
