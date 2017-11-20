/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:34:34 by ddinaut           #+#    #+#             */
/*   Updated: 2017/11/14 14:42:13 by ddinaut          ###   ########.fr       */
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
		if (len > 0)
			print_long_prefix(len, opt);
	}
	else
	{
		if (len > 0)
			print_long_prefix(len, opt);
		if (opt.space == 1 && i >= 0 && opt.sign == 0)
			ft_putchar(' ');
		else if (opt.sign == 1 && i >= 0)
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
