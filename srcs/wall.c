/*
* Created: 2020/10/27 17:21:07
*/

#include "../header/cub3d.h"

void	ft_wall_txt(t_plr *plr, t_ray *r)
{
	if (r->side <= 1)
		r->wall_x = plr->y + r->pw_dist * r->dir_y;
	else
		r->wall_x = plr->x + r->pw_dist * r->dir_x;
	r->wall_x = r->wall_x - floor(r->wall_x);
	r->tex_x = (int)(r->wall_x * (double)TEX_WIDTH);
	if (r->side == 1)
		r->tex_x = TEX_WIDTH - r->tex_x - 1;
	else if (r->side == 2)
		r->tex_x = TEX_WIDTH - r->tex_x - 1;
}

void	ft_wall_clr(t_all_info *all, t_ray *r, int x)
{
	int	y;
	int	color;

	r->step = 1.0 * TEX_HEIGHT / r->line_height;
	r->tex_pos = (r->draw_start - all->height / 2 + r->line_height \
													/ 2) * r->step;
	y = r->draw_start;
	while (y < r->draw_end)
	{
		r->tex_y = (int)r->tex_pos & (TEX_HEIGHT - 1);
		r->tex_pos = r->tex_pos + r->step;
		color = all->txtr[r->side][TEX_HEIGHT * r->tex_y + r->tex_x];
		all->buf[y][x] = color;
		y++;
	}
}

void	ft_first_ray(t_all_info *all, t_plr *plr, t_ray *ray, int x)
{
	ray->dir_x = plr->dir_x + plr->follow_x * ray->camera_x;
	ray->dir_y = plr->dir_y + plr->follow_y * ray->camera_x;
	ray->camera_x = 2 * x / (double)all->width - 1;
	ray->delta_dist_x = fabs(1 / ray->dir_x);
	ray->delta_dist_y = fabs(1 / ray->dir_y);
	ray->map_x = (int)plr->x;
	ray->map_y = (int)plr->y;
	ray->hit = 0;
}

void	ft_ray_step_player(t_plr *plr, t_ray *r)
{
	if (r->dir_y < 0)
	{
		r->step_y = -1;
		r->side_dist_y = (plr->y - r->map_y) * r->delta_dist_y;
	}
	else
	{
		r->step_y = 1;
		r->side_dist_y = (r->map_y + 1.0 - plr->y) * r->delta_dist_y;
	}
	if (r->dir_x < 0)
	{
		r->step_x = -1;
		r->side_dist_x = (plr->x - r->map_x) * r->delta_dist_x;
	}
	else
	{
		r->step_x = 1;
		r->side_dist_x = (r->map_x + 1.0 - plr->x) * r->delta_dist_x;
	}
}

void	ft_view_wall(t_all_info *all, t_ray *r)
{
	while (r->hit == 0)
	{
		if (r->side_dist_x < r->side_dist_y)
		{
			r->side = (r->step_x == -1) ? 0 : 1;
			r->side_dist_x += r->delta_dist_x;
			r->map_x += r->step_x;
		}
		else
		{
			r->side = (r->step_y == -1) ? 2 : 3;
			r->side_dist_y += r->delta_dist_y;
			r->map_y += r->step_y;
		}
		if (all->map[r->map_y][r->map_x] == '1')
			r->hit = 1;
	}
}
