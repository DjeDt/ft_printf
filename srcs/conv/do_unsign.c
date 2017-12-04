/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_unsign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:15:57 by ddinaut           #+#    #+#             */
/*   Updated: 2017/12/04 16:50:16 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_convert_unsign(unsigned long long int value, int base, char *str)
{
	int		count;
	char	*ret;

	count = nbr_len(value, base);
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

void	*unsign_to_str(unsigned long long int i, void *add, char c, t_opt opt)
{
	if (c == 'o')
		add = ft_itoa_base(i, 8);
	else if (c == 'u')
		add = ft_itoa_base(i, 10);
	else if (c == 'x')
		add = ft_convert_unsign(i, 16, "0123456789abcdef");
	else if (c == 'X')
		add = ft_convert_unsign(i, 16, "0123456789ABCDEF");
	if (add == NULL)
		return (NULL);
	if (opt.flags & FLAG_ALT && (i != 0))
	{
		if (c == 'o')
			add = ft_strjoin_fr("0", add);
		else if (c == 'x')
			add = ft_strjoin_fr("0x", add);
		else if (c == 'X')
			add = ft_strjoin_fr("0X", add);
	}
	return (add);
}

int		do_unsign(va_list arg, t_opt opt, char c, void **final)
{
	int						ret;
	unsigned long long int	i;
	void					*to_add;

	to_add = NULL;
	if (opt.len_mod == MOD_L)
		i = (unsigned long)va_arg(arg, unsigned long long int);
	else if (opt.len_mod == MOD_LL)
		i = (unsigned long long)va_arg(arg, unsigned long long int);
	else if (opt.len_mod == MOD_H)
		i = (unsigned short)va_arg(arg, unsigned long long int);
	else if (opt.len_mod == MOD_HH)
		i = (unsigned char)va_arg(arg, unsigned long long int);
	else if (opt.len_mod == MOD_J)
		i = (uintmax_t)va_arg(arg, unsigned long long int);
	else if (opt.len_mod == MOD_T)
		i = (ptrdiff_t)va_arg(arg, unsigned long long int);
	else if (opt.len_mod == MOD_Z)
		i = (size_t)va_arg(arg, unsigned long long int);
	else
		i = (unsigned int)va_arg(arg, unsigned long long int);
	to_add = unsign_to_str(i, to_add, c, opt);
	ret = concat_to_str(final, to_add, opt);
	return (ret);
}
