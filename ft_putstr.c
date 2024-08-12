/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepinhei <bepinhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 09:23:34 by bepinhei          #+#    #+#             */
/*   Updated: 2024/08/12 10:58:10 by bepinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if(!str)
		return (write (1, "(null)", 6));
	while (*str)
	{
		i += ft_putchar(*str);
		str ++;
	}
	return(i);
}
