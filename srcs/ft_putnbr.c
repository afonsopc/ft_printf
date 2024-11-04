/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:52:03 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/04 23:04:41 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr(int n, t_flags *flags)
{
	char	*str2;
	int		ret;
	char	*zeroes;
	char	*str;

	str2 = ft_itoa(n);
	if (!str2)
		return (-1);
	str = str2;
	if (flags && (flags->plus || flags->space || n < 0))
		flags->width--;
	if (flags && flags->zero && flags->width > (int)ft_strlen(str))
	{
		zeroes = malloc(flags->width - ft_strlen(str) + 1);
		if (!zeroes)
		{
			free(str2);
			return (-1);
		}
		ft_memset(zeroes, '0', flags->width - ft_strlen(str));
		zeroes[flags->width - ft_strlen(str)] = '\0';
		str = ft_strjoin(zeroes, str2);
		free(zeroes);
		free(str2);
	}
	if (flags && (flags->plus || flags->space || n < 0))
	{
		if (n >= 0 && flags->plus)
			str2 = ft_strjoin("+", str);
		else if (n < 0 || (flags->plus && n < 0))
			str2 = ft_strjoin("-", str);
		else if (n >= 0 && flags->space)
			str2 = ft_strjoin(" ", str);
		free(str);
		str = str2;
	}
	ret = ft_putstr(str, NULL);
	free(str);
	return (ret);
}
