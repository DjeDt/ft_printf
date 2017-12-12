/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:15:44 by ddinaut           #+#    #+#             */
/*   Updated: 2017/12/08 11:55:03 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*convert_int(long long int value, int base)
{
	int			neg;
	int			count;
	char		*ret;
	const char	*str;

	neg = 0;
	if (value < 0)
	{
		neg = 1;
		value *= (-1);
	}
	count = nbr_len(value, base) + neg;
	str = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if (!(ret = (char*)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	ret[count] = '\0';
	while (count-- > neg)
	{
		ret[count] = str[(value % base)];
		value /= base;
	}
	neg == 1 ? ret[0] = '-' : 0;
	return (ret);
}

int		check_int_exception(long long int i, t_opt opt)
{
	if ((opt.flags & FLAG_SPACE) && (i >= 0) && ((opt.flags & FLAG_SIGN) == 0))
		return (1);
	else if ((opt.flags & FLAG_SIGN) && (i >= 0))
		return (2);
	return (0);
}

char	*do_int_exeption(long long int i, t_opt opt, char *to_add)
{
	if (check_int_exception(i, opt) == 1)
		to_add = ft_strjoin_fr(" ", to_add);
	else if (check_int_exception(i, opt) == 2)
		to_add = ft_strjoin_fr("+", to_add);
	return (to_add);
}

int		do_int(va_list arg, t_opt opt, char c, void **final)
{
	int				ret;
	long long int	i;
	char			*to_add;

	to_add = NULL;
	opt.type = CONV_INT;
	if (opt.len_mod == MOD_L)
		i = (long)va_arg(arg, long long int);
	else if (opt.len_mod == MOD_LL)
		i = (long long)va_arg(arg, long long int);
	else if (opt.len_mod == MOD_H)
		i = (short)va_arg(arg, long long int);
	else if (opt.len_mod == MOD_HH)
		i = (signed char)va_arg(arg, long long int);
	else if (opt.len_mod == MOD_J)
		i = (intmax_t)va_arg(arg, long long int);
	else if (opt.len_mod == MOD_T)
		i = (ptrdiff_t)va_arg(arg, long long int);
	else if (opt.len_mod == MOD_Z)
		i = (size_t)va_arg(arg, long long int);
	else
		i = (int)va_arg(arg, long long int);
	to_add = convert_int(i, 10);
	to_add = do_int_exeption(i, opt, to_add);
	ret = concat_to_str(final, to_add, c, opt);
	ft_strdel(&to_add);
	return (ret);
}
