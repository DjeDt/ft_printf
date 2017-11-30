/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:38:51 by ddinaut           #+#    #+#             */
/*   Updated: 2017/11/27 16:54:46 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	init_opt(t_opt *opt)
{
	opt->flags = 0;
	opt->prefix = ' ';
	opt->width = 0;
	opt->precision = 0;
	opt->len_mod = 0;
}

void	get_flags2(char **format, t_opt *opt)
{
	if (**format == '-')
		opt->flags |= FLAG_LEFT;
	else if (**format == '+')
		opt->flags |= FLAG_SIGN;
	else if (**format == '#')
		opt->flags |= FLAG_ALT;
	else if (**format == ' ')
	{
		opt->flags |= FLAG_SPACE;
		opt->prefix = ' ';
	}
	else if (**format == '0')
	{
		opt->flags |= FLAG_ZERO;
		opt->prefix = '0';
	}
	(*format)++;
}

void	get_mod(char **format, t_opt *opt)
{
	if (**format == 'h')
		opt->len_mod = MOD_H;
	else if (**format == 'l')
		opt->len_mod = MOD_L;
	else if (**format == 'j')
		opt->len_mod = MOD_J;
	else if (**format == 't')
		opt->len_mod = MOD_T;
	else if (**format == 'z')
		opt->len_mod = MOD_Z;
	(*format)++;
	if (**format == 'h' || **format == 'l')
	{
		if (**format == 'h')
			opt->len_mod = MOD_HH;
		else if (**format == 'l')
			opt->len_mod = MOD_LL;
		(*format)++;
	}
}

int		do_parse2(char **format, va_list arg)
{
	t_opt	opt;
	char	*save;

	init_opt(&opt);
	save = (*format) - 1;
	if (**format == '-' || **format == '+' || **format == ' ' || **format == '0' || **format == '#')
		get_flags2(format, &opt);
	if (**format >= '1' || **format <= '9')
	{
		while ((**format != '\0') && (**format >= '0' && **format <= '9'))
		{
			opt.width = (opt.width * 10) + ((**format) - 48);
			(*format)++;
		}
	}
	if (**format == '.')
	{
		(*format)++;
		while ((**format != '\0') && (**format >= '0' && **format <= '9'))
		{
			opt.precision = (opt.width * 10) + ((**format) - 48);
			(*format)++;
		}
	}
	if (**format == 'l' || **format == 'h' || **format == 'j' || **format == 't' || **format == 'z')
		get_mod(format, &opt);
	do_conv2(format, save, arg, opt);
	return (0);
}

int		ft_printf2(const char *format, ...)
{
	va_list	arg;

	va_start(arg, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			do_parse2((char**)&format, arg);
		}
		else
			ft_putchar(*format);
		format++;
	}
	return (0);
}
