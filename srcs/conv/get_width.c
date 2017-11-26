/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:58:52 by ddinaut           #+#    #+#             */
/*   Updated: 2017/11/26 19:02:31 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		get_width(t_opt opt, char *str)
{
	int		ret;
	size_t	len;

	ret = 0;
	len = ft_strlen(str);
	if (opt.width > len)
		ret = opt.width - len;
	else
		ret = opt.width;
	if (opt.flags & FLAG_SPACE)
		ret -= 1;
	if (opt.flags & FLAG_SIGN)
		ret -= 1;
	return (ret);
}
