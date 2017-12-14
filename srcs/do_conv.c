/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:23:58 by ddinaut           #+#    #+#             */
/*   Updated: 2017/12/14 22:56:52 by ddinaut          ###   ########.fr       */
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

void	normal_char(char c, t_core *core)
{
	char	*to_add;

	to_add = (char*)malloc(sizeof(char) * 5);
	core->opt.type = NO_CONV;
	char_to_str(c, &to_add);
	concat_to_str(&core->final, to_add, c, core->opt);
	core->bytes += ft_strlen(to_add);
	free(to_add);
}

void	do_conv(t_core *core, int *cc, va_list arg)
{
	/* Verifier si elle sert vraiment a qque chose
	 *	check_exeption(core->fmt[(*cc)], &core->opt);
	 */
	if (oneof("di", core->fmt[(*cc)]))
		do_int(arg, core, core->fmt[(*cc)]);
	else if (oneof("cC", core->fmt[(*cc)]))
		do_char(arg, core->fmt[(*cc)], core);
	else if (oneof("ouxX", core->fmt[(*cc)]))
		do_unsign(arg, core->fmt[(*cc)], core);
	else if (oneof("sSp", core->fmt[(*cc)]))
		do_ptr(arg, core, core->fmt[(*cc)]);
	else if (oneof("DOU", core->fmt[(*cc)]))
		do_long(arg, core->fmt[(*cc)], core);
	else
		normal_char(core->fmt[(*cc)], core);
}
