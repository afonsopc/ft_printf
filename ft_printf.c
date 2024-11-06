/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:58:56 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/03 00:06:24 by afpachec         ###   ########.fr       */
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

static int	parse_flags(const char *percentage, t_flags *flags)
{
	int	i;

	i = 1;
	if (match(percentage[i], "-0"))
	{
		if (percentage[i] == '-')
			flags->dash = 1;
		else if (percentage[i] == '0')
			flags->zero = 1;
		flags->width = ft_atoi(&percentage[i + 1]);
		i += ft_strlen(ft_itoa(flags->width)) + 1;
	}
	if (percentage[i] == '.')
	{
		flags->dot = 1;
		flags->precision = ft_atoi(&percentage[i + 1]);
		i += ft_strlen(ft_itoa(flags->precision)) + 1;
	}
	return (i);
}

static int	process_sign(int *printed, const char **sign, va_list *args)
{
	int		ret;
	t_flags	*flags;

	flags = new_flags();
	if (!flags)
		return (-1);
	if (match((*sign)[1], "-0."))
		*sign += parse_flags(*sign, flags) - 1;
	(*sign)++;
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

/* #include <limits.h>

int main(void)
{
	printf("\n\nReturns: ft: %d | printf: %d\n",
	ft_printf(" %d ", INT_MIN), printf(" %d ", INT_MIN));
	printf(
		"\n\nReturns: ft: %d | printf: %d\n",
		ft_printf(" %d %d %d %d %d %d %d\n\n\n", 
		INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42), 
		printf(" %d %d %ld %ld %ld %d %d\n\n\n", 
		INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42)
	);
}
 */