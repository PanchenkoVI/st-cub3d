/*
* Created: 2020/10/27 17:21:07
*/

#include "../header/cub3d.h"

char	*ft_minus_end(char *src)
{
	char	*str;
	int		m;
	int		n;

	if (!src)
		return (NULL);
	if ((n = ft_key_end_txtr(src)) == -1)
		return (NULL);
	n = ft_strlen(src) - n;
	if (!(str = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	m = 0;
	str[n] = '\0';
	while (n > 0)
	{
		str[n - 1] = src[n - 1];
		n--;
	}
	return (str);
}

int		ft_key_str_txtr(char *s1)
{
	int		i;

	i = 2;
	if (s1[0] == 'S' && s1[1] == ' ')
		i--;
	while (s1[i] == ' ' || s1[i] == '\t')
		i++;
	return (i);
}

int		ft_key_end_txtr(char *s1)
{
	int		i;
	int		j;

	j = 0;
	i = ft_strlen(s1);
	i--;
	while (s1[i] == ' ' || s1[i] == '\t')
	{
		j++;
		if (s1[i - 3] == '.' && s1[i - 2] == 'x' && \
			s1[i - 1] == 'p' && s1[i] == 'm')
			return (j);
		i--;
	}
	if (!(s1[i - 3] == '.' && s1[i - 2] == 'x' && \
		s1[i - 1] == 'p' && s1[i] == 'm'))
		return (-1);
	return (j);
}
