/*
* Created: 2020/10/27 17:21:07
*/

#include "../header/cub3d.h"

int		ft_color_f(t_all_info *all, char *str)
{
	char	**range;
	int		clr;
	int		n;

	if (!ft_comma(str))
		return (ft_print_err(all, 7));
	n = 0;
	if (!(range = ft_split(str, ',')))
		return (ft_print_err(all, 7));
	while (range[n])
		n++;
	if (!range || n != 3)
		return (ft_print_err(all, 7));
	if (!ft_sign(range[0]) || !ft_sign(range[1]) || !ft_sign(range[2]))
		return (ft_print_err(all, 7));
	if (!ft_sign3(range[0]) || !ft_sign3(range[1]) || !ft_sign3(range[2]))
		return (ft_print_err(all, 7));
	if (ft_enter_color(range[0], range[1], range[2]) == 1)
		return (ft_print_err(all, 7));
	clr = ft_clr(range);
	ft_free2(range);
	range = NULL;
	all->f_clr = clr;
	return (1);
}

int		ft_sign3(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

int		ft_sign2(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			while (str[i] >= '0' && str[i] <= '9')
				i++;
			break ;
		}
		i++;
	}
	return (i);
}

int		ft_sign(char *str)
{
	int		dig;
	int		i;
	int		flag;

	flag = 0;
	dig = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			dig++;
		i++;
	}
	if (dig == 0 || dig > 3)
		return (0);
	i = ft_sign2(str);
	while (str[i] == ' ')
		i++;
	if (str[i] >= '0' && str[i] <= '9')
		flag = 1;
	if (flag == 1)
		return (0);
	return (1);
}

int		ft_color_c(t_all_info *all, char *str)
{
	char	**range;
	int		clr;
	int		n;

	if (!ft_comma(str))
		return (ft_print_err(all, 6));
	n = 0;
	if (!(range = ft_split(str, ',')))
		return (ft_print_err(all, 6));
	while (range[n])
		n++;
	if (!range || n != 3)
		return (ft_print_err(all, 6));
	if (!ft_sign(range[0]) || !ft_sign(range[1]) || !ft_sign(range[2]))
		return (ft_print_err(all, 6));
	if (!ft_sign3(range[0]) || !ft_sign3(range[1]) || !ft_sign3(range[2]))
		return (ft_print_err(all, 6));
	if (ft_enter_color(range[0], range[1], range[2]) == 1)
		return (ft_print_err(all, 6));
	clr = ft_clr(range);
	ft_free2(range);
	range = NULL;
	all->c_clr = clr;
	return (1);
}
