/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat_unsign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 12:43:14 by ddinaut           #+#    #+#             */
/*   Updated: 2017/12/08 15:40:21 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*unsign_width(char *add, t_opt opt)
{
	int		len;
	char	*ret;
	char	*padding;

	ret  = NULL;
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

static char	*unsign_precision(char *add, t_opt opt)
{
	int		len;
	char	*ret;
	char	*padding;

	ret = NULL;
	padding = NULL;
	len = ft_strlen(add);
	len = opt.precision - len;
}


static char	*keep_prefix(char *add, int len, char c, t_opt opt)
{
	char	*ret;
	char	*save;

	ret = NULL;
	save = NULL;
	if (opt.precision > 0)
	{
		if (opt.precision > len)
			opt.precision = len;
		ret = unsign_precision(add, opt);
	}
	if (c == 'o')
		ret = ft_strjoin_fr("0", save);
	else if (c == 'x')
		ret = ft_strjoin_fr("0x", ret);
	else if (c == 'X')
		ret = ft_strjoin_fr("0X", ret);
	save = unsign_width(ret, opt);
	if (ret)
		free(ret);
	return (save);
}

char	*concat_unsign(char *to_add, char c, t_opt opt)
{
	int		len;
	char	*ret;

	ret = NULL;
	len = ft_strlen(to_add);
	if (opt.flags & FLAG_ALT)
	{
/*
		if (c == 'o')
			ret = ft_strjoin("0", ret);
		else if (c == 'x')
			ret = ft_strjoin_fr("0x", ret);
		else if (c == 'X')
			ret = ft_strjoin_fr("0X", ret);
*/
		ret = keep_prefix(to_add, len, c, opt);
	}
	else
	{
		if (opt.precision > 0)
			ret = unsign_precision(to_add, opt);
		else
			ret = unsign_width(to_add, opt);
	}
	return (ret);
}
