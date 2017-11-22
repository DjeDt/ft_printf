/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:34:34 by ddinaut           #+#    #+#             */
/*   Updated: 2017/11/22 18:05:18 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_long_prefix(int len, t_opt opt)
{
	char	tmp[len];

	tmp[len] = '\0';
	while (len-- > 0)
		tmp[len] = opt.prefix;
	ft_putstr(tmp);
}

void	print_long(t_opt opt, char *str, long long i)
{
	int len;

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
		if (len > 0)
			print_long_prefix(len, opt);
	}
	else
	{
		if (len > 0)
			print_long_prefix(len, opt);
		if ((opt.flags & SPACE) && i >= 0 && (opt.flags & SIGN) == 0)
			ft_putchar(' ');
		else if ((opt.flags & SIGN) && i >= 0)
			ft_putchar('+');
		ft_putstr(str);
	}
}

void	do_long(va_list arg, t_opt opt, char c)
{
	long long int	i;
	char			*str;

	str = NULL;
	i = va_arg(arg, long long int);
	if (c == 'D')
		str = ft_itoa_base(i, 10);
	else if (c == 'O')
		str = ft_itoa_base(i, 8);
	else if (c == 'U')
		str = ft_itoa_base(i, 10);
	if (str != NULL)
	{
		print_long(opt, str, i);
		free(str);
	}
}
