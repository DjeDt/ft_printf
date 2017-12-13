/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 10:20:25 by ddinaut           #+#    #+#             */
/*   Updated: 2017/12/13 19:59:22 by ddinaut          ###   ########.fr       */
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
	len = opt.width - ft_strlen(add);
	if (len > 0)
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
	char	*tmp;

	tmp = ft_strsub(add, 0, opt.precision);
	return (tmp);
}

char	*concat_ptr(void *add, t_opt opt)
{
	char	*ret;

	ret = NULL;
	if (opt.flags & FLAG_PREC)
	{
		ret = ptr_precision(add, opt);
		if (opt.flags & FLAG_LDC)
			return (ptr_width(ret, opt));
	}
	else
	{
		if (opt.flags & FLAG_LDC)
			ret = ptr_width(add, opt);
		else
			ret = ft_strdup(add);
	}
	return (ret);
}
