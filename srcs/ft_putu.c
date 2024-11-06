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

#include "../ft_printf.h"

static ssize_t	pu(unsigned int n, ssize_t *size)
{
	if (n >= 10 && pu(n / 10, size) < 0)
		return (-1);
	*size = *size + 1;
	return (write(1, &"0123456789"[n % 10], 1));
}

ssize_t	ft_putu(unsigned int n)
{
	ssize_t	size;

	size = 0;
	if (pu(n, &size) < 0)
		return (-1);
	return (size);
}
