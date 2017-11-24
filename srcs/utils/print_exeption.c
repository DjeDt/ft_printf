/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_exeption.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 10:22:35 by ddinaut           #+#    #+#             */
/*   Updated: 2017/11/24 10:27:14 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_exeption(long long int i, t_opt opt)
{
	if ((opt.flags & SPACE) && (i >= 0) && (opt.flags & SIGN) == 0)
		ft_putchar(' ');
	else if ((opt.flags & SIGN) && (i >= 0))
		ft_putchar('+');
}
