/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 20:09:36 by ddinaut           #+#    #+#             */
/*   Updated: 2017/12/13 18:09:50 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*
**	ft_strcat :
**	-> append s1 to s2, overwriting the terminating null byte at the end of s1
**	   and then adds a terminating null byte
*/

char	*ft_strcat(char *s1, const char *s2)
{
	char			*ret;
	unsigned char	*str;

	ret = s1;
	str = (unsigned char *)s2;
	while ((*ret) != '\0')
		ret++;
	while ((*str) != '\0')
		(*ret++) = (*str++);
	(*ret) = '\0';
	return (s1);
}
