/*
* Created: 2020/10/27 17:21:07
*/

#include "../header/cub3d.h"

void	ft_free2(char **str)
{
	int	n;

	n = 0;
	while (str[n])
	{
		free(str[n]);
		n++;
	}
	free(str);
}

int		ft_in_map(char n)
{
	int		i;
	char	*s;

	i = 0;
	s = MAP_IN;
	while (s[i])
	{
		if (s[i] == n)
			return (1);
		i++;
	}
	return (0);
}

int		ft(char n)
{
	int		i;
	char	*s;

	i = 0;
	s = MAP_INI;
	while (s[i])
	{
		if (s[i] == n)
			return (0);
		i++;
	}
	return (1);
}

int		ft_key_key2(char *str)
{
	static int	i = 4;

	if (str[0] == 'C')
		i = i - 1;
	if (str[0] == 'F')
		i = i - 3;
	return (i);
}

int		ft_comma(char *str)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			j++;
		i++;
	}
	if (j == 2)
		return (1);
	return (0);
}
