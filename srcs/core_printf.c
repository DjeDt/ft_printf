/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:04:41 by ddinaut           #+#    #+#             */
/*   Updated: 2017/11/10 20:33:21 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

void	init_opt(t_opt *opt)
{
	opt->sign = 0;
	opt->align = 0;
	opt->space = 0;
	opt->diez = 0;
	opt->zero = 0;
	opt->prefix = '\0';
	opt->width = 0;
	opt->precision = 0;
	opt->len_mod = 0;
}

int		get_number(const char *restrict format, int *count, t_opt *opt)
{
	int		ret;
	int		count2;
	char	*str;

	opt->prefix = format[(*count)];
	++(*count);
	count2 = (*count);
	while (format[(*count)] >= '0' && format[(*count)] <= '9')
		(*count)++;
	if ((str = ft_strsub(format, count2, (*count) - count2)) == NULL)
		return (-1);
	ret = ft_atoi(str);
	free(str);
	return (ret);
}

void	get_precision(const char *restrict format, int *count, t_opt *opt)
{
	int		count2;
	char	*str;

	str = NULL;
	count2 = (*count);
	++(*count);
	while (format[(*count)] && (format[(*count)] >= '0' && format[(*count)] <= '9'))
		(*count)++;
	str = ft_strsub(format, count2, (*count) - count2);
	opt->width = ft_atoi(str);
	free(str);
	if (format[(*count)] != '.')
		return ;
	count2 = ++(*count);
	while (format[(*count)] && (format[(*count)] >= '0' && format[(*count)] <= '9'))
		(*count)++;
	str = ft_strsub(format, count2, (*count) - count2);
	opt->precision = ft_atoi(str);
	free(str);
	(*count)++;
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
	/* rajouter les else pour gestion d'erreur */
	(*count)++;
}

void	get_flags(const char *restrict format, int *c, t_opt *opt)
{
	if (format[(*c)] == '-')
	{
		opt->align = 1;
		(*c)++;
	}
	else if (format[(*c)] == '+')
	{
		opt->sign = 1;
		(*c)++;
	}
	else if (format[(*c)] == ' ')
	{
		opt->space = 1;
		opt->prefix = ' ';
		(*c)++;
	}
	else if (format[(*c)] == '0')
	{
		opt->zero = 1;
		opt->prefix = '0';
		(*c)++;
	}
	else if (format[(*c)] == '#')
	{
		opt->diez = 1;
		(*c)++;
	}
}

int		is_conv_char(char c)
{
	if (c == 'd' || c == 'i' || c == 'c' || c == 'C' || c == 's' ||
		c == 'S' || c == 'p' || c == 'D' || c == 'O' || c == 'U')
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
			get_precision(format, c, &opt); /* get width and/or precision */
		if (format[(*c)] == 'l' || format[(*c)] == 'h' || format[(*c)] == 'j' || format[(*c)] == 't' || format[(*c)] == 'z')
			get_len_mod(format, c, &opt); /* get differents len modifiers */
	}
//	printf("\nalign = %d et sign = %d et space = %d et diez = %d et zero = %d et precision = %d.%d\n", opt.align, opt.sign, opt.space, opt.diez, opt.zero, opt.left_pre, opt.righ_pre);
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
