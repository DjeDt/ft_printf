/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:15:07 by ddinaut           #+#    #+#             */
/*   Updated: 2017/12/14 16:13:03 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	addr_len(unsigned long value, int base)
{
	int ret;

	ret = 1;
	while (value /= base)
		ret++;
	return (ret);
}

static char	*get_addr(unsigned long value, int base, t_opt opt)
{
	int			count;
	char		*ret;
	const char	*str;

	count = addr_len(value, base) + 2;
	str = "0123456789abcdef";
	if (!(ret = (char*)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	ret[count] = '\0';
	while (count-- > 2)
	{
		ret[count] = str[(value % base)];
		value /= base;
	}
	if (opt.flags & FLAG_ALT)
	{
		ret[count--] = 'X';
		ret[count] = '0';
	}
	else
	{
		ret[count--] = 'x';
		ret[count] = '0';
	}
	return (ret);
}

char	*transform_to_char(wchar_t *old_add)
{
	wchar_t	ch;
	int		count;
	char	*new;
	char	*tmp;

	new = NULL;
	count = -1;
	tmp = (char*)malloc(sizeof(char) * 5);
	if ((old_add) == NULL)
		return (NULL);
	while (old_add[++count] != '\0')
	{
		ch = old_add[count];
		char_to_str(ch, &tmp);
		new = ft_strjoin_fl(new, tmp);
	}
	free(tmp);
	return (new);
}

char	*transform_s(char *add)
{
	char	*ret;

	ret = NULL;
	if (add == NULL)
		ret = ft_strdup("(null)");
	else
		ret = ft_strdup(add);
	return (ret);
}

int		do_ptr(va_list arg, t_core *core, char c)
{
	void	*to_add;

	to_add = NULL;
	core->opt.type = CONV_PTR;
	if (c == 's' || c == 'S')
	{
		if (core->opt.len_mod == MOD_L || c == 'S')
		{
			to_add = (wchar_t*)va_arg(arg, wchar_t*);
			to_add = transform_to_char((wchar_t*)to_add);
		}
		else
		{
			to_add = (char*)va_arg(arg, char*);
			to_add = transform_s(to_add);
		}
	}
	else if (c == 'p')
	{
		to_add = (void*)va_arg(arg, void*);
		to_add = get_addr((unsigned long)to_add, 16, core->opt);
	}
	concat_ptr((char**)&to_add, core);
	concat_to_str(&core->final, to_add, c, core->opt);
	free(to_add);
	return (0);
}
