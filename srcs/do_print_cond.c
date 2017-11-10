#include "printf.h"

int		cond_1(t_opt opt)
{
	if (opt.align == 1)
		return (1);
	return (0);
}

int		cond_2(t_opt opt)
{
	if (opt.sign == 1)
		return (1);
	return (0);
}

int		cond_3(t_opt opt)
{
	if (opt.sign == 0 && opt.space > 0)
		return (1);
	return (0);
}

int		cond_4(t_opt opt)
{
	if (opt.diez == 1)
		return (1);
	return (0);
}

int		cond_5(t_opt opt)
{
	if (opt.align == 0 && opt.zero > 0) /* return (0) si precision est donne pour certains flags */
		return (1);
	return (0);
}
