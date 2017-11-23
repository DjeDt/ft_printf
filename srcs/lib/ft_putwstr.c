/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 10:25:28 by ddinaut           #+#    #+#             */
/*   Updated: 2017/11/23 10:26:50 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putwstr(const wchar_t *str, t_opt opt)
{
	if (str)
	{
		if (opt.precision > 0)
			while (*str && (opt.precision-- > 0))
				ascii_to_utf8(*str++);
		else
			while (*str)
				ascii_to_utf8(*str++);
	}
}
