/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:15:07 by ddinaut           #+#    #+#             */
/*   Updated: 2017/11/30 19:27:33 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		addr_len(unsigned long value, int base)
{
	int ret;

	ret = 1;
	while (value /= base)
		ret++;
	return (ret);
}

char	*get_addr(unsigned long value, int base, t_opt opt)
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
	if (opt.flags & FLAG_ALT)
	{
		ret[1] = 'X';
		ret[0] = '0';
	}
	else
	{
		ret[1] = 'x';
		ret[0] = '0';
	}
	return (ret);
}

int		do_ptr(va_list arg, t_opt opt, char c, void **final)
{
	int		ret;
	void	*to_add;

	to_add = NULL;
	if (c == 's' || c == 'S')
	{
		if (opt.len_mod == MOD_L || c == 'S')
			to_add = (wchar_t*)va_arg(arg, wchar_t*);
		else
			to_add = (char*)va_arg(arg, char*);
		if (to_add == NULL)
			to_add = "(null)";
	}
	else if (c == 'p')
	{
		to_add = (void*)va_arg(arg, void*); /* Check si leaks */
		to_add = get_addr((unsigned long)to_add, 16, opt);
	}
	ret = concat_to_str(final, to_add, opt);
	return (ret);
}
