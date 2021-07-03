/*
* Created: 2020/10/27 17:21:07
*/

#include "libft.h"

static void	*free_memory(char **spr)
{
	int i;

	i = 0;
	while (spr[i])
	{
		free(spr[i]);
		i++;
	}
	free(spr);
	return (NULL);
}

static int	ft_words(const char *s, char c)
{
	int words;
	int	i;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			words++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (words);
}

static int	ft_ch(char const *s, char c)
{
	int i;

	i = 0;
	while (*s != c && s[i] != '\0')
		i++;
	return (i);
}

static char	**ft_split2(char const *s, char c, char **spr)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != '\0')
		{
			if (!(spr[i] = (char *)malloc(sizeof(char) * (ft_ch(s, c) + 1))))
				return (free_memory(spr));
			while (*s != c && *s)
				spr[i][n++] = *s++;
			spr[i++][n] = '\0';
			n = 0;
		}
	}
	spr[i] = NULL;
	return (spr);
}

char		**ft_split(char const *s, char c)
{
	char	**spr;
	int		words;

	if (!s)
		return (NULL);
	words = ft_words(s, c);
	spr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!spr)
		return (NULL);
	return (ft_split2(s, c, spr));
}
