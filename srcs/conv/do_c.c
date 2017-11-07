#include "printf.h"

void	do_c(va_list arg, char c)
{
	char	i;
	wchar_t ii;

	if (c == 'c')
	{
		i = (unsigned char)va_arg(arg, int);
		ft_putchar(i);
	}
	else if (c == 'C')
	{
		ii = (wchar_t)va_arg(arg, int);
		ft_putchar(ii);
	}
}
