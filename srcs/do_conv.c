/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:23:58 by ddinaut           #+#    #+#             */
/*   Updated: 2017/11/14 12:28:49 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		oneof(const char *str, char c)
{
	int count;

	count = -1;
	if (str)
	{
		while (str[++count])
		{
			if (str[count] == c)
				return (1);
		}
	}
	return (0);
}

void	check_exeption(const char c, t_opt *opt)
{
	if (oneof("cdipsu", c) == 1 && opt->diez == 1)
		opt->diez = 0;
	if (oneof("diouixX", c) == 1 && opt->zero == 1)
		opt->zero = 0;
	if (opt->zero == 1 && opt->align == 1)
		opt->zero = 0;
	if (oneof("aAdeEfFgGi", c) == 0 && opt->space == 1)
		opt->space = 0;
	if (opt->space == 1 && opt->sign == 1)
		opt->space = 0;
}

void	do_conv(const char *restrict format, int *count, va_list arg, t_opt opt)
{

	check_exeption(format[(*count)], &opt);
	if (format[(*count)] == 'd' || format[(*count)] == 'i')
		do_int(arg, opt, format[(*count)]);
	else if (format[(*count)] == 'c' || format[(*count)] == 'C')
		do_char(arg, opt, format[(*count)]);
	else if (format[(*count)] == 'o' || format[(*count)] == 'u' || \
			 format[(*count)] == 'x' || format[(*count)] == 'X')
		do_unsign(arg, opt, format[(*count)]);
	else if (format[(*count)] == 's' || format[(*count)] == 'S' || format[(*count)] == 'p')
		do_ptr(arg, opt, format[(*count)]);
	else if (format[(*count)] == 'D' || format[(*count)] == 'O' || format[(*count)] == 'U')
		do_long(arg, opt, format[(*count)]);
	else
		ft_putchar(format[(*count)]);
}
