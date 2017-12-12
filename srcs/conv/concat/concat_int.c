/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 12:43:14 by ddinaut           #+#    #+#             */
/*   Updated: 2017/12/08 13:14:41 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*int_width(char *add, t_opt opt)
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

char	*int_precision(char *add, t_opt opt)
{
	char	*ret;
	char	*tmp;

	ret = NULL;
	tmp = ft_strsub(add, 0, opt.precision);
	if (tmp != NULL)
		ret = int_width(tmp, opt);
	else
		ret = int_width(add, opt);
	return (ret);
}

char	*keep_sign(char *sign, char *add, char c, t_opt opt)
{
	int		len;
	char	*save;
	char	*ret;

	ret = NULL;
	len = ft_strlen(add);
	save = ft_strsub(add, 1, len);
	if (save != NULL)
	{
		ret = concat_int(save, c ,opt);
		ret = ft_strjoin_fr(sign, ret);
		free(save);
	}
	else
	{
		if (opt.precision > 0)
		{
			if (opt.precision > len)
				opt.precision = len;
			ret = int_precision(add, opt);
		}
		else
			ret = int_width(add, opt);
	}
	return (ret);
}

char	*concat_int(char *to_add, char c, t_opt opt)
{
	int		len;
	char	*ret;
	char	test[2];

	(void)c;
	ret = NULL;
	len = ft_strlen(to_add);
	if ((oneof("- +", to_add[0])) && (opt.flags & FLAG_ZERO))
	{
		test[0] = to_add[0];
		ret = keep_sign(test, to_add, c, opt);
	}
	else
	{
		if (opt.precision > 0)
		{
			if (opt.precision > len)
				opt.precision = len;
			ret = int_precision(to_add, opt);
		}
		else
			ret = int_width(to_add, opt);
	}
	return (ret);
}
