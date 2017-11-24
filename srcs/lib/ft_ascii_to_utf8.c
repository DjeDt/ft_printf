/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ascii_to_utf8.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 09:29:46 by ddinaut           #+#    #+#             */
/*   Updated: 2017/11/24 09:32:09 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_ascii_to_utf8(wchar_t ch)
{
	if (ch <= 0x7F) // 127
		ft_putchar(ch);
	else if (ch <= 0x7FF) // 2047
	{
		ft_putchar((ch >> 6) + 0xC0); // + 192
		ft_putchar((ch & 0x3F) + 0x80); // (ch & 63) + 128 ->
	}
	else if (ch <= 0xFFFF) // 65535
	{
		ft_putchar((ch >> 12) + 0xE0); // (ch >> 12) + 224
		ft_putchar(((ch >> 6) & 0x3F) + 0x80); // (ch >> 6 & 63) + 128
		ft_putchar((ch & 0x3F) + 0x80); // (ch & 63) + 128
	}
	else if (ch <= 0x10FFFF) // 1114111
	{
		ft_putchar((ch >> 18) + 0xF0); // (ch >> 18) + 240
		ft_putchar(((ch >> 12) & 0x3F) + 0x80); // (ch >> 12) & 63 + 128
		ft_putchar(((ch >> 6) & 0x3F) + 0x80); // (ch >> 6) & 36 + 128
		ft_putchar((ch & 0x3F) + 0x80); // (ch >> 6 & 63) + 128
	}
}
