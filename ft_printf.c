/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepinhei <bepinhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 09:23:19 by bepinhei          #+#    #+#             */
/*   Updated: 2024/08/12 13:09:38 by bepinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(char c, va_list args)
{
	int	result;

	result = 0;
	if (!c)
		return (0);
	else if (c == 'c')
		result += ft_putchar(va_arg(args, int));
	else if (c == 's')
		result += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		result += ft_putptr(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		result += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		result += ft_putnbr_char(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		result += ft_putnbr_hex(va_arg(args, unsigned int), c);
	else if (c == '%')
		result += write(1, "%", 1);
	return (result);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		result;

	va_start(args, str);
	result = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '%')
			result += ft_format(*(++str), args);
		else
			result += write(1, str, 1);
		++str;
	}
	va_end(args);
	return (result);
}