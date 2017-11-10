/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:15:44 by ddinaut           #+#    #+#             */
/*   Updated: 2017/11/10 20:08:04 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_int(long long int i, t_opt opt)
{
	/* rajouter les options de opt ici */
	char	*str;

	str = NULL;
	str = ft_itoa_base(i, 10); /* converti pas les chiffres negatifs */
	if (str != NULL)
	{
		ft_putstr(str);
		free(str);
	}
	(void)opt;
}

void	do_int(va_list arg, t_opt opt, char c)
{
	long long int i;

	if (opt.len_mod == MOD_L)
		i = (long)va_arg(arg, long long int);
	else if (opt.len_mod == MOD_LL)
		i = (long long)va_arg(arg, long long int);
	else if (opt.len_mod == MOD_H)
		i = (short)va_arg(arg, long long int);
	else if (opt.len_mod == MOD_HH)
		i = (signed char)va_arg(arg, long long int);
	else if (opt.len_mod == MOD_J)
		i = (intmax_t)va_arg(arg, long long int);
	else if (opt.len_mod == MOD_T)
		i = (ptrdiff_t)va_arg(arg, long long int);
	else if (opt.len_mod == MOD_Z)
		i = (size_t)va_arg(arg, long long int);
	else
		i = (int)va_arg(arg, long long int);
	print_int(i, opt);
	(void)c;
}
