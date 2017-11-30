/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:04:41 by ddinaut           #+#    #+#             */
/*   Updated: 2017/11/30 19:30:55 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

void	init_core(t_core *core, const char *format)
{
	core->fmt = (char*)format;
	core->bytes = 0;
	core->cur_pos = 0;
	core->final = NULL;
}

void	init_opt(t_opt *opt, int *c)
{
	opt->flags = 0;
	opt->prefix = ' ';
	opt->width = 1;
	opt->precision = 0;
	opt->len_mod = 0;
	opt->arg_len = (*c) - 1;
}

void	get_width(const char *format, int *count, t_opt *opt)
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

void	get_precision(const char *format, int *count, t_opt *opt)
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

void	get_len_mod(const char *format, int *count, t_opt *opt)
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

void	get_flags(const char *format, int *c, t_opt *opt)
{
	if (format[(*c)] == '-')
		opt->flags |= FLAG_LEFT;
	else if (format[(*c)] == '+')
		opt->flags |= FLAG_SIGN;
	else if (format[(*c)] == '#')
		opt->flags |= FLAG_ALT;
	else if (format[(*c)] == ' ')
	{
		opt->flags |= FLAG_SPACE;
		opt->prefix = ' ';

	}
	else if (format[(*c)] == '0')
	{
		opt->flags |= FLAG_ZERO;
		opt->prefix = '0';
	}
	(*c)++;
}

int		do_parse(t_core *core, int *c, va_list arg)
{
	init_opt(&core->opt, c);
	while (oneof("-+ 0#", core->fmt[(*c)]) == 1)
		get_flags(core->fmt, c, &core->opt);
	if (core->fmt[(*c)] >= '1' && core->fmt[(*c)] <= '9')
		get_width(core->fmt, c, &core->opt);
	if (core->fmt[(*c)] == '.')
		get_precision(core->fmt, c,  &core->opt);
	if (oneof("lhjtz", core->fmt[(*c)]) == 1)
		get_len_mod(core->fmt, c, &core->opt);
	do_conv(core, c, arg);
	return (*c);
}

void	begin_parse(t_core *core, va_list arg)
{
	int count;

	count = -1;
	while (core->fmt[++count] != '\0')
	{
		if (core->fmt[count] == '%')
		{
			count++;
			do_parse(core, &count, arg);
		}
		else
		{
			ft_putchar(core->fmt[count]);
			core->bytes += 1;
		}
	}
}

int		ft_printf(const char *restrict format, ...)
{
	va_list arg;
	t_core	core;

	if (format == NULL)
		return (-1);
	init_core(&core, format);
	va_start(arg, format);
	begin_parse(&core, arg);
	va_end(arg);
	free(core.final);
	return (core.bytes);
}
