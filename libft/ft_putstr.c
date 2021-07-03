/*
* Created: 2020/10/27 17:21:07
*/

#include "libft.h"

void	ft_putstr(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
}
