/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:00:21 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/05 22:35:02 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	put_lspaces(int str_len, t_flags *flags)
{
	int	width;
	int	count;

	width = 0;
	count = 0;
	if (flags && !flags->dash && flags->width > str_len)
	{
		while (width++ < flags->width - str_len)
			if (++count && write(1, " ", 1) < 0)
				return (-1);
	}
	return (count);
}

static int	put_rspaces(int str_len, t_flags *flags)
{
	int	width;
	int	count;

	width = 0;
	count = 0;
	if (flags && flags->dash && flags->width > str_len)
	{
		while (width++ < flags->width - str_len)
			if (++count && write(1, " ", 1) < 0)
				return (-1);
	}
	return (count);
}

int	ft_putstr(char *str, t_flags *flags)
{
	int	str_len;
	int	ret1;
	int	ret2;
	int	ret3;

	if (!str)
		str = "(null)";
	str_len = ft_strlen(str);
	if (flags && flags->dot && flags->length < str_len)
		str_len = flags->length;
	ret1 = put_lspaces(str_len, flags);
	if (ret1 < 0)
		return (-1);
	ret2 = write(1, str, str_len);
	if (ret2 < 0)
		return (-1);
	ret3 = put_rspaces(str_len, flags);
	if (ret3 < 0)
		return (-1);

	return (ret1 + str_len + ret3);
}
