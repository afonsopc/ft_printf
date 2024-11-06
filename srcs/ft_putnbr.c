/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:52:03 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/01 23:34:20 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static ssize_t	pnbr(int n, ssize_t *size)
{
	if (n >= 10 && pnbr(n / 10, size) < 0)
		return (-1);
	*size = *size + 1;
	return (write(1, &"0123456789"[n % 10], 1));
}

ssize_t	ft_putnbr(int n)
{
	ssize_t	size;

	size = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	else if (n < 0)
	{
		size++;
		if (write(1, "-", 1) < 0)
			return (-1);
		n = -n;
	}
	if (pnbr(n, &size) < 0)
		return (-1);
	return (size);
}
