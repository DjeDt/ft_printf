/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:55:58 by ddinaut           #+#    #+#             */
/*   Updated: 2017/11/30 19:31:07 by ddinaut          ###   ########.fr       */
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

# define FLAG_LEFT	(1 << 0)
# define FLAG_SIGN	(1 << 1)
# define FLAG_SPACE	(1 << 2)
# define FLAG_ALT	(1 << 3)
# define FLAG_ZERO	(1 << 4)

typedef struct	s_opt
{
	int			flags;
	char		prefix;
	size_t		width;
	size_t		precision;
	int			len_mod;
	size_t		arg_len;
}				t_opt;

typedef struct	s_core
{
	char		*fmt;
	int			bytes;
	int			cur_pos;
	t_opt		opt;
	void		*final;
}				t_core;

/**
 ** LIB
 **/

void	ft_putchar(char c);
int		ft_ascii_to_utf8(wchar_t ch);
void	ft_putnbr(int nb);
void	ft_putstr(const char *str);
void	ft_putlstr(char *str, int bef, int end);
int		ft_putwstr(const wchar_t *str, t_opt opt);
char	*ft_itoa_base(int value, int base);
size_t	ft_strlen(const char *str);
int		nbr_len(unsigned long long i, int base);
int		ft_atoi(const char *str);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char    *ft_strfsub(char *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_fr(char const *s1, char *s2);
char	*ft_strjoin_fl(char *s1, char const *s2);
int		ft_strequ(const char *s1, const char *s2);

/**
 ** CONVERSION
 **/

int		do_int(va_list arg, t_opt opt, char c, void **final);
int		do_ptr(va_list arg, t_opt opt, char c, void **final);
int		do_long(va_list arg, t_opt opt, char c, void **final);
int		do_char(va_list arg, t_opt opt, char c, void **final);
int		do_unsign(va_list arg, t_opt opt, char c , void **final);

int		ascii_to_utf8(wchar_t ch);
char    *convert_int(long long int value, int base);
int     check_int_exception(long long int i, t_opt opt);

/**
 **	PRINT
**/

int		get_addr_len(unsigned long value, int base);
char	*get_addr(unsigned long value, int base, t_opt opt);
int		oneof(const char *str, char c);
int		concat_to_str(void **base, void *add, t_opt opt);
/**
 ** CORE
 **/

void	do_conv(t_core *core, int *count, va_list arg);
int		ft_printf(const char *format, ...);

int		ft_printf2(const char *format, ...);
void	do_conv2(char **format, char *save, va_list arg, t_opt opt);

#endif






