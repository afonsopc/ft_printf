/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:52:56 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/05 17:52:25 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_all_zero(t_flags *flags)
{
	if (!flags)
		return ;
	flags->zero = 0;
	flags->dash = 0;
	flags->sign = 0;
	flags->dot = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->alt = 0;
	flags->width = 0;
	flags->length = 0;
}

void	set_all_zero_and_pass_dash_and_width(t_flags *flags)
{
	int	dash;
	int	width;

	if (!flags)
		return ;
	dash = flags->dash;
	width = flags->width;
	set_all_zero(flags);
	flags->dash = dash;
	flags->width = width;
}

t_flags	*new_flags(void)
{
	t_flags	*flags;

	flags = malloc(sizeof(t_flags));
	if (!flags)
		return (NULL);
	flags->zero = 0;
	flags->dash = 0;
	flags->sign = 0;
	flags->dot = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->alt = 0;
	flags->width = 0;
	flags->length = 0;
	return (flags);
}
