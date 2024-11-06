/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:04:23 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/01 23:36:03 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

ssize_t	ft_strlen(const char *s)
{
	ssize_t	counter;

	counter = 0;
	while (s[counter])
		counter++;
	return (counter);
}
