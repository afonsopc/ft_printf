/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:42:41 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/01 23:32:23 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pu(unsigned int n, int *size)
{
	if (n >= 10 && pu(n / 10, size) < 0)
		return (-1);
	*size = *size + 1;
	return (write(1, &"0123456789"[n % 10], 1));
}

int	ft_putu(unsigned int n)
{
	int	size;

	size = 0;
	if (pu(n, &size) < 0)
		return (-1);
	return (size);
}

int	ft_putnbr(int n)
{
	int				size;
	unsigned int	un;

	size = 0;
	un = n;
	if (n < 0)
	{
		un = -n;
		size++;
		if (write(1, "-", 1) < 0)
			return (-1);
	}
	if (pu(un, &size) < 0)
		return (-1);
	return (size);
}

int	ft_putstr(char *str)
{
	if (!str)
		return (ft_putstr("(null)"));
	return (write(1, str, ft_strlen(str)));
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}
