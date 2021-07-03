/*
* Created: 2020/10/27 17:21:07
*/

#include "../header/cub3d.h"

int		ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	while (n > 0)
	{
		if (*s1 != *s2)
			return (1);
		if (*s1 == '\0' && *s2 == '\0')
			return (0);
		s1++;
		s2++;
		n--;
	}
	return (0);
}

int		ft_duptxtr(char *s1)
{
	int		i;
	char	*str;

	i = 2;
	str = ft_strdup("./textures/");
	if (s1[0] == 'S' && s1[1] == ' ')
		i--;
	while (s1[i] == ' ' || s1[i] == '\t')
		i++;
	if (ft_strncmp(s1 + i, str, 11) != 0)
	{
		free(str);
		return (0);
	}
	free(str);
	return (1);
}
