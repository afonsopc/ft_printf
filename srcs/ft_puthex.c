/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:52:03 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/01 22:28:46 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	phex(unsigned long n, char *base, size_t *size)
{
	if (n >= 16)
		phex(n / 16, base, size);
	*size = *size + 1;
	write(1, &base[n % 16], 1);
}

size_t	ft_puthex(unsigned long n, int upper)
{
	size_t	size;
	char	*hex;

	size = 0;
	hex = "0123456789abcdef";
	if (upper)
		hex = "0123456789ABCDEF";
	phex(n, hex, &size);
	return (size);
}
