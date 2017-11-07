#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

/**
 ** LIBFT
 **/

void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putstr(const char *str);
char	*ft_itoa_base(int value, int base);
size_t	ft_strlen(const char *str);

/**
 ** CONVERSION
 **/

void	do_d(va_list arg);
void	do_c(va_list arg, char c);
void	do_s(va_list arg, char c);
void	do_o(va_list arg);
void	do_u(va_list arg);
void	do_x(va_list arg, char c);
void	do_hh(va_list arg);

/**
 ** CORE
 **/

int	ft_printf(const char *restrict format, ...);

#endif
