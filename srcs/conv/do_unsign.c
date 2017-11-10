/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_unsign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:15:57 by ddinaut           #+#    #+#             */
/*   Updated: 2017/11/10 20:07:31 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_len(int i, int base)
{
	int len;

	len = 1;
	while (i /= base)
		len++;
	return (len);
}

char	*ft_convert(int value, int base, char *str)
{
	int		count;
	char	*ret;

	count = ft_len(value, base);
	if (!(ret = (char*)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	ret[count] = '\0';
	while (count--)
	{
		ret[count] = str[value % base];
		value /= base;
	}
	return (ret);
}

void	print_unsign(t_opt opt, unsigned long long int i, char c)
{
	char	*str;

	(void)opt;
	str = NULL;
	if (c == 'o')
		str = ft_itoa_base(i, 8);
	else if (c == 'u')
		str = ft_itoa_base(i, 10);
	else if (c == 'x')
		str = ft_convert(i, 16, "0123456789abcdef");
	else if (c == 'X')
		str = ft_convert(i, 16, "0123456789ABCDEF");
	if (str == NULL)
		return ;
	ft_putstr(str);
	free(str);
}

void	do_unsign(va_list arg, t_opt opt, char c)
{
	unsigned long long int i;

		if (opt.len_mod == MOD_L)
		i = (unsigned long)va_arg(arg, long long int);
	else if (opt.len_mod == MOD_LL)
		i = (unsigned long long)va_arg(arg, long long int);
	else if (opt.len_mod == MOD_H)
		i = (unsigned short)va_arg(arg, long long int);
	else if (opt.len_mod == MOD_HH)
		i = (unsigned char)va_arg(arg, long long int);
	else if (opt.len_mod == MOD_J)
		i = (uintmax_t)va_arg(arg, long long int);
	else if (opt.len_mod == MOD_T)
		i = (ptrdiff_t)va_arg(arg, long long int);
	else if (opt.len_mod == MOD_Z)
		i = (size_t)va_arg(arg, long long int);
	else
		i = (unsigned int)va_arg(arg, long long int);
	print_unsign(opt, i, c);
}
