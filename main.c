#include <stdio.h>
#include "includes/printf.h"

int main(void)
{
	unsigned int c;
	unsigned int cc;

	c = 42000450;
	cc = 0xFFEF;
//	ft_printf("1-> %x et %X", c, cc);
	ft_printf("1-> %c et %c", 'a', 'b');
	printf("\n");
	printf("1-> %c et %c", 'a', 'b');
//	printf("2-> %x et %X", c, cc);
	printf("\n");
	return (0);
}
