/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:14:20 by ddinaut           #+#    #+#             */
/*   Updated: 2017/11/24 09:33:02 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

void	print_char_prefix(t_opt opt, int len)
{
	char	tmp[len + 1];

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
	if (opt.flags & ALIGN)
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

void	print_wchar(wchar_t ch, t_opt opt)
{
	int	len;

	len = opt.width - 1;
	if (opt.flags & ALIGN)
	{
		ft_ascii_to_utf8(ch);
		if (len > 0)
			print_char_prefix(opt, len);
	}
	else
	{
		if (len > 0)
			print_char_prefix(opt, len);
		ft_ascii_to_utf8(ch);
	}
}

void	do_char(va_list arg, t_opt opt, char c)
{
	wchar_t ch;

	ch = 0;
	if (c == 'c')
	{
		if (opt.len_mod == MOD_L)
			ch = (wint_t)va_arg(arg, wint_t);
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
