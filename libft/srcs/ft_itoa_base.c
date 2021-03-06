#include "libft.h"

static int	conv_ex(unsigned long long nb)
{
	if (nb >= 10)
		return (nb - 10 + 'a');
	else
		return (nb + '0');
}

char	*ft_itoa_base(unsigned long long value, unsigned long long base)
{
	int					i;
	char				*str;
	unsigned long long	tmp;

	i = 1;
	tmp = value;
	while (tmp >= base)
	{
		tmp = tmp / base;
		i++;
	}
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	while (i--)
	{
		tmp = value % base;
		str[i] = conv_ex(tmp);
		value /= base;
	}
	return (str);
}
