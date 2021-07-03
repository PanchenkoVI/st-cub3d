/*
* Created: 2020/10/27 17:21:07
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	sub;
	size_t	m;
	char	*spr;

	if (!s)
		return (NULL);
	m = 0;
	sub = ft_strlen(s);
	if (sub < start)
		len = 0;
	else
	{
		sub = sub - start;
		if (sub < len)
			len = sub;
	}
	if (!(spr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (m < len)
	{
		spr[m] = s[m + start];
		m++;
	}
	spr[m] = '\0';
	return (spr);
}
