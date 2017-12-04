/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_final.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 19:29:28 by ddinaut           #+#    #+#             */
/*   Updated: 2017/12/04 19:58:15 by ddinaut          ###   ########.fr       */
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

void	*check_precision(t_opt opt, void *add)
{
	int		cur;

	cur  = ft_strlen((add));
	if (opt.precision > 0)
	{
		if (opt.precision > 0)
			opt.precision = cur;
		if (!((add) = ft_strsub((add), 0, opt.precision)))
			return (NULL);
	}
	return (add);
}

char	*check_width(t_opt opt, void **add)
{
	int		cur;
	int		min;
	char	*padd;
	char	*add_p;

	padd  = NULL;
	add_p = NULL;
	cur = ft_strlen((*add));
	min = opt.width - cur;
	if ((opt.width > 0) && (min > 0))
		padd = create_padding(min, opt.prefix);
	if (opt.flags & FLAG_LEFT)
		add_p = ft_strjoin(*add, padd);
	else
		add_p = ft_strjoin(padd, *add);
	if (padd)
		free(padd);
	return (add_p);
}
/*
char	*pad_new_str(void *add, t_opt opt)
{
	char	*add_p;

	add_p = NULL;
	add_p = check_precision(opt, add);
	add_p = check_width(opt, &add);
	return (add_p);
}
*/

char	*pad_new_str(void *add, t_opt opt)
{
	int		min;
	int		curr;
	char	*add_p;
	char	*padd;

	add_p = NULL;
	padd = NULL;
	min = 0;
	curr = ft_strlen(add);
	if (opt.precision > 0)
	{
		if (opt.precision > curr)
			opt.precision = curr;
		add = ft_strsub(add, 0, opt.precision);
	}
	curr = ft_strlen(add);
	min = opt.width - curr;
	if ((opt.width > 0) && (min > 0))
		padd = create_padding(min, opt.prefix);

	if (opt.flags & FLAG_LEFT)
		add_p = ft_strjoin(add, padd);
	else
		add_p = ft_strjoin(padd, add);

	if (padd)
		free(padd);
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
	(*base) = ft_strjoin((*base), padded);
	ft_strdel(&padded);
	return (ret);
}
