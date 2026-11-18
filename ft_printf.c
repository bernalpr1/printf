/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berpinhe <berpinhe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 01:20:48 by berpinhe          #+#    #+#             */
/*   Updated: 2026/11/18 18:49:07 by berpinhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_select(va_list *args, char c);

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	if (!str)
		return (-1);
	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1))
		{
			count += ft_select(&args, *(str + 1));
			str += 2;
		}
		else
		{
			if (*str == '%')
				return (-1);
			count += write(1, str, 1);
			str++;
		}
	}
	va_end(args);
	return (count);
}

static int	ft_select(va_list *args, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_c(va_arg(*args, int));
	else if (c == 's')
		count += ft_str(va_arg(*args, char *));
	else if (c == 'p')
		count += ft_ptr(va_arg(*args, void *));
	else if (c == 'd' || c == 'i')
		count += ft_dig(va_arg(*args, int));
	else if (c == 'u')
		count += ft_dig(va_arg(*args, unsigned int));
	else if (c == 'x')
		count += ft_hex(va_arg(*args, unsigned int), c);
	else if (c == 'X')
		count += ft_hex(va_arg(*args, unsigned int), c);
	else if (c == '%')
		count += ft_c('%');
	else
		count = -1;
	return (count);
}
