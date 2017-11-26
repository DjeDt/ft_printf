/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:23:58 by ddinaut           #+#    #+#             */
/*   Updated: 2017/11/26 21:06:37 by ddinaut          ###   ########.fr       */
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
	if ((oneof("cdipsu", c) == 1) && (opt->flags & FLAG_ALT))
		opt->flags &= ~FLAG_ALT;
	if ((oneof("diouixX", c) == 1) && (opt->flags & FLAG_ZERO))
	{
		opt->flags &= ~FLAG_ZERO;
		opt->prefix = ' ';
	}
	if ((opt->flags & FLAG_ZERO) && (opt->flags & FLAG_LEFT))
	{
		opt->flags &= ~FLAG_ZERO;
		opt->prefix = ' ';
	}
	if ((oneof("aAdeEfFgGi", c) == 0) && (opt->flags & FLAG_SPACE))
		opt->flags &= ~FLAG_SPACE;
	if ((opt->flags & FLAG_SPACE) && (opt->flags & FLAG_SIGN))
		opt->flags &= ~FLAG_SPACE;
}

void	do_conv(const char *restrict format, int *count, va_list arg, t_opt opt)
{
	int	len;

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
	{
		len = (*count) - opt.arg_len;
		write(1, format + ((*count) - len), len + 1);
	}
}
