/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:58:56 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/01 23:24:42 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	match(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	printed;

	if (!format)
		return (-1);
	printed = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (!match(format[1], "cspdiuxX%"))
				format++;
			else
				printed += ft_convert_and_put(&args, (format++)[1]);
			printed--;
		}
		else
			write(1, format, 1);
		printed++;
		format++;
	}
	return (printed);
}
