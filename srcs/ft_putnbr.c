/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:52:03 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/01 23:23:29 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	pnbr(int n, size_t *size)
{
	if (n >= 10)
		pnbr(n / 10, size);
	*size = *size + 1;
	write(1, &"0123456789"[n % 10], 1);
}

size_t	ft_putnbr(int n)
{
	size_t	size;

	size = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	else if (n < 0)
	{
		size++;
		write(1, "-", 1);
		n = -n;
	}
	pnbr(n, &size);
	return (size);
}
