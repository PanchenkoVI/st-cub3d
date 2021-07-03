/*
* Created: 2020/10/27 17:21:07
*/

#include "../header/cub3d.h"

int		ft_ln_screen(t_all_info *all, char *str)
{
	char	**len;
	int		n;

	n = 0;
	if (!(len = ft_split(str, ' ')))
		return (ft_print_err(all, 9));
	while (len[n])
		n++;
	if (!len || n != 2)
		return (ft_print_err(all, 9));
	if (!ft_digit(len[0]) || !ft_digit(len[1]))
		return (ft_print_err(all, 9));
	all->width = ft_atoi_rx(all, len[0]);
	all->height = ft_atoi_ry(all, len[1]);
	n = 0;
	ft_free2(len);
	len = NULL;
	if (!all->width || !all->height)
		return (ft_print_err(all, 9));
	return (1);
}

int		ft_new_lists(t_all_info *all, char *str)
{
	t_list	*new_list;

	all->map_w = 0;
	all->map_h = 0;
	new_list = ft_lstnew(ft_strdup(str));
	free(str);
	while (get_next_line(all->fd, &str) > 0)
	{
		ft_lstadd_back(&new_list, ft_lstnew(ft_strdup(str)));
		free(str);
	}
	ft_lstadd_back(&new_list, ft_lstnew(ft_strdup(str)));
	free(str);
	if (ft_parse(all, new_list) != 1)
		return (ft_print_err(all, 16));
	return (1);
}

int		ft_start_buffer(t_all_info *all)
{
	int	i;

	i = 0;
	if (!(all->buf = ft_calloc(all->height, sizeof(int **))))
		return (ft_print_err(all, 21));
	while (i < all->height)
	{
		if (!(all->buf[i] = ft_calloc(all->width, sizeof(int *))))
			return (ft_print_err(all, 21));
		i++;
	}
	if (!(all->inf_buf = ft_calloc(all->width, sizeof(double *))))
		return (ft_print_err(all, 21));
	return (1);
}

void	ft_pl_direction(t_all_info *all)
{
	t_plr		*pl;
	double		pi;
	double		start_x;
	double		next_x;

	pi = 0;
	pl = &all->player;
	if (all->dir == 'N')
		pi = 270 * (M_PI / 180);
	else if (all->dir == 'E')
		pi = 0 * (M_PI / 180);
	else if (all->dir == 'S')
		pi = 90 * (M_PI / 180);
	else if (all->dir == 'W')
		pi = 180 * (M_PI / 180);
	start_x = pl->dir_x;
	pl->dir_x = pl->dir_x * cos(pi) - pl->dir_y * sin(pi);
	pl->dir_y = start_x * sin(pi) + pl->dir_y * cos(pi);
	next_x = pl->follow_x;
	pl->follow_x = pl->follow_x * cos(pi) - pl->follow_y * sin(pi);
	pl->follow_y = next_x * sin(pi) + pl->follow_y * cos(pi);
}

int		ft_start(t_all_info *all, char *path)
{
	t_plr	*plr;

	plr = &all->player;
	plr->x = 2;
	plr->y = 5;
	plr->dir_x = 1.0;
	plr->dir_y = 0.0;
	plr->follow_x = 0.0;
	plr->follow_y = 0.66;
	plr->speed_m = 0.066;
	plr->speed_r = 0.066;
	if (ft_all_parser(all, path) != 1)
		return (ft_print_err(all, 3));
	ft_pl_direction(all);
	all->mlx = mlx_init();
	if (ft_start_buffer(all) != 1)
		return (ft_print_err(all, 20));
	if (ft_texture(all) != 1)
		return (ft_print_err(all, 8));
	ft_mlx_texture(all);
	all->img.img = mlx_new_image(all->mlx, all->width, all->height);
	all->img.data = (int *)mlx_get_data_addr(all->img.img, &all->img.bpp, \
		&all->img.len_pct, &all->img.end_pct);
	return (1);
}
