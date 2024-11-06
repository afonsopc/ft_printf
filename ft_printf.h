/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:57:14 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/02 17:43:49 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_flags
{
	int		zero;
	int		dash;
	int		dot;
	size_t	width;
	size_t	precision;
}	t_flags;

char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);

char	*ft_itoa(int n);
int		ft_atoi(const char *str);
char	*ft_uitoa(unsigned int n);
char	*ft_uitohexa(unsigned long n, char *hex);

t_flags	*new_flags(void);
int		ft_convert_and_put(va_list *args, const char sign, t_flags *flags);

int		ft_printf(const char *format, ...);

int		ft_putchar(char c, t_flags *flags);
int		ft_putu(unsigned int n, t_flags *flags);
int		ft_putptr(void *n, t_flags *flags);
int		ft_puthex(unsigned long n, int upper, t_flags *flags);
int		ft_putnbr(int n, t_flags *flags);
int		ft_putstr(char *str, t_flags *flags);

#endif