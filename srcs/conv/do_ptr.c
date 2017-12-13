/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:15:07 by ddinaut           #+#    #+#             */
/*   Updated: 2017/12/13 18:50:51 by ddinaut          ###   ########.fr       */
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
	char	tmp[5];

	new = NULL;
	count = -1;
	if ((old_add) == NULL)
		return (NULL);
	while (old_add[++count] != '\0')
	{
		ch = old_add[count];
		char_to_str(ch, tmp);
		new = ft_strjoin_fl(new, tmp);
	}
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

int		do_ptr(va_list arg, t_opt opt, char c, void **final)
{
	int		ret;
	void	*to_add;

	ret = 0;
	to_add = NULL;
	opt.type = CONV_PTR;
	if (c == 's' || c == 'S')
	{
		if (opt.len_mod == MOD_L || c == 'S')
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
		to_add = get_addr((unsigned long)to_add, 16, opt);
	}
	ret = concat_to_str(final, to_add, c, opt);
	free(to_add);
	return (ret);
}
