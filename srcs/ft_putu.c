/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:42:41 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/02 17:35:17 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putu(unsigned int n, t_flags *flags)
{
	char	*str;
	int		ret;

	(void)flags;
	str = ft_uitoa(n);
	ret = -1;
	if (str)
		ret = ft_putstr(str, NULL);
	free(str);
	return (ret);
}
