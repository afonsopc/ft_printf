/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:00:21 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/01 23:49:12 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

ssize_t	ft_putstr(char *str)
{
	if (!str)
		return (ft_putstr("(null)"));
	if (write(1, str, ft_strlen(str)) < 0)
		return (-1);
	return (ft_strlen(str));
}
