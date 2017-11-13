/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:55:58 by ddinaut           #+#    #+#             */
/*   Updated: 2017/11/10 20:24:45 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>
# include <stddef.h> /* pour cast en ptrdiff */
# include <inttypes.h>

/**
 **	lenght modifier
 **/

# define MOD_L	1
# define MOD_LL	2
# define MOD_H	4
# define MOD_HH	8
# define MOD_J	16
# define MOD_T	32
# define MOD_Z	64

typedef struct	s_opt
{
	int			align;	// left align
	int			sign;	// have i to print a sign prefix ?
	int			space;	// have i to print 'space' prefix ?
	int			diez;	// have i to do an alternate convertion ?
	int			zero;	// how many zero should i print instead of space ?
	char		prefix; // espace ou zero
	int			width;
	int			precision;
	int			len_mod;
}				t_opt;

/**
 ** LIBFT
 **/

void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putstr(const char *str);
char	*ft_itoa_base(int value, int base);
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);
char	*ft_strsub(char const *s, unsigned int start, size_t len);

/**
 ** CONVERSION
 **/

void	do_char(va_list arg, t_opt opt, char c);
void	do_int(va_list arg, t_opt opt, char c);
void	do_unsign(va_list arg, t_opt opt, char c);
void	do_ptr(va_list arg, t_opt opt, char c);
void	do_long(va_list arg, t_opt opt, char c);

/**
 ** CORE
 **/

void	do_conv(const char *restrict format, int *count, va_list arg, t_opt opt);
int		ft_printf(const char *restrict format, ...);

#endif
