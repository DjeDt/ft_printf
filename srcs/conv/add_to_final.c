/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_final.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 19:29:28 by ddinaut           #+#    #+#             */
/*   Updated: 2017/12/08 13:14:12 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*create_padding(int size, char c)
{
	char	*ret;
	int		count;

	ret = NULL;
	count = 0;
	if (size < 1)
		return (NULL);
	if (!(ret = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (count < size)
		ret[count++] = c;
	ret[count] = '\0';
	return (ret);
}

int		concat_to_str(void **base, void *add, char c, t_opt opt)
{
	int		ret;
	char	*padded;

	padded = NULL;
	if (opt.type & NO_CONV)
		padded = concat_char(add, opt);
	else if (opt.type & CONV_CHR)
		padded = concat_char(add, opt);
	else if (opt.type & CONV_INT)
		padded = concat_int(add, c, opt);
	else if (opt.type & CONV_PTR)
		padded = concat_ptr(add, opt);
	else if (opt.type & CONV_LNG)
		padded = concat_int(add, c, opt);
	else if (opt.type & CONV_UNS)
		padded = concat_unsign(add, c, opt);
	if (padded == NULL)
		return (-1);
	ret = ft_strlen(padded);
	(*base) = ft_strjoin_fl((*base), padded);
	ft_strdel(&padded);
	return (ret);
}