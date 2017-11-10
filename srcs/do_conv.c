/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:23:58 by ddinaut           #+#    #+#             */
/*   Updated: 2017/11/10 20:21:08 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	do_conv(const char *restrict format, int *count, va_list arg, t_opt opt)
{

	if (format[(*count)] == 'd' || format[(*count)] == 'i')
		do_int(arg, opt, format[(*count)]);
	else if (format[(*count)] == 'c' || format[(*count)] == 'C')
		do_char(arg, opt, format[(*count)]);
	else if (format[(*count)] == 'o' || format[(*count)] == 'u' || \
			 format[(*count)] == 'x' || format[(*count)] == 'X')
		do_unsign(arg, opt, format[(*count)]);
	else if (format[(*count)] == 's' || format[(*count)] == 'S' || format[(*count)] == 'p') /*ensuite DOU*/
		do_ptr(arg, opt, format[(*count)]);
	else if (format[(*count)] == 'D' || format[(*count)] == 'O' || format[(*count)] == 'U')
		do_long(arg, opt, format[(*count)]);
	else
		ft_putchar(format[(*count)]);
}
