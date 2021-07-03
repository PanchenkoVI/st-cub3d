/*
* Created: 2020/10/27 17:21:07
*/

#include "../header/cub3d.h"

int		ft_top(t_all_info *all)
{
	int		i;
	int		len;
	int		len1;

	i = 0;
	len = (int)ft_strlen(all->map[0]);
	len1 = (int)ft_strlen(all->map[1]);
	if (len1 > len)
		len = len1;
	while (i < len)
	{
		if (all->map[0][i] != '\0')
			if (!(all->map[0][i] == ' ' || all->map[0][i] == '1'))
				return (ft_print_err(all, 10));
		i++;
	}
	return (1);
}

int		ft_bottom(t_all_info *all, int n)
{
	int		m;
	int		len;

	m = 0;
	len = (int)ft_strlen(all->map[n]);
	while (m < len)
	{
		if (!(all->map[n][m] == ' ' || all->map[n][m] == '1'))
			return (ft_print_err(all, 13));
		if (m == len - 1)
		{
			if (all->map[n - 1][m] == '0' && (all->map[n][m + 1] != '1' || \
				all->map[n][m + 1] != ' '))
				return (ft_print_err(all, 13));
		}
		m++;
	}
	return (1);
}

int		ft_middle(t_all_info *all, int n, int m, int len)
{
	while (m < len)
	{
		if (n > 0 && n < all->map_h - 1)
		{
			if (all->map[n - 1][m] == ' ' || all->map[n + 1][m] == ' ')
				if (all->map[n][m] != ' ' && all->map[n][m] != '1')
					return (ft_print_err(all, 12));
		}
		if (m > 0 && m < all->map_w)
		{
			if (all->map[n][m - 1] == ' ' || all->map[n][m + 1] == ' ')
				if (all->map[n][m] != ' ' && all->map[n][m] != '1')
					return (ft_print_err(all, 12));
		}
		if (ft_in_map(all->map[n][m]) == 1)
			if (ft(all->map[n][m - 1]) || ft(all->map[n - 1][m - 1]) ||\
			ft(all->map[n - 1][m]) || ft(all->map[n + 1][m + 1]) ||\
			ft(all->map[n][m + 1]) || ft(all->map[n + 1][m + 1]) ||\
			ft(all->map[n + 1][m]) || ft(all->map[n + 1][m - 1]))
				return (ft_print_err(all, 12));
		m++;
	}
	return (m);
}

int		ft_valid(t_all_info *all)
{
	int		n;
	int		m;
	int		len;

	n = 0;
	if (ft_top(all) != 1)
		return (ft_print_err(all, 10));
	while (n < all->map_h - 1)
	{
		m = 0;
		while (all->map[n][m] == ' ')
			m++;
		if (all->map[n][m] != '1')
			return (ft_print_err(all, 11));
		len = (int)ft_strlen(all->map[n]);
		m = ft_middle(all, n, m, len);
		if (all->map[n][m - 1] != '1')
			return (ft_print_err(all, 12));
		n++;
	}
	if (ft_bottom(all, n) != 1)
		return (ft_print_err(all, 13));
	return (1);
}

int		ft_fill(t_all_info *all, t_list *lst)
{
	int		m;
	char	*str;
	int		len;

	m = -1;
	len = 0;
	while (++m < all->map_h)
	{
		str = (char *)lst->content;
		ft_process_fill(all, m, &len, str);
		lst = lst->next;
	}
	if (len == 0)
		return (ft_print_err(all, 14));
	else if (len > 1)
		return (ft_print_err(all, 14));
	return (1);
}
