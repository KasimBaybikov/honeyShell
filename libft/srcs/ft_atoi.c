#include "libft.h"
#include <limits.h>

int	ft_atoi(const char *str)
{
	int		minus;
	long	result;

	minus = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus = -minus;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (result > INT_MAX && minus == 1)
			return (-1);
		result = (result * 10) + *str - '0';
		str++;
	}
	return (result * minus);
}
