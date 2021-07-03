/*
* Created: 2020/10/27 17:21:07
*/

#include "../header/cub3d.h"

int		ft_exit(int i)
{
	exit(i);
	return (i);
}

void	ft_free(void *str)
{
	free(str);
	str = 0;
}

int		ft_finish(t_all_info *all)
{
	if (all->mlx && all->win)
		mlx_destroy_window(all->mlx, all->win);
	if (all->img.img)
		mlx_destroy_image(all->mlx, all->img.img);
	if (all->buf)
		ft_free2((void *)all->buf);
	if (all->map)
		ft_free2(all->map);
	if (all->sprite)
		ft_free(all->sprite);
	if (all->inf_buf)
		ft_free(all->inf_buf);
	if (all->txtr)
		ft_free(all->txtr);
	ft_exit(0);
	return (0);
}
