/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:57:14 by afpachec          #+#    #+#             */
/*   Updated: 2024/11/05 17:53:14 by afpachec         ###   ########.fr       */
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
	int		sign;
	int		dot;
	int		plus;
	int		space;
	int		alt;
	int		width;
	int		length;
}	t_flags;

char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);

char	*ft_itoa(int n);
int		ft_atoi(const char *str);
char	*ft_uitoa(unsigned int n);
char	*ft_uitohexa(unsigned long n, char *hex);

void	set_all_zero_and_pass_dash_and_width(t_flags *flags);
int		parse_flags(char *str, t_flags *flags);
t_flags	*new_flags(void);
int		ft_convert_and_put(va_list *args, const char sign, t_flags *flags);

int		ft_printf(const char *format, ...);

int		ft_putchar(char c, t_flags *flags);
int		ft_putu(unsigned int n, t_flags *flags);
int		ft_putptr(void *n, t_flags *flags);
int		ft_puthex(unsigned long n, int force_alt, int upper, t_flags *flags);
int		ft_putnbr(int n, t_flags *flags);
int		ft_putstr(char *str, t_flags *flags);

#endif