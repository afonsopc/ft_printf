/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:00:21 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/02 17:35:21 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putstr(char *str, t_flags *flags)
{
	size_t	str_len;
	int		ret;

	if (!str)
		return (ft_putstr("(null)", NULL));
	str_len = ft_strlen(str);
	if (flags && flags->dot == 1 && flags->precision < str_len)
		str_len = flags->precision;
	ret = write(1, str, str_len);
	if (ret < 0)
		return (-1);
	if (flags && flags->dash == 1 && flags->width > str_len)
	{
		while (flags->width-- > str_len)
		{
			ret = write(1, " ", 1);
			if (ret < 0)
				return (-1);
		}
	}
	return (str_len);
}
