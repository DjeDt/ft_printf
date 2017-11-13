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
#include <stdio.h>

int		get_len(long long int value, int base)
{
	int len;

	len = 1;
	while (value /= base)
		len++;
	return (len);
}

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
	count = get_len(value, base) + neg;
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

	str = convert_int(i, 10);
	(void)c;
	if (str != NULL)
	{
		len = opt.width - ft_strlen(str) - opt.space - opt.sign;
		if (i < 0 && opt.sign == 1)
			len++;
		if (opt.align == 1)
		{
			if (opt.space == 1 && i >= 0 && opt.sign == 0)
				ft_putchar(' ');
			else if (opt.sign == 1 && i >= 0)
				ft_putchar('+');
			ft_putstr(str);
			len > 0 ? print_int_prefix(len, opt) : 0;
		}
		else
		{
			len > 0 ? print_int_prefix(len, opt) : 0;
			if (opt.space == 1 && i >= 0 && opt.sign == 0)
				ft_putchar(' ');
			else if (opt.sign == 1 && i >= 0)
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
		i = (short)va_arg(arg, long long int); /* segfault desssus */
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
