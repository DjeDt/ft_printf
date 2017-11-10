/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 17:32:14 by ddinaut           #+#    #+#             */
/*   Updated: 2017/11/10 19:55:20 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_len(int i, int base)
{
	int len;

	len = 1;
	while (i /= base)
		len++;
	return (len);
}

char		*ft_itoa_base(int value, int base)
{
	int			count;
	char		*ret;
	const char	*str;

	count = ft_len(value, base);
	str = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if (!(ret = (char*)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	ret[count] = '\0';
	while (count--)
	{
		ret[count] = str[value % base];
		value /= base;
	}
	return (ret);
}
