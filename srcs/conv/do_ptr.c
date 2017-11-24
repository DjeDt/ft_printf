/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:15:07 by ddinaut           #+#    #+#             */
/*   Updated: 2017/11/24 09:33:18 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int		addr_len(unsigned long value, int base)
{
	int ret;

	ret = 1;
	while (value /= base)
		ret++;
	return (ret);
}

char	*get_addr(unsigned long value, int base)
{
	int			count;
	char		*ret;
	const char	*str;

	count = addr_len(value, base) + 2;
	str = "0123456789abcdef";
	if (!(ret = (char*)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	ret[count] = '\0';
	while (count-- > 2)
	{
		ret[count] = str[(value % base)];
		value /= base;
	}
	ret[1] = 'x';
	ret[0] = '0';
	return (ret);

}

void	do_ptr(va_list arg, t_opt opt, char c)
{
	void	*tmp;

	tmp = NULL;
	if (c == 's' || c == 'S')
	{
		if (opt.len_mod == MOD_L || c == 'S')
		{
			tmp = (wchar_t*)va_arg(arg, wchar_t*);
			print_ptr_S(tmp, opt);
		}
		else
		{
			tmp = (char*)va_arg(arg, char*);
			print_ptr_s(tmp, opt);
		}
	}
	else if (c == 'p')
	{
		tmp = (void*)va_arg(arg, void*);
		print_ptr_p(tmp, opt);
	}
}
