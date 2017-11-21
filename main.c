/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:16:53 by ddinaut           #+#    #+#             */
/*   Updated: 2017/11/14 15:06:42 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "includes/printf.h"

int main(void)
{
	/*
	printf("real_char_1 = %-5c et %2c et %c\n", 'a', 'b', 'c');
	ft_printf("mine_char_1 = %-5c et %2c et %c\n", 'a', 'b', 'c');
	printf("real_char_2 = %5c\n", 'd');
	ft_printf("real_char_2 = %5c\n", 'd');
	printf("real2 = %- 8d et %-d et %-+d et %05d\n", 1, -1, -10, 10);
	ft_printf("mine2 = %- 8d et %-d et %-+d et %05d\n", 1, -1, -10, 10);
	printf("real3 = %+ 5d et %+ 10d\n", 50, -50);
	ft_printf("mine3 = %+ 5d et %+ 10d\n", 50, -50);

	ft_printf("\nTest des modificateurs int :\n");

	ft_printf("Test 'l' :\n");
	long lmin = -2147483648;
	long lmax = 2147483647;
	printf("real : lmin = %ld et lmax = %ld\n", lmin, lmax);
	ft_printf("mine : lmin = %ld et lmax = %ld\n", lmin, lmax);

	ft_printf("Test 'll' :\n");
	long long llmin = -9223372036854775807; // erreur si +1, pourquoi?
	long long llmax = 9223372036854775807;
	printf("real : llmin = %lld et llmax = %lld\n", llmin, llmax);
	ft_printf("mine : llmin = %lld et llmax = %lld\n", llmin, llmax);

	ft_printf("Test 'h' :\n");
	short smin = -32768;
	short smax = 32767;
	printf("real : smin = %hd et smax = %hd\n", smin, smax);
	ft_printf("mine : smin = %hd et smax = %hd\n", smin, smax);

	ft_printf("Test 'hh' :\n");
	signed char cmax = -128;
	signed char cmin = 127;
	printf("real : cmin = %hhd et cmax = %hhd\n", cmin, cmax);
	ft_printf("mine : cmin = %hhd et cmax = %hhd\n", cmin, cmax);

	ft_printf("Test 'j' :\n");
	intmax_t imax;
	printf("real : imax = %ji\n", INT64_MAX);
	ft_printf("mine : imax = %ji\n", INT64_MAX);

	ft_printf("\nTest des modificateurs long :\n");

	ft_printf("Test de 'D' :\n"); // Pas sur debian
	printf("real : %D et %D\n", 1234, 1234);
	//ft_printf("mine : %D et %D\n", 1234, 1234); segfault

	ft_printf("Test de 'U' :\n"); // Pas sur debian
	printf("real : %U et %U\n", 1, 1);
//	ft_printf("mine : %U et %U\n", 1, 1); segfault
	*/
	ft_printf("\nTest des pointeurs :\n");
	printf("real : s = %-10s et %s et %s\n", "test1", "test2", "test3");
	ft_printf("mine : s = %-10s et %s et %s\n", "test1", "test2", "test3");
	char *s = NULL;
	char s2[3];
	char c;
	printf("real : p = %p et p = %p et p = %p et p = %p\n", s, &s2, &c, NULL);
	ft_printf("mine : p = %p et p = %p et p = %p et p = %p\n", s, &s2, &c, NULL);

	wchar_t test1 = L'中';
	wchar_t test2 = L'文';
	wchar_t test3 = L'ح';

	ft_printf("Test de l'utf8 :\n");
	ft_printf("mine = %C et %C et %C\n", test1, test2, test3);
	printf("real = %C \net \n%C et\n %C\n", test1, test2, test3);

	wchar_t *wstr1 = L"كيف حالك ؟";
	wchar_t *wstr2 = L"你好嗎？";
	wchar_t *wstr3 = L"Πώς είσαι;";

	ft_printf("mine = %S et %S et %S\n", wstr1, wstr2, wstr3);
	printf("real = %S et %S et %S\n", wstr1, wstr2, wstr3);

	return (0);
}
