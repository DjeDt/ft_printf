#include "printf.h"

void	do_hh(va_list arg)
{
	unsigned int i;

	i = va_arg(arg, int);
	ft_putnbr(i);
}
