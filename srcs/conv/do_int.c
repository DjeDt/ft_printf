#include "printf.h"

void	print_int(long long int i, t_opt opt)
{
	/* rajouter les options de opt ici */
	/* faire un putnbr modifier pour gerer les options d'affichage */
	ft_putnbr(i);
	(void)opt;
}

void	do_int(va_list arg, t_opt opt, char c)
{
	long long int i;

	(void)c;
	i = (int)va_arg(arg, long long int);
	print_int(i, opt);
}
