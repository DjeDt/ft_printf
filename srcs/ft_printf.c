/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:04:41 by ddinaut           #+#    #+#             */
/*   Updated: 2017/12/21 15:37:15 by ddinaut          ###   ########.fr       */
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

void	init_opt(t_opt *opt)
{
	opt->flags = 0;
	opt->type = 0;
	opt->prefix = ' ';
	opt->width = 0;
	opt->precision = 0;
	opt->len_mod = 0;
	opt->len_cpy = 0;
}

void	begin_parse(t_core *core, va_list arg)
{
	int cc;

	cc = -1;
	while (core->fmt[++cc] != '\0')
	{
		if (core->fmt[cc] == '%' && core->fmt[cc + 1] != '\0')
		{
			cc++;
			if (do_parse(core, &cc, arg) == -1)
				break ;
		}
		else
			normal_char(core->fmt[cc], core);
	}
	write(1, core->final, core->bytes);
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
	ft_strdel((char**)&core.final);
	return (core.bytes);
}
