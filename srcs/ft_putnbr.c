/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:52:03 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/05 23:37:37 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*zero_string(int amount, int c)
{
	char	*zeroes;

	zeroes = malloc(amount + 1);
	if (!zeroes)
		return (NULL);
	ft_memset(zeroes, c, amount);
	zeroes[amount] = '\0';
	return (zeroes);
}

static int	process_zeroes(char **str, char **str2, t_flags *flags)
{
	char	*zeroes;
	int		width;
	char	c;

	if (flags && flags->dot && flags->length > (int)ft_strlen(*str))
		width = flags->length;
	else if (flags && flags->zero && flags->width > (int)ft_strlen(*str))
		width = flags->width;
	else
		return (0);
	c = '0';
	if (flags && flags->dot && flags->length < (int)ft_strlen(*str))
		c = ' ';
	zeroes = zero_string(width - ft_strlen(*str), c);
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
	if (flags && (flags->plus || flags->space || n < 0))
	{
		if (n >= 0 && flags->plus)
			*str2 = ft_strjoin("+", *str);
		else if (n < 0 || (flags->plus && n < 0))
			*str2 = ft_strjoin("-", *str);
		else if (n >= 0 && flags->space)
			*str2 = ft_strjoin(" ", *str);
		free(*str);
		*str = *str2;
	}
}

int	ft_putnbr(int n, t_flags *flags)
{
	char	*str2;
	int		ret;
	char	*str;

	str2 = ft_itoa(n);
	if (!str2)
		return (-1);
	str = str2;
	if (flags && (flags->plus || flags->space || n < 0))
		flags->width--;
	ret = process_zeroes(&str, &str2, flags);
	if (ret == -1)
		return (-1);
	process_sign(&str, &str2, flags, n);
	if (flags && n < 0)
		flags->width++;
	set_all_zero_and_pass_dash_and_width(flags);
	ret = ft_putstr(str, flags);
	free(str);
	return (ret);
}
 
int main()
{
	int a = ft_printf("!%05%!");
	int b = printf("!%05%!");

	printf("\n\nft_printf: %d\nprintf: %d\n", a, b);
}