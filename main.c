/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddinaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:16:53 by ddinaut           #+#    #+#             */
/*   Updated: 2017/12/15 19:14:27 by ddinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "includes/printf.h"
#include <locale.h>


void	test_c(void)
{
	int ret;
	int ret2;

	ft_printf("TEST 'c' :\n\n");
	ft_printf("\nTest 1 :\n");
	ret = printf("real : %5c\n", 'd');
	ret2 = ft_printf("real : %5c\n", 'd');
	printf("Test2 : {real = %d} {mine = %d}\n", ret, ret2);

	ret = printf("real : %5c\n", '\0');
	ret2 = ft_printf("mine : %5c\n", '\0');
	printf("Test2 : {real = %d} {mine = %d}\n", ret, ret2);

	ft_printf("Test 2 :\n");
	ret = printf("real : %5c\n", 'a');
	ret2 = ft_printf("mine : %5c\n", 'a');
	printf("Test3 : {real = %d} {mine = %d}\n", ret, ret2);

	ft_printf("Test 3 :\n");
	ret = printf("real : %-5c et %2c et %c\n", 'a', 'b', 'c');
	ret2 = ft_printf("mine : %-5c et %2c et %c\n", 'a', 'b', 'c');
	printf("Test 1 : {real = %d} {mine = %d}\n", ret, ret2);

	wchar_t sign1 = L'中';
	wchar_t sign2 = L'文';
	wchar_t sign3 = L'ح';

	ft_printf("\nTest de l'utf8 :\n");
	ret2 = ft_printf("mine = %C et %C et %C\n", sign1, sign2, sign3);
	ret = printf("real = %C \net \n%C et\n %C\n", sign1, sign2, sign3);
	printf("Test C : {real = %d} {mine = %d}\n", ret, ret2);
}

void	test_int(void)
{
	int ret;
	int ret2;

	printf("Test int :\n");
	ft_printf("\nTest 1 :\n");
	ret = printf("real : %d et %- 8i et %-i et %-+d et %05d\n", 2, 1, -1, -10, 10);
	ret2 = ft_printf("mine : %d et %- 8i et %-i et %-+d et %05d\n",2 , 1, -1, -10, 10);
	printf("Test 1 : {real = %d} {mine = %d}\n", ret, ret2);


	ft_printf("\nTest 2 :\n");
	ret = printf("real3 = %+5d et %+10d\n", 50, -50);
	ret2 = ft_printf("mine3 = %+5d et %+10d\n", 50, -50);
	printf("Test 2 : {real = %d} {mine = %d}\n", ret, ret2);
}

void	test_modificateurs(void)
{
	int ret;
	int ret2;

	ft_printf("\nTest des modificateurs int :\n");
	ft_printf("\nTest 'l' :\n");
	long lmin = -2147483648;
	long lmax = 2147483647;
	ret = printf("real : lmin = %ld et lmax = %ld\n", lmin, lmax);
	ret2 = ft_printf("mine : lmin = %ld et lmax = %ld\n", lmin, lmax);
	ft_printf("Test 'l' : {real = %d} {mine = %d}\n", ret, ret2);

	ft_printf("\nTest 'll' :\n");
	long long llmin = -9223372036854775807; // erreur si +1, pourquoi?
	long long llmax = 9223372036854775807;
	ret = printf("real : llmin = %lld et llmax = %lld\n", llmin, llmax);
	ret2 = ft_printf("mine : llmin = %lld et llmax = %lld\n", llmin, llmax);
	ft_printf("Test ll : {real = %d} {mine = %d}\n", ret, ret2);

	ft_printf("\nTest 'h' :\n");
	short smin = -32768;
	short smax = 32767;
	ret = printf("real : smin = %hd et smax = %hd\n", smin, smax);
	ret2 = ft_printf("mine : smin = %hd et smax = %hd\n", smin, smax);
	ft_printf("Test 'h' : {real = %d} {mine = %d}\n", ret, ret2);

	ft_printf("\nTest 'hh' :\n");
	signed char cmax = -128;
	signed char cmin = 127;
	ret = printf("real : cmin = %hhd et cmax = %hhd\n", cmin, cmax);
	ret2 = ft_printf("mine : cmin = %hhd et cmax = %hhd\n", cmin, cmax);
	ft_printf("Test 'hh' : {real = %d} {mine = %d}\n", ret, ret2);

	ft_printf("\nTest 'j' :\n");
	ret = printf("real : imax = %ji\n", LONG_MAX);
	ret2 = ft_printf("mine : imax = %ji\n", LONG_MAX);
	ret = ft_printf("Test 'j' : {real = %d} {mine = %d}\n", ret, ret2);

}

void	test_long(void)
{
	int ret;
	int ret2;

	ft_printf("\nTest des modificateurs long :\n");
	ret = ft_printf("Test de 'D' :\n"); // Pas sur debian
	ret = printf("real : %D et %D\n", 1234, 1234);
	ret2 = ft_printf("mine : %D et %D\n", 1234, 1234);
	ft_printf("{real = %d} {mine = %d}\n", ret, ret2);

	ft_printf("Test2 :\n");
	ret = printf("real : %+15D et %010D\n", 1234, 1234);
	ret2 = ft_printf("mine : %+15D et %010D\n", 1234, 1234);
	ft_printf("{real = %d} {mine = %d}\n", ret, ret2);

	ft_printf("Test de 'U' :\n"); // Pas sur debian
	ret = printf("real : %U et %U\n", 1, 1);
	ret2 = ft_printf("mine : %U et %U\n", 1, 1);
	ft_printf("{real = %d} {mine = %d}\n", ret, ret2);
}

void	test_wstr(void)
{
	int ret;
	int	ret2;

	ret = 0;
	ret2 = 0;

	ft_printf("Test 1 :\n");
	wchar_t *wstr1 = L"كيف حالك ؟";
	wchar_t *wstr2 = L"你好嗎？";
	wchar_t *wstr3 = L"Πώς είσαι;";

	ret2 = ft_printf("mine = %S et %S et %S\n", wstr1, wstr2, wstr3);
	ret = printf("real = %S et %S et %S\n", wstr1, wstr2, wstr3);
	printf("Test S : {real = %d} {mine = %d}\n", ret, ret2);
}

void	test_ptr(void)
{
	int ret;
	int ret2;

	char s2[3];
	char *s = NULL;
	char c;

	ft_printf("\nTest des pointeurs :\n");
	ret = printf("real : p = %p et p = %p et p = %p et p = %p\n", s, &s2, &c, NULL);
	ret2 = ft_printf("mine : p = %p et p = %p et p = %p et p = %p\n", s, &s2, &c, NULL);
	ft_printf("Test1 : {real = %d} {mine = %d}\n\n", ret, ret2);

	ret = printf("real : p = %5p et p = %-15p et p = %15p et p = %p\n", s, &s2, &c, NULL);
	ret2 = ft_printf("mine : p = %5p et p = %-15p et p = %15p et p = %p\n", s, &s2, &c, NULL);
	ft_printf("Test1 : {real = %d} {mine = %d}\n\n", ret, ret2);

	ret = printf("real : s = %-10s et %s et %s\n", "test1", "test2", "test3");
	ret2 = ft_printf("mine : s = %-10s et %s et %s\n", "test1", "test2", "test3");
	ft_printf("Test ptr : {real = %d} {mine = %d}\n\n", ret, ret2);

	ret = printf("real : %s\n", "123");
	ret2 = ft_printf("mine : %s\n", "123");
	ft_printf("Test ptr : {real = %d} {mine = %d}\n\n", ret, ret2);

	char *test1 = "ceci est le test1";
	char *test2 = "c'est le test2";
	char *test3 = "encore un test numero 3";

	ret = printf("real : |%5s| - |%.5s| - |%5.5s| - |%-30.10s| - |%-40s|\n", test1, test1, test1, test2, test3);
	ret2 = ft_printf("mine : |%5s| - |%.5s| - |%5.5s| - |%-30.10s| - |%-40s|\n", test1, test1, test1, test2, test3);
	ft_printf("Test s : {real = %d} {mine = %d}\n\n", ret, ret2);

	ret = printf("real : |%10.5s|\n", test1);
	ret2 = ft_printf("real : |%10.5s|\n", test1);
	ft_printf("Test s : {real = %d} {mine = %d}\n\n", ret, ret2);

	ret = printf("real : |%-10.20s|\n", "123456789123456");
	ret2 = ft_printf("real : |%-10.20s|\n", "123456789123456");
	ft_printf("Test s : {real = %d} {mine = %d}\n", ret, ret2);

	ret = printf("real : %s et p : %p\n", NULL, NULL);
	ret2 = ft_printf("mine : %s et p : %p\n", NULL, NULL);
	ft_printf("Test s : {real = %d} {mine = %d}\n\n", ret, ret2);

	ret = printf("real : |%-30.10s|\n", test2);
	ret2 = ft_printf("mine : |%-30.10s|\n", test2);
	ft_printf("Test s : {real = %d} {mine = %d}\n\n", ret, ret2);

	ret = printf("real : |%s| et |%20.15s|\n", "", "coucou je fais plus de vingts caracteres de long");
	ret2 = ft_printf("mine : |%s| et |%20.15s|\n", "", "coucou je fais plus de vingts caracteres de long");
	ft_printf("Test s : {real = %d} {mine = %d}\n", ret, ret2);
}

void	test_unsign(void)
{
	int ret;
	int ret2;

	unsigned int o = 123;
	ret = printf("real : x = %x et x = %X x = %#x et X = %#X et o = %#o\n", o, o, o, o, o);
	ret2 = ft_printf("real : x = %x et x = %X x = %#x et X = %#X et o = %#o\n", o, o, o, o, o);
	ft_printf("Test # : {real = %d} {mine = %d}\n", ret, ret2);

	ret = printf("real : %.2x\n", 5427);
	ret2 = ft_printf("mine : %.2x\n", 5427);
	ft_printf("Test x : {real = %d} {mine = %d}\n", ret, ret2);

	ret = printf("real : %5.2x\n", 5427);
	ret2 = ft_printf("mine : %5.2x\n", 5427);
	ft_printf("Test x : {real = %d} {mine = %d}\n", ret, ret2);

	ret = printf("real : %#08x\n", 42);
	ret2 = ft_printf("mine : %#08x\n", 42);
	ft_printf("Test x# : {real = %d} {mine = %d}\n\n", ret, ret2);
}

void	test_vrac(void)
{
	int ret;
	int ret2;

	ret = 0;
	ret2 = 0;

	ret =  printf("real : %.2x\n", 5427);
	ret2 =  ft_printf("mine : %.2x\n", 5427);
	ft_printf("Result : {real = %d} {mine = %d}\n", ret, ret2);

	ret = printf("real : %05d\n", -5);
	ret2 = ft_printf("mine : %05d\n", -5);
	ft_printf("Result : {real = %d} {mine = %d}\n", ret, ret2);

	ret = printf("real : % 5d\n", -5);
	ret2 = ft_printf("mine : % 5d\n", -5);
	ft_printf("Result : {real = %d} {mine = %d}\n\n", ret, ret2);

}

void	test_unsign2(void)
{
	int ret;
	int ret2;

	ret = printf("real : |%5x|\n", 10);
	ret2 = ft_printf("mine : |%5x|\n", 10);
	ft_printf("Result : {real = %d} {mine = %d}\n\n", ret, ret2);

	ret = printf("real : |%3.6x|\n", 10);
	ret2 = ft_printf("mine : |%3.6x|\n", 10);
	ft_printf("Result : {real = %d} {mine = %d}\n\n", ret, ret2);

	ret = printf("real : |%.6x|\n", 10);
	ret2 = ft_printf("mine : |%.6x|\n", 10);
	ft_printf("Result : {real = %d} {mine = %d}\n\n", ret, ret2);

	ret = printf("real : |%#x|\n", 10);
	ret2 = ft_printf("mine : |%#x|\n", 10);
	ft_printf("Result : {real = %d} {mine = %d}\n\n", ret, ret2);


	ret = printf("real : |%#.x|\n", 0);
	ret2 = ft_printf("mine : |%#.x|\n", 0);
	ft_printf("Result : {real = %d} {mine = %d}\n\n", ret, ret2);

	ret = printf("real : %#x\n", 42);
	ret2 = ft_printf("mine : %#x\n", 42);
	ft_printf("Result : {real = %d} {mine = %d}\n\n", ret, ret2);

	ret = printf("real : %#08.5x\n", 42);
	ret2 = ft_printf("mine : %#08.5x\n", 42);
	ft_printf("Result : {real = %d} {mine = %d}\n\n", ret, ret2);

	ret = printf("real : %#0.5x\n", 42);
	ret2 = ft_printf("mine : %#0.5x\n", 42);
	ft_printf("Result : {real = %d} {mine = %d}\n\n", ret, ret2);


	ret = printf("real : %#08x\n", 42);
	ret2 = ft_printf("mine : %#08x\n", 42);
	ft_printf("Result : {real = %d} {mine = %d}\n\n", ret, ret2);
	ret = printf("real : %#8x\n", 42);
	ret2 = ft_printf("mine : %#8x\n", 42);
	ft_printf("Result : {real = %d} {mine = %d}\n\n", ret, ret2);

	ret = printf("real : %.4o\n", 12);
	ret2 = ft_printf("mine : %.4o\n", 12);
	ft_printf("Result : {real = %d} {mine = %d}\n\n", ret, ret2);

	ret = printf("real : %#8x\n", 42);
	ret2 = ft_printf("mine : %#8x\n", 42);
	ft_printf("Result : {real = %d} {mine = %d}\n\n", ret, ret2);

	ret = printf("real : %#.8x\n", 42);
	ret2 = ft_printf("mine : %#.8x\n", 42);
	ft_printf("Result : {real = %d} {mine = %d}\n\n", ret, ret2);

}

void	test_int2(void)
{
	int ret;
	int	ret2;

	ret = printf("real : %d\n", 55);
	ret2 = ft_printf("mine : %d\n", 55);
	ft_printf("Result : {real = %d} {mine = %d}\n\n", ret, ret2);

	ret = printf("real : %5d\n", -55);
	ret2 = ft_printf("mine : %5d\n", -55);
	ft_printf("Result : {real = %d} {mine = %d}\n\n", ret, ret2);

	ret = printf("real : %05d\n", 55);
	ret2 = ft_printf("mine : %05d\n", 55);
	ft_printf("Result : {real = %d} {mine = %d}\n\n", ret, ret2);

	ret = printf("real : %5.5d\n", 123456789);
	ret2 = ft_printf("mine : %5.5d\n", 123456789);
	ft_printf("Result : {real = %d} {mine = %d}\n\n", ret, ret2);

	ret = printf("real : {%+10.9d}\n", 123);
	ret2 = ft_printf("mine : {%+10.9d}\n", 123);
	ft_printf("Result : {real = %d} {mine = %d}\n\n", ret, ret2);
}

void	test_int3(void)
{
	int ret;
	int ret2;


	ret = printf("real : %010x\n", 542);
	ret2 = ft_printf("mine : z%010x\n", 542);
	ft_printf("Result : {real = %d} {mine = %d}\n\n", ret, ret2);

	ret = printf("real : %#08x\n", 42);
	ret2 = ft_printf("mine : %#08x\n", 42);
	ft_printf("Result : {real = %d} {mine = %d}\n\n", ret, ret2);

	ret = printf("real : %#.x %#.0x\n", 0, 0);
	ret2 = ft_printf("mine : %#.x %#.0x\n", 0, 0);
	ft_printf("Result : {real = %d} {mine = %d}\n\n", ret, ret2);
}

int		main(void)
{

	setlocale(LC_ALL, "en_US.UTF-8"); /* pour l'utf8 C*/

/*
	test_int();
	write(1, "\n", 1);
	test_int2();
	test_int3();
*/

	test_long();
	test_ptr();
	test_c();
	test_modificateurs();
	test_vrac();

	test_unsign();
	write(1, "\n", 1);
	test_unsign2();


//	printf("real : %#.x %#.0x\n\n", 0, 0);
	/*
	ft_printf("mine : %#.x %#.0x\n", 0, 0);

//	printf("real : %.x %.0x\n\n", 0, 0);
	ft_printf("mine : %.x %.0x\n", 0, 0);

//	printf("real : %5.x %5.0x\n\n", 0, 0);
	ft_printf("mine : %5.x %5.0x\n", 0, 0);

//	printf("real : %.o %.0o\n\n", 0, 0);
	ft_printf("mine : %.o %.0o\n", 0, 0);

//	printf("real : %5.o %5.0o\n\n", 0, 0);
	ft_printf("mine : %5.o %5.0o\n", 0, 0);
	*/
	return (0);
}
