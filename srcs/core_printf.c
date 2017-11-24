/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:04:41 by ddinaut           #+#    #+#             */
/*   Updated: 2017/11/24 10:45:55 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

void	init_opt(t_opt *opt)
{
	opt->flags = 0;
	opt->prefix = ' ';
	opt->width = 0;
	opt->precision = 0;
	opt->len_mod = 0;
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
	else if ((format[(*count)] == 'h' && format[(*count) + 1] == 'h') || (format[(*count)] == 'l' && format[(*count) + 1] == 'l'))
	{
		if (format[(*count) + 1] == 'h')
			opt->len_mod = MOD_HH;
		else if(format[(*count) + 1] == 'l')
			opt->len_mod = MOD_LL;
		(*count)++;
	}
	(*count)++;
}

void	get_flags(const char *restrict format, int *c, t_opt *opt)
{
	if (format[(*c)] == '-')
	{
		opt->flags |= ALIGN;
		(*c)++;
	}
	else if (format[(*c)] == '+')
	{
		opt->flags |= SIGN;
		(*c)++;
	}
	else if (format[(*c)] == ' ')
	{
		opt->flags |= SPACE;
		opt->prefix = ' ';
		(*c)++;
	}
	else if (format[(*c)] == '0')
	{
		opt->flags |= ZERO;
		opt->prefix = '0';
		(*c)++;
	}
	else if (format[(*c)] == '#')
	{
		opt->flags |= DIEZ;
		(*c)++;
	}
}

int		is_conv_char(char c)
{
	if (c == 'd' || c == 'i' || c == 'c' || c == 'C' || c == 's' ||
		c == 'S' || c == 'p' || c == 'D' || c == 'O' || c == 'U' || c == 'o' || c == 'x' || c == 'X')
		return (1);
	return (0);
}

int		do_parse(const char *restrict format, int *c, va_list arg)
{
	t_opt	opt;

	init_opt(&opt);
	while (format[(*c)] != '\0' && (is_conv_char(format[(*c)]) == 0))
	{
		if (format[(*c)] == '-' || format[(*c)] == '+' || format[(*c)] == ' ' || format[(*c)] == '0' || format[(*c)] == '#')
			get_flags(format, c, &opt); /* get differents flags */
		if (format[(*c)] >= '1' && format[(*c)] <= '9')
			get_width_min(format, c, &opt); /* get width and/or precision */
		if (format[(*c)] == '.')
			get_precision(format, c,  &opt);
		if (format[(*c)] == 'l' || format[(*c)] == 'h' || format[(*c)] == 'j' || format[(*c)] == 't' || format[(*c)] == 'z')
			get_len_mod(format, c, &opt); /* get differents len modifiers */
	}
	do_conv(format, c, arg, opt);
	return (0);
}

int		ft_printf(const char *restrict format, ...)
{
	int				count;
	va_list			arg;

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
