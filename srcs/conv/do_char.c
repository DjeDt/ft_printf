/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:14:20 by ddinaut           #+#    #+#             */
/*   Updated: 2017/12/04 19:30:56 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	char_to_str(wchar_t ch, char *to_add)
{
	int count;

	count = 0;
	if (ch <= 0x7F)
		to_add[count++] = ch;
	else if (ch <= 0x7FF)
	{
		to_add[count++] = ((ch >> 6) + 0xC0);
		to_add[count++] = ((ch & 0x3F) + 0x80);
	}
	else if (ch <= 0xFFFF)
	{
		to_add[count++] = ((ch >> 12) + 0xE0);
		to_add[count++] = (((ch >> 6) & 0x3F) + 0x80);
		to_add[count++] = ((ch & 0x3F) + 0x80);
	}
	else if (ch <= 0x10FFFF)
	{
		to_add[count++] = ((ch >> 18) + 0xF0);
		to_add[count++] = (((ch >> 12) & 0x3F) + 0x80);
		to_add[count++] = (((ch >> 6) & 0x3F) + 0x80);
		to_add[count++] = ((ch & 0x3F) + 0x80);
	}
	to_add[count] = '\0';
}

int		do_char(va_list arg, t_opt opt, char c, void **final)
{
	int		ret;
	wchar_t	ch;
	char	*to_add;

	ch = 0;
	if (c == 'c')
	{
		if (opt.len_mod == MOD_L)
			ch = (wint_t)va_arg(arg, wint_t);
		else
			ch = (char)va_arg(arg, int);
	}
	else if (c == 'C')
		ch = (wchar_t)va_arg(arg, wint_t);
	if (!(to_add = (char*)malloc(sizeof(char) * (4 + 1))))
		return (-1);
	char_to_str(ch, to_add);
	ret = concat_to_str(final, to_add, opt);
	return (ret);
}
