/*
* Created: 2020/10/27 17:21:07
*/

#include "../header/cub3d.h"

void	ft_process_loc(t_all_info *all)
{
	t_spr		tmp;
	int			len;
	int			n;
	int			m;

	n = 0;
	len = 0;
	while (n < all->inf_spr - 1)
	{
		len = n;
		m = n + 1;
		while (m < all->inf_spr)
		{
			if (all->sprite[m].dist > all->sprite[n].dist)
				len = m;
			m = m + 1;
		}
		if (n != len)
		{
			tmp = all->sprite[n];
			all->sprite[n] = all->sprite[len];
			all->sprite[len] = tmp;
		}
		n++;
	}
}

void	ft_location_spr(t_all_info *all, t_plr *plr)
{
	int	n;

	n = 0;
	while (n < all->inf_spr)
	{
		all->sprite[n].dist = ((plr->x - all->sprite[n].x) * (plr->x - \
			all->sprite[n].x) + (plr->y - all->sprite[n].y) * \
			(plr->y - all->sprite[n].y));
		n++;
	}
	ft_process_loc(all);
}

void	ft_srp_change(t_all_info *all, t_plr *plr, t_sprite_ray *s, int i)
{
	double	m;

	m = 0.0;
	s->x = all->sprite[i].x - plr->x;
	s->y = all->sprite[i].y - plr->y;
	s->invers = 1.0 / (plr->follow_x * plr->dir_y - plr->dir_x * plr->follow_y);
	s->trans_x = s->invers * (plr->dir_y * s->x - plr->dir_x * s->y);
	s->trans_y = s->invers * (-plr->follow_y * s->x + plr->follow_x * s->y);
	s->scrn_x = (int)((all->width / 2) * (1 + s->trans_x / s->trans_y));
	s->scrn_mv = (int)(m / s->trans_y);
}

void	ft_color_spr(t_all_info *all, t_sprite_ray *s, int line)
{
	int	c;
	int	y;
	int	dr;

	s->tex_x = (int)((256 * (line - (-s->width / 2 + s->scrn_x)) *\
		TEX_WIDTH / s->width) / 256);
	if (s->trans_y > 0 && line < all->width && s->trans_y <\
		all->inf_buf[line] && line > 0)
	{
		y = s->ray_strt_y;
		while (y < s->ray_end_y)
		{
			dr = (y - s->scrn_mv) * 256 + s->height * 128 - all->height * 128;
			s->tex_y = ((dr * TEX_HEIGHT) / s->height) / 256;
			c = all->txtr[4][s->tex_x + TEX_WIDTH * s->tex_y];
			if ((c & 0x00FFFFFF) != 0)
				all->buf[y][line] = c;
			y++;
		}
	}
}

void	ft_load(t_all_info *all, int *txtr, char *path, t_picture *img)
{
	int		x;
	int		y;
	int		n;

	y = 0;
	img->img = mlx_xpm_file_to_image(all->mlx, path, &img->width, &img->height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, \
		&img->len_pct, &img->end_pct);
	n = img->height;
	while (y < n)
	{
		x = 0;
		while (x < n)
		{
			txtr[n * y + x] = img->data[n * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(all->mlx, img->img);
}
