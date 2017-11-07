#include "printf.h"

void	do_s(va_list arg, char c)
{
	char *str;
	wchar_t	*sstr;

	if (c == 's')
	{
		str = va_arg(arg, char*);
		if (str)
			ft_putstr(str);
		else
			write(1, "null", 4);
	}
	else if (c == 'S')
	{
		sstr = (wchar_t*)va_arg(arg, wchar_t*);
		if (sstr)
			write(1, sstr, ft_strlen((const char*)sstr));
		else
			write(1, "null", 4);
	}
}
