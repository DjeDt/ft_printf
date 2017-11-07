#include "printf.h"

int		ft_printf(const char *restrict format, ...)
{
	int				count;
	va_list			arg;

	count = -1;
	va_start(arg, format);
	while (format[++count] != '\0')
	{
		if (format[count] == '%')
		{
			++count;
			if (format[count] == 'd' || format[count] == 'i')
				do_d(arg);
			else if (format[count] == 'c' || format[count] == 'C')
				do_c(arg, format[count]);
			else if (format[count] == 'o')
				do_o(arg);
			else if (format[count] == 's' || format[count] == 'S')
				do_s(arg, format[count]);
			else if (format[count] == 'u')
				do_u(arg);
			else if (format[count] == 'x')
				do_x(arg);
			else if (format[count] == 'h')
			{
				if (format[count + 1] == 'h')
				{
					do_hh(arg);
					count++;
				}
			}
			else if (format[count] == '%')
				ft_putchar('%');
		}
		else
			ft_putchar(format[count]);
	}
	va_end(arg);
	return (0);
}