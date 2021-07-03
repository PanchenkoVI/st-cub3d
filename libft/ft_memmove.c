/*
* Created: 2020/10/27 17:21:07
*/

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t				n;
	unsigned char		*str;
	unsigned const char	*s;

	if (!dest && !src)
		return (NULL);
	n = 0;
	str = dest;
	s = src;
	if (str < s)
	{
		while (len > n)
		{
			str[n] = s[n];
			n++;
		}
	}
	else
	{
		while (len-- > n)
			str[len] = s[len];
	}
	return (dest);
}
