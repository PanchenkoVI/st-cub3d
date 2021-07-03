/*
* Created: 2020/10/27 17:21:07
*/

#include "../header/cub3d.h"

int		ft_texture(t_all_info *all)
{
	int		i;
	int		j;

	if (!(all->txtr = (int **)malloc(sizeof(int *) * 5)))
		return (ft_print_err(all, 17));
	i = 0;
	while (i < 5)
	{
		if (!(all->txtr[i] = (int *)malloc(sizeof(int) * \
			(TEX_HEIGHT * TEX_WIDTH))))
			return (ft_print_err(all, 17));
		j = 0;
		while (j < TEX_HEIGHT * TEX_WIDTH)
		{
			all->txtr[i][j] = 0;
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_initialization(t_all_info *all, t_list *lst)
{
	int		n;
	int		m;

	n = 0;
	while (lst)
	{
		if (!(all->map[n] = (char *)malloc(sizeof(char) * (all->map_w + 1))))
			return (ft_print_err(all, 17));
		m = 0;
		while (m < (int)ft_strlen(lst->content))
		{
			m++;
			all->map[n][m] = 0;
		}
		while (m < all->map_w)
		{
			m++;
			all->map[n][m] = ' ';
		}
		all->map[n][all->map_w] = '\0';
		n++;
		lst = lst->next;
	}
	return (0);
}

int		ft_init(t_all_info *all, t_list *lst)
{
	t_list	*tmp;
	int		len;
	int		n;

	all->map_h = ft_lstsize(lst);
	if (!(all->map = (char **)malloc(sizeof(char *) * (all->map_h))))
		return (ft_print_err(all, 17));
	tmp = lst;
	len = 0;
	while (tmp)
	{
		n = (int)ft_strlen(tmp->content);
		if (n > len)
			len = n;
		tmp = tmp->next;
	}
	tmp = NULL;
	all->map_w = len;
	ft_initialization(all, lst);
	return (1);
}

void	ft_split_screen(t_all_info *all)
{
	int		y;
	int		x;

	y = 0;
	while (y < all->height)
	{
		x = 0;
		while (x < all->width)
		{
			if (y > all->height / 2)
				all->buf[y][x] = all->f_clr;
			else
				all->buf[y][x] = all->c_clr;
			x++;
		}
		y++;
	}
}

int		ft_parse(t_all_info *all, t_list *lst)
{
	if (ft_init(all, lst) != 1)
		return (ft_print_err(all, 16));
	if (ft_fill(all, lst) != 1)
		return (ft_print_err(all, 16));
	ft_lstclear(&lst, free);
	if (ft_valid(all) != 1)
		return (ft_print_err(all, 16));
	return (1);
}
