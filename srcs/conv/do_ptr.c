/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:15:07 by ddinaut           #+#    #+#             */
/*   Updated: 2017/11/10 20:15:00 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_ptr(void *str, t_opt opt, char c)
{
	void *p;

	p = NULL;
	if (c == 's')
		ft_putstr(str);
	else if (c == 'S')
		ft_putstr(str);
	else if (c == 'p')
	{
		p = ft_itoa_base((int)str, 16); /* a ameliorer, fonctionne pas vraiment */
		write(1, "0x", 2);
		write(1, p, ft_strlen(p));
		free(p);
	}
	(void)opt;
}

void	do_ptr(va_list arg, t_opt opt, char c)
{
	void	*tmp;

	tmp = NULL;
	if (c == 's')
	{
		if (opt.len_mod == MOD_L)
			tmp = (wchar_t*)va_arg(arg, wint_t*);
		else
			tmp = (char*)va_arg(arg, void*);
	}
	else if (c == 'S')
		tmp = (wchar_t*)va_arg(arg, wint_t*);
	else if (c == 'p')
		tmp = (void*)va_arg(arg, void*);
	print_ptr(tmp, opt, c);
}










