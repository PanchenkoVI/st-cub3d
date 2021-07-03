/*
* Created: 2020/10/27 17:21:07
*/

#include "../header/cub3d.h"

void	ft_k_ray(t_plr *plr, double spdr)
{
	double	odx;
	double	opx;

	odx = plr->dir_x;
	plr->dir_x = plr->dir_x * cos(spdr) - plr->dir_y * sin(spdr);
	plr->dir_y = odx * sin(spdr) + plr->dir_y * cos(spdr);
	opx = plr->follow_x;
	plr->follow_x = plr->follow_x * cos(spdr) - plr->follow_y * sin(spdr);
	plr->follow_y = opx * sin(spdr) + plr->follow_y * cos(spdr);
}

void	ft_up_down(t_all_info *all, t_plr *plr, double speed_m)
{
	if (all->map[(int)plr->y][(int)(plr->x + plr->dir_x * speed_m)] != '1')
		plr->x = plr->x + plr->dir_x * speed_m;
	if (all->map[(int)(plr->y + plr->dir_y * speed_m)][(int)plr->x] != '1')
		plr->y = plr->y + plr->dir_y * speed_m;
}

void	ft_left_right(t_all_info *all, t_plr *plr, double speed_m)
{
	if (all->map[(int)plr->y][(int)(plr->x + plr->dir_y * speed_m)] != '1')
		plr->x = plr->x + plr->dir_y * speed_m;
	if (all->map[(int)(plr->y + -plr->dir_x * speed_m)][(int)plr->x] != '1')
		plr->y = plr->y + -plr->dir_x * speed_m;
}

int		ft_keyboard(int key, t_all_info *all)
{
	if (key == KEY_D)
		ft_left_right(all, &all->player, -all->player.speed_m);
	if (key == KEY_A)
		ft_left_right(all, &all->player, all->player.speed_m);
	if (key == KEY_W || key == KEY_ARROW_W)
		ft_up_down(all, &all->player, all->player.speed_m);
	if (key == KEY_S || key == KEY_ARROW_S)
		ft_up_down(all, &all->player, -all->player.speed_m);
	if (key == KEY_ARROW_A)
		ft_k_ray(&all->player, all->player.speed_r);
	if (key == KEY_ARROW_D)
		ft_k_ray(&all->player, -all->player.speed_r);
	if (key == K_ESC)
		ft_exit(0);
	return (0);
}
