/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:15:44 by ddinaut           #+#    #+#             */
/*   Updated: 2017/11/22 18:04:24 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

char	*convert_int(long long int value, int base)
{
	int			neg;
	int			count;
	char		*ret;
	const char	*str;

	neg = 0;
	if (value < 0)
	{
		neg = 1;
		value *= (-1);
	}
	count = nbr_len(value, base) + neg;
	str = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if (!(ret = (char*)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	ret[count] = '\0';
	while (count-- > neg)
	{
		ret[count] = str[(value % base)];
		value /= base;
	}
	if (neg == 1)
		ret[0] = '-';
	return (ret);
}

void	print_int_prefix(int len, t_opt opt)
{
	char	tmp[len];

	tmp[len] = '\0';
	while (len-- > 0)
		tmp[len] = opt.prefix;
	ft_putstr(tmp);
}

void	print_int(long long int i, t_opt opt, char c)
{
	int		len;
	char	*str;

	(void)c;
	str = convert_int(i, 10);
	if (str != NULL)
	{
		len = get_width(opt, str);
		if (i < 0 && (opt.flags & SIGN))
			len++;
		if (opt.flags & ALIGN)
		{
			if ((opt.flags & SPACE) && i >= 0 && (opt.flags & SIGN) == 0)
				ft_putchar(' ');
			else if ((opt.flags & SIGN) && i >= 0)
				ft_putchar('+');
			ft_putstr(str);
			len > 0 ? print_int_prefix(len, opt) : 0;
		}
		else
		{
			len > 0 ? print_int_prefix(len, opt) : 0;
			if ((opt.flags & SPACE) && i >= 0 && (opt.flags & SIGN) == 0)
				ft_putchar(' ');
			else if ((opt.flags & SIGN) && i >= 0)
				ft_putchar('+');
			ft_putstr(str);
		}
		free(str);
	}
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
	print_int(i, opt, c);
}
