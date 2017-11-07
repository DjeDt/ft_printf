#include "printf.h"

void	do_d(va_list arg)
{
	int i;

	i = va_arg(arg, int);
	ft_putnbr(i);
}
