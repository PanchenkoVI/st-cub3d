/*
* Created: 2020/10/27 17:21:07
*/

#include "../header/cub3d.h"

void	ft_print_err3(int n)
{
	if (n == 20)
		ft_putstr("Buffer doesn't init\n");
	else if (n == 21)
		ft_putstr("Calloc\n");
	else if (n == 22)
		ft_putstr("Structure\n");
	else if (n == 23)
		ft_putstr("Raycasting\n");
	else if (n == 24)
		ft_putstr("Bmp\n");
	else if (n == 25)
		ft_putstr("Invalid map\n");
}

void	ft_print_err2(int n)
{
	if (n == 8)
		ft_putstr("Тexture\n");
	else if (n == 9)
		ft_putstr("Screen\n");
	else if (n == 10)
		ft_putstr("Invalid map\n");
	else if (n == 11)
		ft_putstr("Invalid map\n");
	else if (n == 12)
		ft_putstr("Invalid map\n");
	else if (n == 13)
		ft_putstr("Invalid map\n");
	else if (n == 14)
		ft_putstr("Map is wrong\n");
	else if (n == 15)
		ft_putstr("Invalid map\n");
	else if (n == 16)
		ft_putstr("Bad parser\n");
	else if (n == 17)
		ft_putstr("Malloc\n");
	else if (n == 18)
		ft_putstr("In the check map\n");
	else if (n == 19)
		ft_putstr("Sprite\n");
}

int		ft_print_err(t_all_info *all, int n)
{
	write(2, "Error\n", 6);
	if (n == 1)
		ft_putstr("Bad argument(s)\n");
	else if (n == 2)
		ft_putstr("Parser\n");
	else if (n == 3)
		ft_putstr("Bad file\n");
	else if (n == 4)
		ft_putstr("In the check map\n");
	else if (n == 5)
		ft_putstr("Lists\n");
	else if (n == 6)
		ft_putstr("Color (C)\n");
	else if (n == 7)
		ft_putstr("Color (F)\n");
	else if (n > 7 && n < 20)
		ft_print_err2(n);
	else if (n > 19 && n < 26)
		ft_print_err3(n);
	if (all->fd)
		close(all->fd);
	ft_exit(0);
	return (-1);
}
