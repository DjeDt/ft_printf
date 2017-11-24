/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:55:58 by ddinaut           #+#    #+#             */
/*   Updated: 2017/11/24 11:03:45 by ddinaut          ###   ########.fr       */
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

# define ALIGN	(1 << 0)
# define SIGN	(1 << 1)
# define SPACE	(1 << 2)
# define DIEZ	(1 << 3)
# define ZERO	(1 << 4)

typedef struct	s_opt
{
	int			flags;
	char		prefix;
	int			width;
	int			precision;
	int			len_mod;
}				t_opt;

/**
 ** LIBFT
 **/

void	ft_putchar(char c);
void	ft_ascii_to_utf8(wchar_t ch);
void	ft_putnbr(int nb);
void	ft_putstr(const char *str);
void	ft_putwstr(const wchar_t *str, t_opt opt);
char	*ft_itoa_base(int value, int base);
size_t	ft_strlen(const char *str);
int		nbr_len(unsigned long long i, int base);
int		ft_atoi(const char *str);
char	*ft_strsub(char const *s, unsigned int start, size_t len);

char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_fr(char const *s1, char *s2);

/**
 ** CONVERSION
 **/

void	do_char(va_list arg, t_opt opt, char c);
void	do_int(va_list arg, t_opt opt, char c);
void	do_unsign(va_list arg, t_opt opt, char c);
void	do_ptr(va_list arg, t_opt opt, char c);
void	do_long(va_list arg, t_opt opt, char c);
void	ascii_to_utf8(wchar_t ch);

int		get_width(t_opt opt, char *str);

/**
 **	PRINT
**/

void	print_ptr_s(void *str, t_opt opt);
void	print_ptr_S(void *str, t_opt opt);
void	print_ptr_p(void *str, t_opt opt);
int		get_addr_len(unsigned long value, int base);
char	*get_addr(unsigned long value, int base);
void	print_ptr_prefix(t_opt opt, int len);
void	print_exeption(long long int i, t_opt opt);
/**
 ** CORE
 **/

void	do_conv(const char *restrict format, int *count, va_list arg, t_opt opt);
int		ft_printf(const char *restrict format, ...);

#endif
