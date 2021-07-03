/*
* Created: 2020/10/27 17:21:07
*/

#include "../header/cub3d.h"

int		ft_line_map(t_all_info *all, char *s)
{
	if (s[0] == '\0')
		return (1);
	if (s[0] == 'C' && (s[1] == ' ' || s[1] == '\t'))
		return (ft_color_c(all, s + 2));
	else if (s[0] == 'F' && (s[1] == ' ' || s[1] == '\t'))
		return (ft_color_f(all, s + 2));
	else if (s[0] == 'R' && (s[1] == ' ' || s[1] == '\t'))
		return (ft_ln_screen(all, s + 2));
	else if (s[0] == 'S' && (s[1] == ' ' || s[1] == '\t'))
		return (ft_ln_txtr(all, s));
	else if (s[0] == 'N' && s[1] == 'O' && (s[2] == ' ' || s[2] == '\t'))
		return (ft_ln_txtr(all, s));
	else if (s[0] == 'W' && s[1] == 'E' && (s[2] == ' ' || s[2] == '\t'))
		return (ft_ln_txtr(all, s));
	else if (s[0] == 'S' && s[1] == 'O' && (s[2] == ' ' || s[2] == '\t'))
		return (ft_ln_txtr(all, s));
	else if (s[0] == 'E' && s[1] == 'A' && (s[2] == ' ' || s[2] == '\t'))
		return (ft_ln_txtr(all, s));
	return (0);
}

void	ft_zero_inf(t_all_info *all)
{
	all->width = 0;
	all->height = 0;
	all->map_w = 0;
	all->map_h = 0;
	all->inf_spr = 0;
	all->f_clr = 0;
	all->c_clr = 0;
	all->map = NULL;
	all->buf = NULL;
	all->sprite = NULL;
	all->inf_buf = NULL;
	all->we_tex_inf = NULL;
	all->ea_tex_inf = NULL;
	all->no_tex_inf = NULL;
	all->so_tex_inf = NULL;
	all->spr_tex_inf = NULL;
}

int		ft_key_key(char *str)
{
	static int	i = 0;
	char		*s;

	i = 0;
	s = KEY_KEY;
	while (s[i])
	{
		if (str[0] == s[i])
			return (1);
		i++;
	}
	return (0);
}

int		ft_list_chek_map_instal_spr(t_all_info *all, char *line)
{
	if (ft_new_lists(all, line) != 1)
		return (ft_print_err(all, 5));
	if (ft_check_map(all) != 1)
		return (ft_print_err(all, 18));
	if (ft_instal_sprite(all) != 1)
		return (ft_print_err(all, 19));
	return (0);
}

int		ft_all_parser(t_all_info *all, char *path)
{
	char			*line;
	int				r;
	int				i;
	int				j;

	i = 0;
	ft_zero_inf(all);
	all->fd = open(path, O_RDONLY);
	while (get_next_line(all->fd, &line) > 0)
	{
		if ((r = ft_line_map(all, line)) == -1)
			return (ft_print_err(all, 3));
		if (r == 0)
			break ;
		if (ft_key_key(line) == 1)
			i++;
		j = ft_key_key2(line);
		free(line);
	}
	if (i != 8 || j != 0)
		return (ft_print_err(all, 25));
	if (ft_list_chek_map_instal_spr(all, line))
		return (ft_print_err(all, 25));
	return (1);
}
