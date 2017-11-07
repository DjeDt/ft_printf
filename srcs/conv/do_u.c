#include "printf.h"

void	do_u(va_list arg)
{
	unsigned int	i;
	char			*str;

	i = va_arg(arg, unsigned int);
	str = ft_itoa_base(i, 10);
	ft_putstr(str);
	free(str);
}
