/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:04:44 by ddinaut           #+#    #+#             */
/*   Updated: 2017/11/07 16:12:35 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/printf.h"

int main(void)
{
	unsigned int c;
	unsigned int cc;

	c = 42000450;
	cc = 0xFFEF;
	ft_printf("1-> %x et %X", c, cc);
	printf("\n");
	printf("2-> %x et %X", c, cc);
	printf("\n");
	return (0);
}
