/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:15:44 by ddinaut           #+#    #+#             */
/*   Updated: 2017/11/30 18:57:54 by ddinaut          ###   ########.fr       */
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

int		do_int(va_list arg, t_opt opt, char c, void **final)
{
	int				ret;
	long long int	i;
	void			*to_add;

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
	(void)c;
	to_add = convert_int(i, 10);
	if (check_int_exception(i, opt) == 1)
		to_add = ft_strjoin_fr(" ", to_add);
	else if (check_int_exception(i, opt) == 2)
		to_add = ft_strjoin_fr("+", to_add);
	ret = concat_to_str(final, to_add, opt);
	return (ret);
}
