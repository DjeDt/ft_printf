#include "printf.h"

void	print_ptr(void *str, t_opt opt, char c)
{
	if (c == 's')
		ft_putstr(str);
	else if (c == 'S') /* faire un putstr special pour l'unicode etendu */
		write(1, str, ft_strlen(str));
	/* trouver commment le p*/
	(void)opt;
}

void	do_ptr(va_list arg, t_opt opt, char c)
{
	void *tmp;

	if (c == 's')
		tmp = (char*)va_arg(arg, char*);
	else if (c == 'S')
		tmp = (wchar_t*)va_arg(arg, wint_t*);
	else if (c == 'p')
		tmp = (void*)va_arg(arg, void*);
	print_ptr(tmp, opt, c);
}
