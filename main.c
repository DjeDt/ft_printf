/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:16:53 by ddinaut           #+#    #+#             */
/*   Updated: 2017/11/10 20:38:00 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_printf/includes/printf.h"

int main(void)
{
	printf("test de %%s\n");
	ft_printf("test de %%s\n");

	ft_printf("test de char * :\n");
	printf("test de %s", "test reussi\n");
	ft_printf("test de %s", "test reussi\n");

	ft_printf("Random nubers :\n");
	printf("%d %d %d %d %d\n", -123, 123, 0, 2147483647, -2147483648);
	ft_printf("%d %d %d %d %d\n", -123, 123, 0, 2147483647, -2147483648);
	return (0);
}
