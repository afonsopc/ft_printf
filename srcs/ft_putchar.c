/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:00:21 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/05 23:45:25 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putchar(char c, t_flags *flags)
{
	int	ret;

	ret = 1;
	while (!flags->dash && (flags->width - 1) > 0)
	{
		if (write(1, " ", 1) < 0)
			return (-1);
		ret++;
		flags->width--;
	}
	if (write(1, &c, 1) < 0)
		return (-1);
	while (flags->dash && (flags->width - 1) > 0)
	{
		if (write(1, " ", 1) < 0)
			return (-1);
		ret++;
		flags->width--;
	}
	return (ret);
}
