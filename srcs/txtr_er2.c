/*
* Created: 2020/10/27 17:21:07
*/

#include "../header/cub3d.h"

int		ft_instal_sprite(t_all_info *all)
{
	int	x;
	int	y;
	int	n;

	if (!(all->sprite = (t_spr *)malloc(sizeof(t_spr) * all->inf_spr)))
		return (ft_print_err(all, 17));
	y = 0;
	n = 0;
	while (y < all->map_h)
	{
		x = 0;
		while (x < all->map_w)
		{
			if (all->map[y][x] == '2')
			{
				all->sprite[n].y = 0.5f + y;
				all->sprite[n].x = 0.5f + x;
				n++;
			}
			x++;
		}
		y++;
	}
	return (1);
}

int		ft_process_fill(t_all_info *all, int n, int *len, char *l)
{
	int m;

	m = -1;
	while (++m < (int)ft_strlen(l))
	{
		if (!(l[m] == 78 || l[m] == 83 || l[m] == 69 || l[m] == 87 || \
			l[m] == 32 || l[m] == '\n' || l[m] == '\0' || l[m] == 48 || \
			l[m] == 49 || l[m] == 50))
			return (ft_print_err(all, 15));
		all->map[n][m] = l[m];
		if (l[m] == 78 || l[m] == 83 || l[m] == 69 || l[m] == 87)
		{
			all->player.y = 0.5f + n;
			all->player.x = 0.5f + m;
			all->dir = l[m];
			(*len)++;
		}
		if (l[m] == 50)
			all->inf_spr++;
	}
	return (1);
}
