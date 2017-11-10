#include "printf.h"

int		get_len(int i)
{
	int len;

	len = 1;
	while (i /= 10)
		len++;
	return (len);
}

void	do_d(va_list arg, t_opt opt)
{
	int		i;
	char	*str;

	i = va_arg(arg, int);
	str = ft_itoa_base(i, 10);
	if (!str)
		return ;
	ft_putstr(str);
	free(str);
	(void)opt;
/**
   if (cond_1(opt) == 1)
   comprendre ce que c'est le left align
   if (cond_2(opt) == 1)
   {
   len += 1;
   }
   if (cond_3(opt) == 1)
   len += opt.space - 1; // - 1 pour le signe
   if (cond_5(opt) == 1)
   len += opt.zero;
**/
}
