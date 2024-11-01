/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_and_put.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:30:01 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/01 23:26:41 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	ft_convert_and_put(va_list *args, const char sign)
{
	if (sign == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (sign == 'd' || sign == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (sign == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (sign == 'p')
		return (ft_putstr("0x") + ft_puthex(va_arg(*args, unsigned long), 0));
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
