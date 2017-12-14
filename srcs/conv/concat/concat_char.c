/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 09:59:37 by ddinaut           #+#    #+#             */
/*   Updated: 2017/12/14 16:17:41 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	char_width(char **to_add, t_opt opt)
{
	int		len;
	char	*new;
	char	*padding;

	new = NULL;
	padding = NULL;
	len = opt.width - ft_strlen((*to_add));
	if (len > 0)
	{
		padding = create_padding(len, opt.prefix);
		if (opt.flags & FLAG_LEFT)
			new = ft_strjoin((*to_add), padding);
		else
			new = ft_strjoin(padding, (*to_add));
		if (padding)
			free(padding);
		free((*to_add));
		(*to_add) = new;
	}
}

void	concat_char(char **to_add, t_opt opt)
{
	if (opt.flags & FLAG_LDC)
		char_width(to_add, opt);
}
