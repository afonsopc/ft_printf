/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:58:56 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/06 14:22:22 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_and_put(va_list *args, char sign)
{
	if (sign == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (sign == 'd' || sign == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (sign == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (sign == 'p')
		return (ft_putptr(va_arg(*args, void *), 0));
	else if (sign == 'u')
		return (ft_putu(va_arg(*args, unsigned int)));
	else if (sign == 'x')
		return (ft_puthex(va_arg(*args, unsigned int), 0));
	else if (sign == 'X')
		return (ft_puthex(va_arg(*args, unsigned int), 1));
	else if (sign == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_strlen(const char *s)
{
	int	counter;

	counter = 0;
	while (s[counter])
		counter++;
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		printed;
	int		ret;

	if (!format)
		return (-1);
	printed = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			ret = ft_convert_and_put(&args, *++format);
		else
			ret = ft_putchar(*format);
		if (ret < 0)
		{
			va_end(args);
			return (-1);
		}
		printed += ret;
		format++;
	}
	va_end(args);
	return (printed);
}

/* int main()
{
	int a = ft_printf("%s\n\n", "pagman");
	int b = printf("%s\n\n", "pagman");

	printf("%d | %d\n", a, b);
} */