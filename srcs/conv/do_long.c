/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:34:34 by ddinaut           #+#    #+#             */
/*   Updated: 2017/12/19 18:34:34 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*convert_unsign(unsigned long long int value, int base)
{
	int						neg;
	int						count;
	char					*ret;
	const char				*str;
//	unsigned long long int	value;

	
	neg = 0;
	/*
	if (val < 0)
	{
		if (base == 10)
			neg = 1;
		value = val * (-1);
	}
	else
		value = val;
	*/
	count = nbr_len(value, base) + neg;
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
	unsigned long long int	i;
	char			*to_add;

	to_add = NULL;
	i = (unsigned long long)va_arg(arg, unsigned long long int);
	if (c == 'D')
		to_add = convert_unsign(i, 10);
	else if (c == 'O')
		to_add = convert_unsign(i, 8);
	else if (c == 'U')
		to_add = convert_unsign(i, 10);
	printf("i = %lld et add = %s\n", i, to_add);
	concat_int(i, c, &to_add, core);
	final_concat(core, to_add);
}
