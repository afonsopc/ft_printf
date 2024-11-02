/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 00:11:00 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/02 00:13:18 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

ssize_t	ft_putptr(unsigned long n, int upper)
{
	ssize_t	size;

	if (ft_putstr("0x") < 0)
		return (-1);
	size = ft_puthex(n, upper);
	if (size < 0)
		return (-1);
	return (size + 2);
}
