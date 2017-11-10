#include "printf.h"

int		ft_len(int i, int base)
{
	int len;

	len = 1;
	while (i /= base)
		len++;
	return (len);
}

char	*ft_convert(int value, int base, char *str)
{
	int		count;
	char	*ret;

	count = ft_len(value, base);
	if (!(ret = (char*)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	ret[count] = '\0';
	while (count--)
	{
		ret[count] = str[value % base];
		value /= base;
	}
	return (ret);
}

void	print_unsign(t_opt opt, unsigned long long int i, char c)
{
	char	*str;

	(void)opt;
	str = NULL;
	if (c == 'o')
		str = ft_itoa_base(i, 8);
	else if (c == 'u')
		str = ft_itoa_base(i, 10);
	else if (c == 'o')
		str = ft_convert(i, 16, "0123456789abcdef");
	else if (c == 'X')
		str = ft_convert(i, 16, "0123456789ABCDEF");
	if (str == NULL)
		return ;
	ft_putstr(str);
	free(str);
}

void	do_unsign(va_list arg, t_opt opt, char c)
{
	unsigned long long int i;

	i = (unsigned int)va_arg(arg, long long int);
	print_unsign(opt, i, c);
}
