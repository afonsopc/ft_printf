/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:58:56 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/04 16:58:22 by afpachec         ###   ########.fr       */
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

static int	process_sign(int *printed, const char **sign, va_list *args)
{
	int		ret;
	t_flags	*flags;

	flags = new_flags();
	if (!flags)
		return (-1);
	*sign += 1;
	*sign += parse_flags((char *)*sign, flags);
	if (match(**sign, "cspdiuxX%"))
	{
		ret = ft_convert_and_put(args, **sign, flags);
		if (ret < 0)
		{
			free(flags);
			return (-1);
		}
		*printed += ret;
	}
	free(flags);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		printed;

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
	va_end(args);
	return (printed);
}
