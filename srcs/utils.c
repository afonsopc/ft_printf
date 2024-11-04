/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:54:20 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/04 22:49:57 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_itoa(int n)
{
	size_t			i;
	char			str[12];
	unsigned int	nb;

	nb = n;
	if (n < 0)
		nb = -n;
	str[11] = '\0';
	i = 10;
	while (nb >= 10)
	{
		str[i] = "0123456789"[nb % 10];
		nb /= 10;
		i--;
	}
	str[i] = "0123456789"[nb % 10];
	return (ft_strdup(&str[i]));
}

int	ft_atoi(const char *str)
{
	int	num;

	num = 0;
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*str - '0');
		str++;
	}
	return (num);
}

char	*ft_uitoa(unsigned int n)
{
	size_t	i;
	char	str[11];

	str[10] = '\0';
	i = 9;
	while (n >= 10)
	{
		str[i] = "0123456789"[n % 10];
		n /= 10;
		i--;
	}
	str[i] = "0123456789"[n % 10];
	return (ft_strdup(&str[i]));
}

char	*ft_uitohexa(unsigned long n, char *hex)
{
	size_t	i;
	char	str[17];

	str[16] = '\0';
	i = 15;
	while (n >= 16)
	{
		str[i] = hex[n % 16];
		n /= 16;
		i--;
	}
	str[i] = hex[n % 16];
	return (ft_strdup(&str[i]));
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
