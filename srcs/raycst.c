/*
* Created: 2020/10/27 17:21:07
*/

#include "../header/cub3d.h"

void	ft_raycasting(t_all_info *all)
{
	int		x;

	x = 0;
	ft_split_screen(all);
	while (x < all->width)
	{
		ft_first_ray(all, &all->player, &all->ray, x);
		ft_ray_step_player(&all->player, &all->ray);
		ft_view_wall(all, &all->ray);
		ft_w_and_h(all, &all->player, &all->ray);
		ft_wall_txt(&all->player, &all->ray);
		ft_wall_clr(all, &all->ray, x);
		all->inf_buf[x] = all->ray.pw_dist;
		x++;
	}
}

void	ft_spr_hw(t_all_info *all, t_sprite_ray *s)
{
	int		h;
	int		w;

	w = 1;
	h = 1;
	s->height = (int)fabs((all->height / s->trans_y) / h);
	s->ray_strt_y = -s->height / 2 + all->height / 2 + s->scrn_mv;
	if (s->ray_strt_y < 0)
		s->ray_strt_y = 0;
	s->ray_end_y = s->height / 2 + all->height / 2 + s->scrn_mv;
	if (s->ray_end_y >= all->height)
		s->ray_end_y = all->height - 1;
	s->width = (int)fabs((all->height / s->trans_y) / w);
	s->ray_strt_x = -s->width / 2 + s->scrn_x;
	if (s->ray_strt_x < 0)
		s->ray_strt_x = 0;
	s->ray_end_x = s->width / 2 + s->scrn_x;
	if (s->ray_end_x >= all->width)
		s->ray_end_x = all->width - 1;
}

void	ft_raycasting_spr(t_all_info *all, t_plr *plr)
{
	int	i;
	int	line;

	ft_location_spr(all, plr);
	i = 0;
	while (i < all->inf_spr)
	{
		ft_srp_change(all, plr, &all->s_ray, i);
		ft_spr_hw(all, &all->s_ray);
		line = all->s_ray.ray_strt_x;
		while (line < all->s_ray.ray_end_x)
		{
			ft_color_spr(all, &all->s_ray, line);
			line++;
		}
		i++;
	}
}

int		ft_all_ray(t_all_info *all)
{
	int		x;
	int		y;

	y = 0;
	ft_raycasting(all);
	ft_raycasting_spr(all, &all->player);
	while (y < all->height)
	{
		x = 0;
		while (x < all->width)
		{
			all->img.data[all->width * y + x] = all->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(all->mlx, all->win, all->img.img, 0, 0);
	return (0);
}

void	ft_w_and_h(t_all_info *all, t_plr *plr, t_ray *r)
{
	if (r->side <= 1)
		r->pw_dist = (r->map_x - plr->x + (1 - r->step_x) / 2) / r->dir_x;
	else
		r->pw_dist = (r->map_y - plr->y + (1 - r->step_y) / 2) / r->dir_y;
	r->line_height = (int)(all->height / r->pw_dist);
	r->draw_start = -r->line_height / 2 + all->height / 2;
	if (r->draw_start < 0)
		r->draw_start = 0;
	r->draw_end = r->line_height / 2 + all->height / 2;
	if (r->draw_end >= all->height)
		r->draw_end = all->height - 1;
}
