/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:34:34 by ddinaut           #+#    #+#             */
/*   Updated: 2017/12/28 20:24:43 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	long_len(unsigned long int value, int base)
{
	int ret;

	ret = 1;
	while (value /= base)
		ret++;
	return (ret);
}

static void	init_value(unsigned long int *v2, long int v1, int base, int *neg)
{
	if (v1 < 0)
	{
		if (base == 10)
			(*neg) = 1;
		(*v2) = v1 * (-1);
	}
	else
		(*v2) = v1;
}

char		*convert_long(long int val, int base)
{
	int					neg;
	int					count;
	char				*ret;
	const char			*str;
	unsigned long int	value;

	neg = 0;
	value = 0;
	if (base < 2 && base > 16)
		return (NULL);
	init_value(&value, val, base, &neg);
	count = long_len(value, base) + neg;
	str = "0123456789abcdef";
	if (!(ret = (char*)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	ret[count] = '\0';
	while (count-- > neg)
	{
		ret[count] = str[(value % base)];
		value /= base;
	}
	neg == 1 ? ret[0] = '-' : 0;
	return (ret);
}

void		do_long(va_list arg, char c, t_core *core)
{
	long int	i;
	char		*to_add;

	i = 0;
	to_add = NULL;
	if (c == 'D')
	{
		i = (long int)va_arg(arg, long int);
		to_add = convert_long(i, 10);
	}
	else if (c == 'O')
	{
		i = (unsigned long)va_arg(arg, unsigned long);
		to_add = convert_long(i, 8);
	}
	else if (c == 'U')
	{
		i = (unsigned long int)va_arg(arg, unsigned long int);
		to_add = convert_long(i, 10);
	}
	concat_int(i, c, &to_add, core);
	final_concat(core, to_add);
}
