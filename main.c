#include <stdio.h>
#include "includes/printf.h"

int main(void)
{
	unsigned char c;
	char cc;

	c = 42;
	cc = 42;
//	ft_printf("1-> %s et %S", "test", "TEST");
//	printf("\n");
//	printf("2-> %s et %S", "test", "TEST");
	printf("2-> %hhd", c);
	printf("\n");
	return (0);
}
