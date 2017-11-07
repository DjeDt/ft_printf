#include "printf.h"

void	do_c(va_list arg, char c)
{
	int i;
	wchar_t ii;

	if (c == 'c')
	{
		i = va_arg(arg, int);
		ft_putchar(i);
	}
	else if (c == 'C')
	{
		ii = (wchar_t)va_arg(arg, int);
		ft_putchar(ii);
	}
}
