/*
* Created: 2020/10/27 17:21:07
*/

#include "../header/cub3d.h"

void	ft_mlx_texture(t_all_info *all)
{
	t_picture	image;

	ft_load(all, all->txtr[0], all->we_tex_inf, &image);
	ft_load(all, all->txtr[1], all->ea_tex_inf, &image);
	ft_load(all, all->txtr[2], all->so_tex_inf, &image);
	ft_load(all, all->txtr[3], all->no_tex_inf, &image);
	ft_load(all, all->txtr[4], all->spr_tex_inf, &image);
	free(all->no_tex_inf);
	all->no_tex_inf = 0;
	free(all->so_tex_inf);
	all->so_tex_inf = 0;
	free(all->we_tex_inf);
	all->we_tex_inf = 0;
	free(all->ea_tex_inf);
	all->ea_tex_inf = 0;
	free(all->spr_tex_inf);
	all->spr_tex_inf = 0;
}

int		ft_check_map(t_all_info *all)
{
	if (!all->height)
		return (ft_print_err(all, 4));
	else if (!all->width)
		return (ft_print_err(all, 4));
	else if (!all->map_h)
		return (ft_print_err(all, 4));
	else if (!all->map_w)
		return (ft_print_err(all, 4));
	else if (!all->spr_tex_inf)
		return (ft_print_err(all, 4));
	else if (!all->no_tex_inf)
		return (ft_print_err(all, 4));
	else if (!all->we_tex_inf)
		return (ft_print_err(all, 4));
	else if (!all->so_tex_inf)
		return (ft_print_err(all, 4));
	else if (!all->ea_tex_inf)
		return (ft_print_err(all, 4));
	return (1);
}

int		ft_second_part(t_all_info *all, int n)
{
	if (n == 1)
	{
		ft_raycasting(all);
		ft_raycasting_spr(all, &all->player);
		if (ft_bmp(all) != 1)
			return (ft_print_err(all, 24));
		ft_exit(0);
	}
	else
	{
		all->win = mlx_new_window(all->mlx, all->width, all->height, "cub3D");
		mlx_hook(all->win, X_EVENT_KEY_PRESS, 0, ft_keyboard, all);
		mlx_hook(all->win, X_EVENT_KEY_EXIT, 0, ft_exit, 0);
		mlx_loop_hook(all->mlx, ft_all_ray, all);
		mlx_loop(all->mlx);
	}
	ft_finish(all);
	return (1);
}
