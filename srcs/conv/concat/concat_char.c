/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 09:59:37 by ddinaut           #+#    #+#             */
/*   Updated: 2017/12/13 12:15:57 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*char_width(char *add, t_opt opt)
{
	int		len;
	char	*ret;
	char	*padding;

	ret = NULL;
	padding = NULL;
	len = ft_strlen(add);
	len = opt.width - len;
	if ((opt.width > 1) && (len > 0))
	{
		padding = create_padding(len, opt.prefix);
		if (opt.flags & FLAG_LEFT)
			ret = ft_strjoin(add, padding);
		else
			ret = ft_strjoin(padding ,add);
		if (padding)
			free(padding);
	}
	else
		ret = ft_strdup(add);
	return (ret);
}

char	*char_precision(char *add, t_opt opt)
{
	char	*ret;
	char	*tmp;

	ret = NULL;
	tmp = ft_strsub(add, 0, opt.precision);
	if (tmp != NULL)
		ret = char_width(tmp, opt);
	else
		ret = char_width(add, opt);
	return (ret);
}

char	*concat_char(char *to_add, t_opt opt)
{
	int		len;
	char	*ret;

	ret = NULL;
	len = ft_strlen(to_add);
	len == 0 ? len = 1 : 0;
	if (opt.precision > 0)
	{
		if (opt.precision > len)
			opt.precision = len;
		ret = char_precision(to_add, opt);
	}
	else
		ret = char_width(to_add, opt);
	return (ret);
}
