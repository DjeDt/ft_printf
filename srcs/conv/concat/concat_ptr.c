/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 10:20:25 by ddinaut           #+#    #+#             */
/*   Updated: 2017/12/07 13:53:18 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ptr_width(void *add, t_opt opt)
{
	int		len;
	char	*ret;
	char	*padding;

	ret = NULL;
	padding = NULL;
	len = ft_strlen(add);
	len = opt.width - len;
	if ((opt.width > 0) && (len > 0))
	{
		padding = create_padding(len, opt.prefix);
		if (opt.flags & FLAG_LEFT)
			ret = ft_strjoin(add, padding);
		else
			ret = ft_strjoin(padding, add);
		if (padding)
			free(padding);
	}
	else
		ret = ft_strdup(add);
	return (ret);
}

char	*ptr_precision(void *add, t_opt opt)
{
	char	*ret;
	char	*tmp;

	ret = NULL;
	tmp = ft_strsub(add, 0, opt.precision);
	if (tmp != NULL)
		ret = ptr_width(tmp, opt);
	else
		ret = ptr_width(add, opt);
	return (ret);
}

char	*concat_ptr(void *add, t_opt opt)
{
	int		len;
	char	*ret;

	ret = NULL;
	len = ft_strlen(add);
	if (opt.precision > 0)
	{
		if (opt.precision > len)
			opt.precision = len;
		ret = ptr_precision(add, opt);
	}
	else
		ret = ptr_width(add, opt);
	return (ret);
}
