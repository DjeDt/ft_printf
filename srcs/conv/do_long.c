/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:34:34 by ddinaut           #+#    #+#             */
/*   Updated: 2017/12/15 12:19:13 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		do_long(va_list arg, char c, t_core *core)
{
	long long int	i;
	char			*to_add;

	to_add = NULL;
	core->opt.type = CONV_LNG;
	i = va_arg(arg, long long int);
	if (c == 'D')
		to_add = convert_int(i, 10);
	else if (c == 'O')
		to_add = convert_int(i, 8);
	else if (c == 'U')
		to_add = convert_int(i, 10);
	concat_int(i, c, &to_add, core);
	final_concat(core, to_add);
}
