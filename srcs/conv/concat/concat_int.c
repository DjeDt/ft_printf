/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 12:43:14 by ddinaut           #+#    #+#             */
/*   Updated: 2017/12/15 19:37:08 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	int_alter(char c, long long int i, char **to_add, t_opt opt)
{
	char	*new;

	new = NULL;
	(void)c;
	if ((opt.flags & FLAG_SPACE) && (i >= 0) && ((opt.flags & FLAG_SIGN) == 0))
	{
		new = ft_strjoin(" ", (*to_add));
		free((*to_add));
		(*to_add) = new;
	}
	else if ((opt.flags & FLAG_SIGN) && (i >= 0))
	{
		new = ft_strjoin("+", (*to_add));
		free((*to_add));
		(*to_add) = new;
	}
}

void	int_width(char c, long long int i, char **to_add, t_opt opt)
{
	int		len;
	char	*new;
	char	*padding;

	new = NULL;
	padding = NULL;
	len = opt.width - ft_strlen((*to_add));
	if (check_int_exception(i, opt) > 0 && i >= 0)
		len -= 1;
	if (len > 0)
	{
		if (opt.flags & FLAG_LEFT)
		{
			int_alter(c, i, to_add, opt);
			padding = create_padding(len, ' ');
			new = ft_strjoin((*to_add), padding);
		}
		else
		{
			if (opt.prefix == ' ')
				int_alter(c, i, to_add, opt);
			padding = create_padding(len, opt.prefix);
			new = ft_strjoin(padding, (*to_add));
			if (opt.prefix != ' ')
				int_alter(c, i, &new, opt);
		}
		free((*to_add));
		(*to_add) = new;
		if (padding)
			free(padding);
	}
}

void	int_precision(char **to_add, t_opt opt)
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

void	move_sign(char **to_add)
{
	int		count;
	int		count2;

	count = 0;
	count2 = 0;
	while ((*to_add)[count] != '\0' && (*to_add)[count] != '-')
	{
		if ((*to_add)[count2] != '0')
			count2++;
		count++;
	}
	(*to_add)[count] = (*to_add)[count2];
	(*to_add)[count2] = '-';
}

void	special_case(long long int i, char **to_add, t_core *core)
{
	if (i < 0)
		move_sign(to_add);
	if (i == 0 && (core->opt.flags & FLAG_PREC) && core->opt.precision <= 0)
		(*to_add)[0] = '\0';
}

void	concat_int(long long int i, char c, char **to_add, t_core *core)
{
	if (core->opt.flags & FLAG_PREC)
	{
		int_precision(to_add, core->opt);
		if (core->opt.flags & FLAG_LDC)
		{
			int_alter(c, i, to_add, core->opt);
			core->opt.prefix = ' ';
			int_width(c, i, to_add, core->opt);
		}
	}
	else if (core->opt.flags & FLAG_LDC)
		int_width(c, i, to_add, core->opt);
	else
		int_alter(c, i, to_add, core->opt);
	special_case(i, to_add, core);
}
