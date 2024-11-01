/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:42:41 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/01 22:28:54 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	pu(unsigned int n, size_t *size)
{
	if (n >= 10)
		pu(n / 10, size);
	*size = *size + 1;
	write(1, &"0123456789"[n % 10], 1);
}

size_t	ft_putu(unsigned int n)
{
	size_t	size;

	size = 0;
	pu(n, &size);
	return (size);
}
