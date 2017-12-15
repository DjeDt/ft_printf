/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat_unsign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 12:43:14 by ddinaut           #+#    #+#             */
/*   Updated: 2017/12/15 19:20:08 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	do_alter(char **str, char c, t_opt opt)
{
	char *new;

	new = NULL;
	if (opt.flags & FLAG_ALT)
	{
		if (c == 'o')
		{
			new = ft_strjoin("0", (*str));
			free((*str));
			(*str) = new;
		}
		else if (c == 'x')
		{
			new = ft_strjoin("0x", (*str));
			free((*str));
		(*str) = new;
		}
		else if (c == 'X')
		{
			new = ft_strjoin("0X", (*str));
			free((*str));
			(*str) = new;
		}
	}
}

void	unsign_precision(char **to_add, t_opt opt)
{
	int		len;
	char	*new;
	char	*padding;

	new = NULL;
	padding = NULL;
	len = opt.precision - ft_strlen((*to_add));
	if (len > 0)
	{
		padding = create_padding(len, '0');
		new = ft_strjoin(padding, (*to_add));
		free((*to_add));
		(*to_add) = new;
		if (padding)
			free(padding);
	}
}

int		check_unsign_exeption(char c, t_opt opt)
{
	if (opt.flags & FLAG_ALT)
	{
		if (c == 'o')
			return (1);
		else if (c == 'x' || c == 'X')
				return (2);
	}
	return (0);
}

void	unsign_width(char c, char **to_add, t_opt opt)
{
	int		len;
	char	*new;
	char	*padding;

	new = NULL;
	padding = NULL;
	len = opt.width - ft_strlen((*to_add));
	len -= check_unsign_exeption(c, opt);
	if (len > 0)
	{
		if (opt.flags & FLAG_LEFT)
		{
			do_alter(to_add, c, opt);
			padding = create_padding(len, ' ');
			new = ft_strjoin((*to_add), padding);
		}
		else
		{
			if (opt.prefix == ' ')
				do_alter(to_add, c, opt);
			padding = create_padding(len, opt.prefix);
			new = ft_strjoin(padding, (*to_add));
			if (opt.prefix != ' ')
				do_alter(&new, c, opt);
		}
		free((*to_add));
		(*to_add) = new;
		if (padding)
			free(padding);
	}
}

void	concat_unsign(unsigned long long int i, char c, char **to_add, t_core *core)
{
	if (i == 0)
	{
		if (core->opt.flags & FLAG_PREC)
		{
			if ((core->opt.flags & FLAG_ERR) || (core->opt.precision <= 0))
				(*to_add)[0] = '\0';
			if (core->opt.flags & FLAG_LDC)
				unsign_width(c, to_add, core->opt);
		}
	}
	else
	{
		if (core->opt.flags & FLAG_PREC)
		{
			unsign_precision(to_add, core->opt);
			if (core->opt.flags & FLAG_LDC)
				unsign_width(c, to_add, core->opt);
		}
		else if (core->opt.flags & FLAG_LDC)
			unsign_width(c, to_add, core->opt);
		else
			do_alter(to_add, c, core->opt);
	}
}
