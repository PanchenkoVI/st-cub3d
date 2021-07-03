/*
* Created: 2020/10/27 17:21:07
*/

#include "../header/cub3d.h"

int		ft_digit(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else if (str[i] == '\t' || str[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

int		ft_atoi_rx(t_all_info *all, const char *str)
{
	int		i;
	long	nb;

	nb = 0;
	i = 0;
	if (DISPLAY_X <= 0)
		return (ft_print_err(all, 25));
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	(nb > DISPLAY_X) ? (nb = DISPLAY_X) : nb;
	return (nb);
}

int		ft_atoi_ry(t_all_info *all, const char *str)
{
	int		i;
	long	nb;

	nb = 0;
	i = 0;
	if (DISPLAY_Y <= 0)
		return (ft_print_err(all, 25));
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	(nb > DISPLAY_Y) ? (nb = DISPLAY_Y) : nb;
	return (nb);
}

int		ft_enter_color(char *range0, char *range1, char *range2)
{
	if (ft_atoi(range0) > 255)
		return (1);
	else if (ft_atoi(range1) > 255)
		return (1);
	else if (ft_atoi(range2) > 255)
		return (1);
	else if (ft_atoi(range0) < 0)
		return (1);
	else if (ft_atoi(range1) < 0)
		return (1);
	else if (ft_atoi(range2) < 0)
		return (1);
	return (0);
}

int		ft_clr(char **range)
{
	int		clr;
	int		n;

	n = 0;
	clr = 0;
	while (range[n])
	{
		clr = clr * 256;
		clr = clr + ft_atoi(range[n]);
		n++;
	}
	return (clr);
}
