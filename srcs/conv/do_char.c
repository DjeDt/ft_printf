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

void	print_char(wchar_t ch, t_opt opt)
{
	(void)opt; // pour les options d'affichage
	ft_putchar(ch);
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
	}
	else if (c == 'C')
		ch = (wchar_t)va_arg(arg, wint_t);
	print_char(ch, opt);
}
