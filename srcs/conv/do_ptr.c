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
#include <stdio.h>

static int	get_ln(unsigned long value, int base)
{
	int len;

	len = 1;
	while (value /= base)
		len++;
	return (len);
}

char	*get_addr(unsigned long value, int base)
{
	int			count;
	char		*ret;
	const char	*str;

	count = get_ln(value, base) + 2;
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

void	print_ptr(void *str, t_opt opt, char c)
{
	void			*p;
	unsigned long	addr;

	p = NULL;
	if (c == 's' || c == 'S')
	{
		if (str == NULL)
			ft_putstr("(null)");
		else
			ft_putstr(str);
	}
	else if (c == 'p')
	{
		if (str != NULL)
		{
			addr = (unsigned long)str;
			p = get_addr(addr, 16);
			write(1, p, ft_strlen(p));
			free(p);
		}
		else
			ft_putstr("(nil)");
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
			tmp = (char*)va_arg(arg, char*);
	}
	else if (c == 'S')
		tmp = (wchar_t*)va_arg(arg, wint_t*);
	else if (c == 'p')
		tmp = (void*)va_arg(arg, void*);
	print_ptr(tmp, opt, c);
}
