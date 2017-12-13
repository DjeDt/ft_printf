/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:05:29 by ddinaut           #+#    #+#             */
/*   Updated: 2017/12/13 22:23:41 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		get_width(const char *format, int *cc, t_opt *opt)
{
	int		cc2;
	char	*str;

	str = NULL;
	cc2 = (*cc);
	while (format[(*cc)] && (format[(*cc)] >= '0' && format[(*cc)] <= '9'))
		(*cc)++;
	str = ft_strsub(format, cc2, (*cc) - cc2);
	if (str == NULL)
		return (-1);
	opt->width = ft_atoi(str);
	opt->flags |= FLAG_LDC;
	free(str);
	return (0);
}

int		get_precision(const char *format, int *cc, t_opt *opt)
{
	int		cc2;
	char	*str;

	str = NULL;
	cc2 = ++(*cc);
	while (format[(*cc)] && (format[(*cc)] >= '0' && format[(*cc)] <= '9'))
		(*cc)++;
	str = ft_strsub(format, cc2, (*cc) - cc2);
	if (str == NULL)
		return (-1);
	opt->precision = ft_atoi(str);
	opt->flags |= FLAG_PREC;
	free(str);
	return (0);
}

void	get_len_mod(const char *format, int *cc, t_opt *opt)
{
	if (format[(*cc)] == 'h')
		opt->len_mod = MOD_H;
	else if (format[(*cc)] == 'l')
		opt->len_mod = MOD_L;
	else if (format[(*cc)] == 'j')
		opt->len_mod = MOD_J;
	else if (format[(*cc)] == 't')
		opt->len_mod = MOD_T;
	else if (format[(*cc)] == 'z')
		opt->len_mod = MOD_Z;
	(*cc)++;
	if (format[(*cc)] == 'h' || format[(*cc)] == 'l')
	{
		if (format[(*cc)] == 'h')
			opt->len_mod = MOD_HH;
		else if (format[(*cc)] == 'l')
			opt->len_mod = MOD_LL;
		(*cc)++;
	}
}

void	get_flags(const char *format, int *cc, t_opt *opt)
{
	if (format[(*cc)] == '-')
		opt->flags |= FLAG_LEFT;
	else if (format[(*cc)] == '+')
		opt->flags |= FLAG_SIGN;
	else if (format[(*cc)] == '#')
		opt->flags |= FLAG_ALT;
	else if (format[(*cc)] == ' ')
	{
		opt->flags |= FLAG_SPACE;
		opt->prefix = ' ';
	}
	else if (format[(*cc)] == '0')
	{
		opt->flags |= FLAG_ZERO;
		opt->prefix = '0';
	}
	(*cc)++;
}

int		do_parse(t_core *core, int *cc, va_list arg)
{
	int ret;

	ret = 0;
	init_opt(&core->opt);
	while ((core->fmt[(*cc)] != '\0') && (oneof("-+ 0#", core->fmt[(*cc)]) > 0))
		get_flags(core->fmt, cc, &core->opt);
	if (core->fmt[(*cc)] >= '1' && core->fmt[(*cc)] <= '9')
		get_width(core->fmt, cc, &core->opt);
	if (core->fmt[(*cc)] == '.')
		get_precision(core->fmt, cc, &core->opt);
	if (oneof("lhjtz", core->fmt[(*cc)]) == 1)
		get_len_mod(core->fmt, cc, &core->opt);
	do_conv(core, cc, arg);
	return (*cc);
}








