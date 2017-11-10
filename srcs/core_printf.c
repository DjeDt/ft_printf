/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:04:41 by ddinaut           #+#    #+#             */
/*   Updated: 2017/11/07 16:04:41 by ddinaut          ###   ########.fr       */
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
	opt->left_pre = 0;
	opt->righ_pre = 0;
}

int		get_number(const char *restrict format, int *count)
{
	int		ret;
	int		count2;
	char	*str;

	count2 = (*count);
	++(*count);
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

	count2 = (*count);
	++(*count);
	while (format[(*count)] && (format[(*count)] >= '0' && format[(*count)] <= '9'))
		(*count)++;
	str = ft_strsub(format, count2, (*count) - count2);
	opt->left_pre = ft_atoi(str);
	free(str);
	if (format[(*count)] != '.')
		return ;
	count2 = ++(*count);
	while (format[(*count)] && (format[(*count)] >= '0' && format[(*count)] <= '9'))
		(*count)++;
	str = ft_strsub(format, count2, (*count) - count2);
	opt->righ_pre = ft_atoi(str);
	free(str);
}

int		do_parse(const char *restrict format, int *c, va_list arg)
{
	t_opt	opt;

	init_opt(&opt);
	if (format[(*c)] == '-')
		opt.align = 1; /* a verifier */
	else if (format[(*c)] == '+')
		opt.sign = 1;
	else if (format[(*c)] == ' ')
		opt.space = get_number(format, c); //		opt.left_align = get_number(format, c);
	else if (format[(*c)] == '#')
		opt.diez = get_number(format, c);
	else if (format[(*c)] == '0')
		opt.zero = get_number(format, c);
	else if (format[(*c)] >= '1' && format[(*c)] <= '9')
		get_precision(format, c, &opt); // A ameliorer en fonction des convertions
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
