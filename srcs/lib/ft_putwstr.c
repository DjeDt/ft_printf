/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 10:25:28 by ddinaut           #+#    #+#             */
/*   Updated: 2017/11/27 22:18:27 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_putwstr(const wchar_t *str, t_opt opt)
{
	int ret;

	ret = 0;
	if (str)
	{
		if (opt.precision > 0)
			while (*str && (opt.precision-- > 0))
				ret += ft_ascii_to_utf8(*str++);
		else
			while (*str)
				ret += ft_ascii_to_utf8(*str++);
	}
	return (ret);
}
