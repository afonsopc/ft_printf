/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:52:03 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/01 23:35:17 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static ssize_t	phex(unsigned long n, char *base, ssize_t *size)
{
	if (n >= 16 && phex(n / 16, base, size) < 0)
		return (-1);
	*size = *size + 1;
	return (write(1, &base[n % 16], 1));
}

ssize_t	ft_puthex(unsigned long n, int upper)
{
	ssize_t	size;
	char	*hex;

	size = 0;
	hex = "0123456789abcdef";
	if (upper)
		hex = "0123456789ABCDEF";
	if (phex(n, hex, &size) < 0)
		return (-1);
	return (size);
}
