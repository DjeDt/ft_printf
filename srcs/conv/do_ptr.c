/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:15:07 by ddinaut           #+#    #+#             */
/*   Updated: 2017/11/14 15:25:59 by ddinaut          ###   ########.fr       */
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

void	print_ptr_prefix(t_opt opt, int len)
{
	char	tmp[len];

	tmp[len] = '\0';
	while (len-- > 0)
		tmp[len] = opt.prefix;
	ft_putstr(tmp);
}

void	print_ptr_s(void *str, t_opt opt)
{
	int len;

	if (str != NULL)
	{
		len = opt.width - ft_strlen(str) - opt.space - opt.sign;
		if (opt.align == 1)
		{
			ft_putstr(str);
			if (len > 0)
				print_ptr_prefix(opt, len);
		}
		else
		{
			if (len > 0)
				print_ptr_prefix(opt, len);
			ft_putstr(str);
		}
	}
	else
		ft_putstr("(null)");
}

/*
char	*upgrade_unicode(wchar_t c)
{
	if (c < (1 << 7))
	{
		
	}
}
*/

void	print_ptr_S(void *str, t_opt opt)
{
	int len;

	if (str != NULL)
	{
		len = opt.width - ft_strlen(str) - opt.space - opt.sign;
		if (opt.align == 1)
		{
			write(1, str, ft_strlen(str));
			if (len > 0)
				print_ptr_prefix(opt, len);
		}
		else
		{
			if (len > 0)
				print_ptr_prefix(opt, len);
			ft_putstr(str);
		}
	}
	else
		ft_putstr("(null)");
}

void	print_ptr_p(void *str, t_opt opt)
{
	void			*p;
	int				len;
	unsigned long	addr;

	p = NULL;
	if (str != NULL)
	{
		len = opt.width - ft_strlen(str) - opt.space - opt.sign;
		addr = (unsigned long)str;
		p = get_addr(addr, 16);
		if (opt.align == 1)
		{
			write(1, p, ft_strlen(p));
			if (len > 0)
				print_ptr_prefix(opt, len);
		}
		else
		{
			if (len > 0)
				print_ptr_prefix(opt, len);
			write(1, p, ft_strlen(p));
		}
		free(p);
	}
	else
		ft_putstr("(nil)");
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
