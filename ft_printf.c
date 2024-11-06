/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:58:56 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/01 23:50:51 by afpachec         ###   ########.fr       */
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

static ssize_t	process_sign(ssize_t *printed, const char **sign, va_list *args)
{
	ssize_t	ret;

	if (!match((*sign)[1], "cspdiuxX%"))
		(*sign)++;
	else
	{
		ret = ft_convert_and_put(args, ((*sign)++)[1]);
		if (ret < 0)
			return (-1);
		*printed += ret;
	}
	return (0);
}

ssize_t	ft_printf(const char *format, ...)
{
	va_list	args;
	ssize_t	printed;

	if (!format)
		return (-1);
	printed = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (process_sign(&printed, &format, &args) < 0)
				return (-1);
			printed--;
		}
		else
			if (write(1, format, 1) < 0)
				return (-1);
		printed++;
		format++;
	}
	return (printed);
}
