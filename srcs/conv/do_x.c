#include "printf.h"

static int	ft_len(int i, int base)
{
	int len;

	len = 1;
	while (i /= base)
		len++;
	return (len);
}

static char	*ft_convert(int value, int base, char *str)
{
	int			count;
	char		*ret;

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


void	do_x(va_list arg, char c)
{
	unsigned int	i;
	char			*str;

	if (c == 'x')
	{
		i = va_arg(arg, int);
		str = ft_convert(i, 16, "0123456789abcdef");
	}
	else if (c == 'X')
	{
		i = va_arg(arg, int);
		str = ft_convert(i, 16, "0123456789ABCDEF");
	}
	if (str)
	{
		ft_putstr(str);
		free(str);
	}
}
