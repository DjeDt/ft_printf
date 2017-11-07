#include "printf.h"

void	do_o(va_list arg)
{
	unsigned int	i;
	char			*str;

	i = va_arg(arg, unsigned int);
	str = ft_itoa_base(i, 8);
	if (str)
	{
		ft_putstr(str);
		free(str);
	}
}
