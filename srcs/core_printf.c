/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:04:41 by ddinaut           #+#    #+#             */
/*   Updated: 2017/11/26 21:09:27 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

void	init_opt(t_opt *opt, int *c)
{
	opt->flags = 0;
	opt->prefix = ' ';
	opt->width = 0;
	opt->precision = 0;
	opt->len_mod = 0;
	opt->arg_len = (*c) - 1;
}

void	get_width_min(const char *restrict format, int *count, t_opt *opt)
{
	int		count2;
	char	*str;

	str = NULL;
	count2 = (*count);
	++(*count);
	while (format[(*count)] && (format[(*count)] >= '0' && format[(*count)] <= '9'))
		(*count)++;
	if ((str = ft_strsub(format, count2, (*count) - count2)) == NULL)
		return ;
	opt->width = ft_atoi(str);
	free(str);
}
void	get_precision(const char *restrict format, int *count, t_opt *opt)
{
	int		count2;
	char	*str;

	str = NULL;
	count2 = ++(*count);
	while (format[(*count)] && (format[(*count)] >= '0' && format[(*count)] <= '9'))
		(*count)++;
	if ((str = ft_strsub(format, count2, (*count) - count2)) == NULL)
		return ;
	opt->precision = ft_atoi(str);
	free(str);
}

void	get_len_mod(const char *restrict format, int *count, t_opt *opt)
{
	if (format[(*count)] == 'h')
		opt->len_mod = MOD_H;
	else if (format[(*count)] == 'l')
		opt->len_mod = MOD_L;
	else if (format[(*count)] == 'j')
		opt->len_mod = MOD_J;
	else if (format[(*count)] == 't')
		opt->len_mod = MOD_T;
	else if (format[(*count)] == 'z')
		opt->len_mod = MOD_Z;
	(*count)++;
	if (format[(*count)] == 'h' || format[(*count)] == 'l')
	{
		if (format[(*count)] == 'h')
			opt->len_mod = MOD_HH;
		else if (format[(*count)] == 'l')
			opt->len_mod = MOD_LL;
		(*count)++;
	}
}

void	get_flags(const char *restrict format, int *c, t_opt *opt)
{
	if (format[(*c)] == '-')
	{
		opt->flags |= FLAG_LEFT;
		(*c)++;
	}
	if (format[(*c)] == '+')
	{
		opt->flags |= FLAG_SIGN;
		(*c)++;
	}
	if (format[(*c)] == '#')
	{
		opt->flags |= FLAG_ALT;
		(*c)++;
	}
	if (format[(*c)] == ' ')
	{
		opt->flags |= FLAG_SPACE;
		opt->prefix = ' ';
		(*c)++;
	}
	else if (format[(*c)] == '0')
	{
		opt->flags |= FLAG_ZERO;
		opt->prefix = '0';
		(*c)++;
	}
}

int		do_parse(const char *restrict format, int *c, va_list arg)
{
	t_opt	opt;

	init_opt(&opt, c);
	if ((format[(*c)] == '-') || (format[(*c)] == '+') || (format[(*c)] == ' ') || (format[(*c)] == '0') || (format[(*c)] == '#'))
		get_flags(format, c, &opt);
	if (format[(*c)] >= '1' && format[(*c)] <= '9')
		get_width_min(format, c, &opt);
//	if (format[(*c)] == '*')
//		get_precision_or_width_from_arg();
	if (format[(*c)] == '.')
		get_precision(format, c,  &opt);
	if (format[(*c)] == 'l' || format[(*c)] == 'h' || format[(*c)] == 'j' || format[(*c)] == 't' || format[(*c)] == 'z')
		get_len_mod(format, c, &opt);
	do_conv(format, c, arg, opt);
	return (0);
}

int		ft_printf(const char *restrict format, ...)
{
	int		count;
	va_list	arg;

	count = -1;
	va_start(arg, format);
	while (format[++count] != '\0')
	{
		if (format[count] == '%')
		{
			++count;
			do_parse(format, &count, arg);
		}
		else
			ft_putchar(format[count]);
	}
	va_end(arg);
	return (0);
}
