/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:34:34 by ddinaut           #+#    #+#             */
/*   Updated: 2017/12/08 11:55:13 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*do_long_exeption(char *to_add, t_opt opt, long long int i)
{
	if (check_int_exception(i, opt) == 1)
		to_add = ft_strjoin_fr(" ", to_add);
	else if (check_int_exception(i, opt) == 2)
		to_add = ft_strjoin_fr("+", to_add);
	return (to_add);
}

int		do_long(va_list arg, t_opt opt, char c, void **final)
{
	int				ret;
	long long int	i;
	char			*to_add;

	to_add = NULL;
	opt.type = CONV_LNG;
	i = va_arg(arg, long long int);
	if (c == 'D')
		to_add = convert_int(i, 10);
	else if (c == 'O')
		to_add = convert_int(i, 8);
	else if (c == 'U')
		to_add = convert_int(i, 10);
	to_add = do_long_exeption(to_add, opt, i);
	ret = concat_to_str(final, to_add, c, opt);
	ft_strdel(&to_add);
	return (ret);
}
