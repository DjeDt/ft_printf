/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat_unsign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 12:43:14 by ddinaut           #+#    #+#             */
/*   Updated: 2017/12/13 22:25:59 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	do_alter(char **str, char c)
{
	char *new;

	new = NULL;
	if (c == 'o')
		new = ft_strjoin("0", (*str));
	else if (c == 'x')
		new = ft_strjoin("0x", (*str));
	else if (c == 'X')
		new = ft_strjoin("0X", (*str));
	free((*str));
	(*str) = new;
}

static char	*unsign_precision(char *add, t_opt opt)
{
	int		len;
	char	*ret;
	char	*padding;

	ret = NULL;
	padding = NULL;
	len = opt.precision - ft_strlen(add);
	if (len > 0)
	{
		padding = create_padding(len, '0');
		ret = ft_strjoin(padding, add);
		if (padding)
			free(padding);
	}
	else
		ret = ft_strdup(add);
	return (ret);
}

static char	*unsign_width(char *add, t_opt opt, char c)
{
	int		len;
	char	*ret;
	char	*padding;

	ret  = NULL;
	padding = NULL;
	if ((opt.flags & FLAG_ALT) && (opt.prefix == ' '))
		do_alter(&add, c);
	len = opt.width - ft_strlen(add);
	if (len > 0)
	{
		padding = create_padding(len, opt.prefix);
		if (opt.flags & FLAG_LEFT)
			ret = ft_strjoin(add, padding);
		else
			ret = ft_strjoin(padding, add);
		if (opt.flags & FLAG_ALT && opt.prefix == '0')
			do_alter(&ret, c);
		if (padding)
			free(padding);
		free(add);
	}
	else
	{
		ret = ft_strdup(add);
		if (opt.flags & FLAG_ALT)
			do_alter(&ret, c);
	}
	return (ret);
}

char	*concat_unsign(char *to_add, char c, t_opt opt)
{
	char	*ret;

	ret = NULL;

	if (opt.flags & FLAG_PREC)
	{
		ret = unsign_precision(to_add, opt);
		if (opt.flags & FLAG_ALT)
		{
			do_alter(&ret, c);
			opt.flags &= ~FLAG_ALT;
		}
		if (opt.flags & FLAG_LDC)
			ret = unsign_width(ret, opt, c);
	}
	else
	{
		ret = ft_strdup(to_add);
		if (opt.flags & FLAG_LDC || opt.flags & FLAG_ZERO)
			ret = unsign_width(ret, opt, c);
		else
		{
			if (opt.flags & FLAG_ALT)
				do_alter(&ret, c);
		}
	}
	return (ret);
}
