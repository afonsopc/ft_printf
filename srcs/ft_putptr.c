/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 00:11:00 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/02 17:42:42 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putptr(void *n, t_flags *flags)
{
	int	ret1;
	int	ret2;

	(void)flags;
	ret1 = ft_putstr("0x", NULL);
	if (ret1 < 0)
		return (ret1);
	ret2 = ft_puthex((uintptr_t)n, 0, NULL);
	if (ret2 < 0)
		return (ret2);
	return (ret1 + ret2);
}
