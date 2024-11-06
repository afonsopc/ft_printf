/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:57:14 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/06 14:12:11 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_putu(unsigned int n);
int	ft_putptr(void *n, int upper);
int	ft_convert_and_put(va_list *args, const char sign);
int	ft_putchar(char c);
int	ft_puthex(unsigned long n, int upper);
int	ft_strlen(const char *s);
int	ft_putnbr(int n);
int	ft_putstr(char *str);
int	ft_printf(const char *format, ...);

#endif
