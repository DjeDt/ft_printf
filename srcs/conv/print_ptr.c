/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 10:23:05 by ddinaut           #+#    #+#             */
/*   Updated: 2017/11/23 10:48:42 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_ptr_prefix(t_opt opt, int len)
{
	char	tmp[len];

	tmp[len] = '\0';
	while (len--)
		tmp[len] = opt.prefix;
	ft_putstr(tmp);
}

void	print_ptr_s(void *str, t_opt opt)
{
	int len;

	if (str != NULL)
	{
		len = get_width(opt, str);
		if (opt.flags & ALIGN)
		{
			if (opt.precision > 0)
				write(1, str, opt.precision);
			else
				ft_putstr(str);
			if (len > 0)
				print_ptr_prefix(opt, len);
		}
		else
		{
			if (len > 0)
				print_ptr_prefix(opt, len);
			if (opt.precision > 0)
				write(1, str, opt.precision);
			else
				ft_putstr(str);
		}
	}
	else
		ft_putstr("(null)");
}

void	print_ptr_S(void *str, t_opt opt)
{
	int len;

	if (str != NULL)
	{
		len = get_width(opt, str);
		if (opt.flags & ALIGN)
		{
			ft_putwstr(str, opt);
			if (len > 0)
				print_ptr_prefix(opt, len);
		}
		else
		{
			if (len > 0)
				print_ptr_prefix(opt, len);
			ft_putwstr(str, opt);
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
		len = get_width(opt, str);
		addr = (unsigned long)str;
		p = get_addr(addr, 16);
		if (opt.flags & ALIGN)
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
		write(1, "0x0", 3);
}
