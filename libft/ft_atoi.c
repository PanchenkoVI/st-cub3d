/*
* Created: 2020/10/27 17:21:07
*/

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		n;
	long	nb;

	n = 1;
	nb = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			n = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (nb * n > 2147483647)
			return (-1);
		if (nb * n < -2147483648)
			return (0);
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (nb * n);
}
