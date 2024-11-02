/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:57:14 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/02 00:12:47 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

ssize_t	ft_putu(unsigned int n);
ssize_t	ft_putptr(unsigned long n, int upper);
ssize_t	ft_convert_and_put(va_list *args, const char sign);
ssize_t	ft_putchar(char c);
ssize_t	ft_puthex(unsigned long n, int upper);
ssize_t	ft_strlen(const char *s);
ssize_t	ft_putnbr(int n);
ssize_t	ft_putstr(char *str);
ssize_t	ft_printf(const char *format, ...);

#endif