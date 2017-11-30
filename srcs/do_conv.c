/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:23:58 by ddinaut           #+#    #+#             */
/*   Updated: 2017/11/30 19:14:35 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	check_exeption(const char c, t_opt *opt)
{
	if ((oneof("cdipsu", c) == 1) && (opt->flags & FLAG_ALT))
		opt->flags &= ~FLAG_ALT;
	if ((oneof("diouixX", c) == 1) && (opt->flags & FLAG_ZERO) && (opt->precision > 0))
	{
		opt->flags &= ~FLAG_ZERO;
		opt->prefix = ' ';
	}
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

int		test(t_opt opt, char c, void **final)
{
	int		ret;
	char	to_add[2];

	to_add[0] = c;
	to_add[1] = '\0';
	ret = concat_to_str(final, to_add, opt);
	return (ret);
}

void	do_conv(t_core *core, int *count, va_list arg)
{
	check_exeption(core->fmt[(*count)], &core->opt);
	if (core->fmt[(*count)] == 'd' || core->fmt[(*count)] == 'i')
		core->bytes += do_int(arg, core->opt, core->fmt[(*count)], &core->final);
	if (core->fmt[(*count)] == 'c' || core->fmt[(*count)] == 'C')
		core->bytes += do_char(arg, core->opt, core->fmt[(*count)], &core->final);
	else if (core->fmt[(*count)] == 'o' || core->fmt[(*count)] == 'u' || \
			 core->fmt[(*count)] == 'x' || core->fmt[(*count)] == 'X')
		core->bytes += do_unsign(arg, core->opt, core->fmt[(*count)], &core->final);
	else if (core->fmt[(*count)] == 's' || core->fmt[(*count)] == 'S' || core->fmt[(*count)] == 'p')
		core->bytes += do_ptr(arg, core->opt, core->fmt[(*count)], &core->final);
	else if (core->fmt[(*count)] == 'D' || core->fmt[(*count)] == 'O' || core->fmt[(*count)] == 'U')
		core->bytes += do_long(arg, core->opt, core->fmt[(*count)], &core->final);
	else
		core->bytes += test(core->opt, core->fmt[(*count)], &core->final);
}
