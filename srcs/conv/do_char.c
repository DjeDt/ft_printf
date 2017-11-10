#include "printf.h"

void	print_char(wchar_t ch, t_opt opt)
{
	(void)opt; // pour les options d'affichage
	ft_putchar(ch);
}

void	do_char(va_list arg, t_opt opt, char c)
{
	wchar_t ch;

	(void)opt;
	if (c == 'c')
		ch = (char)va_arg(arg, int);
	else if (c == 'C')
		ch = (wchar_t)va_arg(arg, wint_t);
	print_char(ch, opt);
}
