/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepinhei <bepinhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 09:11:59 by bepinhei          #+#    #+#             */
/*   Updated: 2024/08/11 09:12:33 by bepinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int	ft_printf(const char *, ...);
int	ft_putnbr(int nbr);
int	ft_putnbr_char(unsigned int n);
int	ft_putnbr_hex(unsigned int n, char format);
int	ft_putchar(char c);
int	ft_putstr(char *str);

#endif