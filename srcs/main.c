/*
* Created: 2020/10/27 17:21:07
*/

#include "../header/cub3d.h"

int		ft_comparison(const char *s, const char *str)
{
	int		i;
	int		j;

	i = 0;
	if (s[0] == '-' && s[1] == '-' && s[2] == 's' && s[3] == 'a' && \
		s[4] == 'v' && s[5] == 'e' && (s[6] == '\0' || s[6] == ' '))
		i++;
	if ((j = open(str, O_RDONLY)) == -1)
		return (-1);
	return (i);
}

int		ft_two_arg(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		flag;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (s1[i - 4] == '.' && s1[i - 3] == 'c' && \
		s1[i - 2] == 'u' && s1[i - 1] == 'b')
	{
		i = ft_comparison(s2, s1);
		flag = i + 1;
		if (flag == 2)
			return (1);
		return (-1);
	}
	if (s2[j - 4] == '.' && s2[j - 3] == 'c' && \
		s2[j - 2] == 'u' && s2[j - 1] == 'b')
	{
		j = ft_comparison(s1, s2);
		flag = j + 1;
		if (flag == 2)
			return (2);
		return (-1);
	}
	return (-1);
}

int		ft_one_arg(const char *s1)
{
	int		i;
	int		flag;
	int		j;

	flag = 0;
	i = ft_strlen(s1);
	if (s1[i - 4] == '.' && s1[i - 3] == 'c' && \
		s1[i - 2] == 'u' && s1[i - 1] == 'b')
	{
		if ((j = open(s1, O_RDONLY)) == -1)
			return (-1);
		flag = 0;
	}
	else
		flag = -1;
	return (flag);
}

int		ft_main2(t_all_info *all, char *str)
{
	if (ft_start(all, str) != 1)
		return (ft_print_err(all, 22));
	if (ft_second_part(all, 0) != 1)
		return (ft_print_err(all, 23));
	return (0);
}

int		main(int argc, char **argv)
{
	t_all_info	all;
	int			n;

	if (argc > 3 || argc <= 0)
		return (ft_print_err(&all, 1));
	if (argv[1] == NULL)
		return (ft_print_err(&all, 1));
	else if (argv[1] != NULL && argv[2] == NULL)
		n = ft_one_arg(argv[1]);
	else
		n = ft_two_arg(argv[1], argv[2]);
	if (n == -1)
		return (ft_print_err(&all, 1));
	if (n == 2 || n == 1)
	{
		if (ft_start(&all, argv[n]) != 1)
			return (ft_print_err(&all, 22));
		if (ft_second_part(&all, 1) != 1)
			return (ft_print_err(&all, 23));
	}
	else if (n == 0)
	{
		ft_main2(&all, argv[1]);
	}
	return (0);
}
