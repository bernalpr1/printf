/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berpinhe <berpinhe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 01:21:02 by berpinhe          #+#    #+#             */
/*   Updated: 2026/11/18 18:54:42 by berpinhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(char const *s, ...);
int	ft_dig(long n);
int	ft_c(int c);
int	ft_str(char *str);
int	ft_ptr(void *ptr);
int	ft_hex(unsigned long n, char flag);

#endif
