/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 00:11:00 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/05 22:48:21 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putptr(void *n, t_flags *flags)
{
	set_all_zero_and_pass_dash_and_width(flags);
	return (ft_puthex((unsigned long)n, 1, 0, flags));
}
