/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_final.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 19:29:28 by ddinaut           #+#    #+#             */
/*   Updated: 2017/12/06 10:24:16 by ddinaut          ###   ########.fr       */
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

char	*check_width(t_opt opt, void *add)
{
	int		len;
	char	*ret;
	char	*padding;

	padding = NULL;
	len = ft_strlen(add);
	len = opt.width - len;
	if ((opt.width > 0) && (len > 0))
		padding = create_padding(len, opt.prefix);
	if (opt.flags & FLAG_LEFT)
		ret = ft_strjoin(add, padding);
	else
		ret = ft_strjoin(padding, add);
	if (padding != NULL)
		free(padding);
	return (ret);
}

char	*check_precision(t_opt opt, void *add)
{
	char	*tmp;
	char	*ret;

	tmp = NULL;
	ret = NULL;
	tmp = ft_strsub(add, 0, opt.precision);
	ret = check_width(opt, tmp);
	if (ret == NULL)
		return (tmp);
	free(tmp);
	return (ret);
}

char	*pad_new_str(void *add, t_opt opt)
{
	int		curr;
	char	*add_p;

	add_p = NULL;
	curr = ft_strlen(add);
	if (opt.precision > 0)
	{
		if (opt.precision > curr)
			opt.precision = curr;
		add_p = check_precision(opt, add);
	}
	else
		add_p = check_width(opt, add);
	return (add_p);
}

int		concat_to_str(void **base, void *add, t_opt opt)
{
	int		ret;
	char	*padded;

	padded = pad_new_str(add, opt);
	if (padded == NULL)
		return (-1);
	ret = ft_strlen(padded);
	(*base) = ft_strjoin_fl((*base), padded);
	ft_strdel(&padded);
	return (ret);
}
