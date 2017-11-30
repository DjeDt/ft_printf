/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:14:20 by ddinaut           #+#    #+#             */
/*   Updated: 2017/11/30 19:11:05 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		do_char(va_list arg, t_opt opt, char c, void **final)
{
	int		ret;
	wchar_t	to_add[2];

	if (c == 'c')
	{
		if (opt.len_mod == MOD_L)
			to_add[0] = (wint_t)va_arg(arg, wint_t);
		else
			to_add[0] = (char)va_arg(arg, int);
	}
	else if (c == 'C')
		to_add[0] = (wchar_t)va_arg(arg, wint_t);
	to_add[1] = '\0';
	ret = concat_to_str(final, to_add, opt);
	return (ret);
}
