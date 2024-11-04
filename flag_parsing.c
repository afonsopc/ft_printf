/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 20:20:24 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/04 19:12:07 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ailen(char *str)
{
	int	i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}

static int	process_flags(char *str, t_flags *flags)
{
	int	is_flag;
	int	i;

	i = 0;
	is_flag = 1;
	while (is_flag)
	{
		if (str[i] == '-')
			flags->dash = 1;
		else if (str[i] == '0')
			flags->zero = 1;
		else if (str[i] == '#')
			flags->alt = 1;
		else if (str[i] == '+')
			flags->plus = 1;
		else if (str[i] == ' ')
			flags->space = 1;
		else
			is_flag = 0;
		if (str[i] == '-' || str[i] == '0'
			|| str[i] == '#' || str[i] == '+' || str[i] == ' ')
			i++;
	}
	return (i);
}

static int	process_width(char *str, t_flags *flags)
{
	int	width;

	width = ft_atoi(str);
	if (width < 0)
	{
		flags->dash = 1;
		flags->width = -width;
	}
	else
		flags->width = width;
	return (ailen(str));
}

static int	process_length(char *str, t_flags *flags)
{
	flags->length = ft_atoi(str);
	return (ailen(str));
}

int	parse_flags(char *str, t_flags *flags)
{
	int	i;

	i = process_flags(str, flags);
	i += process_width(str + i, flags);
	if (str[i] == '.')
	{
		flags->dot = 1;
		i++;
		i += process_length(str + i, flags);
	}
	return (i);
}
