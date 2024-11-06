/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_and_put.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:30:01 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/05 23:38:01 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_convert_and_put(va_list *args, const char sign, t_flags *flags)
{
	if (sign == 's')
		return (ft_putstr(va_arg(*args, char *), flags));
	else if (sign == 'd' || sign == 'i')
		return (ft_putnbr(va_arg(*args, int), flags));
	else if (sign == 'c')
		return (ft_putchar(va_arg(*args, int), flags));
	else if (sign == 'p')
		return (ft_putptr(va_arg(*args, void *), flags));
	else if (sign == 'u')
		return (ft_putu(va_arg(*args, unsigned int), flags));
	else if (sign == 'x')
		return (ft_puthex(va_arg(*args, unsigned int), 0, 0, flags));
	else if (sign == 'X')
		return (ft_puthex(va_arg(*args, unsigned int), 0, 1, flags));
	else if (sign == '%')
		return (ft_putchar('%', flags));
	return (-1);
}
