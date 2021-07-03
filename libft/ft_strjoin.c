/*
* Created: 2020/10/27 17:21:07
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	n;
	size_t	m;
	char	*spr;

	if (!s1 || !s2)
		return (0);
	n = ft_strlen(s1);
	m = ft_strlen(s2);
	if (!(spr = (char *)malloc(sizeof(char) * (n + m + 1))))
		return (0);
	n = 0;
	while (s1[n])
	{
		spr[n] = s1[n];
		n++;
	}
	m = 0;
	while (s2[m])
	{
		spr[n + m] = s2[m];
		m++;
	}
	spr[n + m] = '\0';
	return (spr);
}
