#include "printf.h"

void	do_u(va_list arg)
{
	unsigned long long int	i;
	char					*str;

	i = (unsigned int)va_arg(arg, long long int);
	str = ft_itoa_base(i, 10);
	if (!str)
		return ;
	ft_putstr(str);
	free(str);
}
