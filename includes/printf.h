#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>

typedef struct	s_prec
{
	int			min_num;	// minimun digit to appear after the decimal point. (for d, u, o, x, X)
	int			num_digit;	// number of digit to appear after the decimal point. (for e, E, f)
	int			max_num;	// max num of significant digits. (for g, G)
	int			max_len;	// max number of char to be printed. (for s)
}				t_prec;

typedef struct	s_opt
{
	int			align;	// left align
	int			sign;	// have i to print a sign prefix ?
	int			space;	// have i to print 'space' prefix ?
	int			diez;	// have i to do an alternate convertion ?
	int			zero;	// how many zero should i print to pad the field ?
	int			left_pre;
	int			righ_pre;
	t_prec		precis;	// more precision
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
 ** PARAMETERS
 */

/**
 ** CONVERSION
 **/

void	do_d(va_list arg, t_opt opt);
void	do_c(va_list arg, char c);
void	do_s(va_list arg, char c);
void	do_o(va_list arg);
void	do_u(va_list arg);
void	do_x(va_list arg, char c);

void	do_char(va_list arg, t_opt opt, char c);
void	do_int(va_list arg, t_opt opt, char c);
void	do_unsign(va_list arg, t_opt opt, char c);
void	do_ptr(va_list arg, t_opt opt, char c);
/**
 ** CORE
 **/

void	do_conv(const char *restrict format, int *count, va_list arg, t_opt opt);
int		ft_printf(const char *restrict format, ...);

#endif
