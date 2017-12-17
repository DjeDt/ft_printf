/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:23:58 by ddinaut           #+#    #+#             */
/*   Updated: 2017/12/15 13:09:16 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	normal_char(char c, t_core *core)
{
	char	*to_add;

	init_opt(&core->opt);
	to_add = (char*)malloc(sizeof(char) * 5);
	char_to_str(c, &to_add);
	final_concat(core, to_add);
}

void	do_conv(t_core *core, int *cc, va_list arg)
{
	if (oneof("di", core->fmt[(*cc)]))
		do_int(arg, core->fmt[(*cc)], core);
	else if (oneof("cC", core->fmt[(*cc)]))
		do_char(arg, core->fmt[(*cc)], core);
	else if (oneof("ouxX", core->fmt[(*cc)]))
		do_unsign(arg, core->fmt[(*cc)], core);
	else if (oneof("sSp", core->fmt[(*cc)]))
		do_ptr(arg, core->fmt[(*cc)], core);
	else if (oneof("DOU", core->fmt[(*cc)]))
		do_long(arg, core->fmt[(*cc)], core);
	else
		do_char(arg, core->fmt[(*cc)], core);
}
