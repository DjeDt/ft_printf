/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_final.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 19:29:28 by ddinaut           #+#    #+#             */
/*   Updated: 2017/12/14 22:51:49 by ddinaut          ###   ########.fr       */
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

void	concat_final(void **final, void *padded)
{
	char	*new;

	new = ft_strjoin((*final), padded);
	free((*final));
	(*final) = new;
}

int		concat_to_str(void **base, void *add, char c, t_opt opt)
{
	int		ret;
	char	*padded;

	padded = NULL;

	if (opt.type & NO_CONV)
	{
		concat_final(base, add);
		ret = ft_strlen(add);
		return (ret);
	}
	else if (opt.type & CONV_CHR)
	{
		concat_final(base, add);
		ret = ft_strlen(add);
		return (ret);
	}
	else if (opt.type & CONV_INT)
	{
		concat_final(base, add);
		ret = ft_strlen(add);
		return  (ret);
	}
	else if (opt.type & CONV_LNG)
	{
		concat_final(base, add);
		ret = ft_strlen(add);
		return  (ret);
	}
	else if (opt.type & CONV_UNS)
	{
		concat_final(base, add);
		ret = ft_strlen(add);
		return (ret);
		(void)c;
	}
	else if (opt.type & CONV_PTR)
	{
		concat_final(base, add);
		ret = ft_strlen(add);
		return (ret);
	}
	if (padded == NULL)
		return (-1);
	concat_final(base, padded);
	ret = ft_strlen(padded);
	ft_strdel(&padded);
	return (ret);
}


