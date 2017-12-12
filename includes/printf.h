/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:55:58 by ddinaut           #+#    #+#             */
/*   Updated: 2017/12/08 13:13:27 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>
# include <stddef.h>
# include <inttypes.h>

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

# define NO_CONV	(1 << 0)
# define CONV_CHR	(1 << 1)
# define CONV_INT	(1 << 2)
# define CONV_LNG	(1 << 3)
# define CONV_PTR	(1 << 4)
# define CONV_UNS	(1 << 5)

typedef struct	s_opt
{
	int			flags;
	int			type;
	char		prefix;
	int			len_mod;
	int			width;
	int			precision;
}				t_opt;

typedef struct	s_core
{
	char		*fmt;
	int			bytes;
	int			cur_pos;
	t_opt		opt;
	void		*final;
}				t_core;

char			*ft_itoa_base(int value, int base);
size_t			ft_strlen(const char *str);
int				nbr_len(unsigned long long i, int base);
int				ft_atoi(const char *str);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
void			ft_strdel(char **as);
char			*ft_strfsub(char *s, unsigned int start, size_t len);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoin_fr(char const *s1, char *s2);
char			*ft_strjoin_fl(char *s1, char const *s2);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);


int				do_int(va_list arg, t_opt opt, char c, void **final);
int				do_ptr(va_list arg, t_opt opt, char c, void **final);
int				do_long(va_list arg, t_opt opt, char c, void **final);
int				do_char(va_list arg, t_opt opt, char c, void **final);
int				do_unsign(va_list arg, t_opt opt, char c, void **final);

char			*concat_int(char *to_add, char c, t_opt opt);
char			*concat_unsign(char *to_add, char c, t_opt opt);
char			*concat_char(char *to_add, t_opt opt);
char			*concat_ptr(void *to_add, t_opt opt);


int				check_int_exception(long long int i, t_opt opt);
void			char_to_str(wchar_t ch, char *to_add);
int				normal_char(t_opt opt, char c, void **final);

int				oneof(const char *str, char c);
int				concat_to_str(void **base, void *add, char c, t_opt opt);
char			*create_padding(int size, char c);

char			*convert_int(long long int value, int base);
char			*pad_new_str(void *add, t_opt opt);

int				ft_printf(const char *format, ...);
void			do_conv(t_core *core, int *count, va_list arg);
int				do_parse(t_core *core, int *c, va_list arg);
void			init_opt(t_opt *opt);

#endif
