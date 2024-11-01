/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:00:21 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/01 23:23:52 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	ft_putstr(char *str)
{
	if (!str)
		return (ft_putstr("(null)"));
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}
