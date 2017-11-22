/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:58:52 by ddinaut           #+#    #+#             */
/*   Updated: 2017/11/22 19:27:00 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		get_width(t_opt opt, char *str)
{
	int ret;

	ret = opt.width - ft_strlen(str);
	if (opt.flags & SPACE)
		ret -= 1;
	if (opt.flags & SIGN)
		ret -= 1;
	return (ret);
}
