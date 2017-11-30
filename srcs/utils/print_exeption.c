/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_exeption.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 10:22:35 by ddinaut           #+#    #+#             */
/*   Updated: 2017/11/27 20:46:07 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		print_exeption(long long int i, t_opt opt)
{
	if ((opt.flags & FLAG_SPACE) && (i >= 0) && (opt.flags & FLAG_SIGN) == 0)
	{
		ft_putchar(' ');
		return (1);
	}
	else if ((opt.flags & FLAG_SIGN) && (i >= 0))
	{
		ft_putchar('+');
		return (1);
	}
	return (0);
}
