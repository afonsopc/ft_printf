/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:52:03 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/04 23:49:58 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_puthex(unsigned long n, int upper, t_flags *flags)
{
	char	*hex;
	char	*str;
	int		ret;
	char	*str2;

	hex = "0123456789abcdef";
	if (upper)
		hex = "0123456789ABCDEF";
	ret = -1;
	str = ft_uitohexa(n, hex);
	if (!str)
		return (-1);
	if (flags && flags->alt && n)
	{
		if (upper)
			str2 = ft_strjoin("0X", str);
		else
			str2 = ft_strjoin("0x", str);
		free(str);
		str = str2;
	}
	ret = ft_putstr(str, NULL);
	free(str);
	return (ret);
}
