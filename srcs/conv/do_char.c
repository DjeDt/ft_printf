/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:14:20 by ddinaut           #+#    #+#             */
/*   Updated: 2017/11/10 20:18:08 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

void	print_char_prefix(t_opt opt, int len)
{
	char	tmp[len];

	tmp[len] = '\0';
	while (len-- > 0)
		tmp[len] = ' ';
	ft_putstr(tmp);
	(void)opt;
}

void	print_char(wchar_t ch, t_opt opt)
{
	int len;

	len = opt.width - 1;
	if (opt.align == 1)
	{
		ft_putchar(ch);
		if (len > 0)
			print_char_prefix(opt, len);
	}
	else
	{
		if (len > 0)
			print_char_prefix(opt, len);
		ft_putchar(ch);
	}
}

void	ascii_to_utf8(wchar_t ch)
{
	if (ch <= 0x7F) // 127
		ft_putchar(ch);
	else if (ch <= 0x7FF) // 2047
	{
		ft_putchar((ch >> 6) + 0xC0); // + 192
		ft_putchar((ch & 0x3F) + 0x80); // (ch & 63) + 128 ->
	}
	else if (ch <= 0xFFFF) // 65535
	{
		ft_putchar((ch >> 12) + 0xE0); // (ch >> 12) + 224
		ft_putchar(((ch >> 6) & 0x3F) + 0x80); // (ch >> 6 & 63) + 128
		ft_putchar((ch & 0x3F) + 0x80); // (ch & 63) + 128
	}
	else if (ch <= 0x10FFFF) // 1114111
	{
		ft_putchar((ch >> 18) + 0xF0); // (ch >> 18) + 240
		ft_putchar(((ch >> 12) & 0x3F) + 0x80); // (ch >> 12) & 63 + 128
		ft_putchar(((ch >> 6) & 0x3F) + 0x80); // (ch >> 6) & 36 + 128
		ft_putchar((ch & 0x3F) + 0x80); // (ch >> 6 & 63) + 128
	}
}

void	print_wchar(wchar_t ch, t_opt opt)
{
	int	len;

	len = opt.width - 1;
	if (opt.align == 1)
	{
		ascii_to_utf8(ch);
		if (len > 0)
			print_char_prefix(opt, len);
	}
	else
	{
		if (len > 0)
			print_char_prefix(opt, len);
		ascii_to_utf8(ch);
	}
}

void	do_char(va_list arg, t_opt opt, char c)
{
	wchar_t ch;

	ch = 0;
	if (c == 'c')
	{
		if (opt.len_mod == MOD_L)
			ch = (wint_t)va_arg(arg, int);
		else
			ch = (char)va_arg(arg, int);
		print_char(ch, opt);
	}
	else if (c == 'C')
	{
		ch = (wchar_t)va_arg(arg, wint_t);
		print_wchar(ch, opt);
	}
}
