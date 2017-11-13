/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:34:34 by ddinaut           #+#    #+#             */
/*   Updated: 2017/11/10 20:20:53 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_long(t_opt opt, unsigned long long int i, char c)
{
	char *str;

	str = NULL;
	if (c == 'D')
		str = ft_itoa_base(i, 10);
	else if (c == 'O')
		str = ft_itoa_base(i, 8);
	else if (c == 'U')
		str = ft_itoa_base(i, 10);
	if (str != NULL)
	{
		ft_putstr(str);
		free(str);
	}
	(void)opt;
}

void	do_long(va_list arg, t_opt opt, char c)
{
	long long int i;

	i = va_arg(arg, long long int);
	print_long(opt, i, c);
}
