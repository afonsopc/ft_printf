/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:52:03 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/02 17:43:28 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_puthex(unsigned long n, int upper, t_flags *flags)
{
	char	*hex;
	char	*str;
	int		ret;

	(void)flags;
	hex = "0123456789abcdef";
	if (upper)
		hex = "0123456789ABCDEF";
	ret = -1;
	str = ft_uitohexa(n, hex);
	if (str)
		ret = ft_putstr(str, NULL);
	free(str);
	return (ret);
}
