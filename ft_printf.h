/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:57:14 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/01 22:29:12 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

size_t	ft_putu(unsigned int n);
size_t	ft_convert_and_put(va_list *args, const char sign);
size_t	ft_putchar(char c);
size_t	ft_puthex(unsigned long n, int upper);
size_t	ft_strlen(const char *s);
size_t	ft_putnbr(int n);
size_t	ft_putstr(char *str);
int		ft_printf(const char *format, ...);

#endif