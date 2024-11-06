/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:42:41 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/05 17:19:05 by afpachec         ###   ########.fr       */
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

static void	process_sign(char **str, char **str2, t_flags *flags, int n)
{
	if (flags && (flags->plus || flags->space))
	{
		if (n >= 0 && flags->plus)
			*str2 = ft_strjoin("+", *str);
		else if (n >= 0 && flags->space)
			*str2 = ft_strjoin(" ", *str);
		free(*str);
		*str = *str2;
	}
}

int	ft_putu(unsigned int n, t_flags *flags)
{
	char	*str2;
	int		ret;
	char	*str;

	str2 = ft_uitoa(n);
	if (!str2)
		return (-1);
	str = str2;
	if (flags && (flags->plus || flags->space))
		flags->width--;
	ret = process_zeroes(&str, &str2, flags);
	if (ret == -1)
		return (-1);
	process_sign(&str, &str2, flags, n);
	set_all_zero_and_pass_dash_and_width(flags);
	ret = ft_putstr(str, flags);
	free(str);
	return (ret);
}
