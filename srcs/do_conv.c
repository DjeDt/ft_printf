/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:23:58 by ddinaut           #+#    #+#             */
/*   Updated: 2017/12/13 11:01:26 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	check_exeption(const char c, t_opt *opt)
{
	if ((oneof("cdipsu", c) == 1) && (opt->flags & FLAG_ALT))
		opt->flags &= ~FLAG_ALT;
	/*
	  if ((oneof("diouixX", c) == 1) && (opt->flags & FLAG_ZERO)	\
	  && (opt->precision > 0))
	  {
	  opt->flags &= ~FLAG_ZERO;
	  opt->prefix = ' ';
	  }
	*/
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

int		normal_char(t_opt opt, char c, void **final)
{
	int		ret;
	char	to_add[5];

	opt.type = NO_CONV;
	char_to_str(c, to_add);
	ret = concat_to_str(final, to_add, c, opt);
	return (ret);
}

void	do_conv(t_core *core, int *cc, va_list arg)
{
	check_exeption(core->fmt[(*cc)], &core->opt);
	if ((core->fmt[(*cc)] == 'd') || (core->fmt[(*cc)] == 'i'))
		core->bytes += do_int(arg, core->opt, core->fmt[(*cc)], &core->final);
	else if (core->fmt[(*cc)] == 'c' || core->fmt[(*cc)] == 'C')
		core->bytes += do_char(arg, core->opt, core->fmt[(*cc)], &core->final);
	else if (core->fmt[(*cc)] == 'o' || core->fmt[(*cc)] == 'u' || core->fmt[(*cc)] == 'x' || core->fmt[(*cc)] == 'X')
		core->bytes += do_unsign(arg, core->opt, core->fmt[(*cc)], &core->final);
	else if (core->fmt[(*cc)] == 's' || core->fmt[(*cc)] == 'S' || core->fmt[(*cc)] == 'p')
		core->bytes += do_ptr(arg, core->opt, core->fmt[(*cc)], &core->final);
	else if (core->fmt[(*cc)] == 'D' || core->fmt[(*cc)] == 'O' || core->fmt[(*cc)] == 'U')
		core->bytes += do_long(arg, core->opt, core->fmt[(*cc)], &core->final);
	else
		core->bytes += normal_char(core->opt, core->fmt[(*cc)], &core->final);
}
