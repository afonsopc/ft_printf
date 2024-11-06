/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:52:03 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/05 17:58:46 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*zero_string(int amount)
{
	char	*zeroes;

	zeroes = malloc(amount + 1);
	if (!zeroes)
		return (NULL);
	ft_memset(zeroes, '0', amount);
	zeroes[amount] = '\0';
	return (zeroes);
}

static int	process_zeroes(char **str, char **str2, t_flags *flags)
{
	char	*zeroes;
	int		width;

	if (flags && flags->dot && flags->length > (int)ft_strlen(*str))
		width = flags->length;
	else if (flags && flags->zero && flags->width > (int)ft_strlen(*str))
		width = flags->width;
	else
		return (0);
	zeroes = zero_string(width - ft_strlen(*str));
	if (!zeroes)
	{
		free(*str2);
		return (-1);
	}
	*str = ft_strjoin(zeroes, *str);
	free(zeroes);
	free(*str2);
	return (0);
}

int	ft_puthex(unsigned long n, int force_alt, int upper, t_flags *flags)
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
	if (flags && ((flags->alt && n) || force_alt))
	{
		if (upper)
			str2 = ft_strjoin("0X", str);
		else
			str2 = ft_strjoin("0x", str);
		free(str);
		str = str2;
	}
	str2 = str;
	if (process_zeroes(&str, &str2, flags) < 0)
		return (-1);
	set_all_zero_and_pass_dash_and_width(flags);
	ret = ft_putstr(str, flags);
	free(str);
	return (ret);
}
