/*
* Created: 2020/10/27 17:21:07
*/

#include "../header/cub3d.h"

int		ft_ea_tex(t_all_info *all, char *str)
{
	int		j;
	char	*tmp;
	char	*tmp2;

	tmp2 = NULL;
	if (str[0] == 'E' && str[1] == 'A' && (str[2] == ' ' || str[2] == '\t'))
	{
		j = ft_key_str_txtr(str);
		if (str[j] == '\0' || !ft_duptxtr(str))
			return (ft_print_err(all, 8));
		tmp = ft_strdup(str + j);
		if (!(tmp2 = ft_minus_end(tmp)))
			return (ft_print_err(all, 8));
		if ((j = open(tmp2, O_RDONLY)) == -1)
			return (ft_print_err(all, 8));
		all->ea_tex_inf = tmp2;
		free(tmp);
		return (1);
	}
	return (0);
}

int		ft_no_tex(t_all_info *all, char *str)
{
	int		j;
	char	*tmp;
	char	*tmp2;

	tmp2 = NULL;
	if (str[0] == 'N' && str[1] == 'O' && (str[2] == ' ' || str[2] == '\t'))
	{
		j = ft_key_str_txtr(str);
		if (str[j] == '\0' || !ft_duptxtr(str))
			return (ft_print_err(all, 8));
		tmp = ft_strdup(str + j);
		if (!(tmp2 = ft_minus_end(tmp)))
			return (ft_print_err(all, 8));
		if ((j = open(tmp2, O_RDONLY)) == -1)
			return (ft_print_err(all, 8));
		all->so_tex_inf = tmp2;
		free(tmp);
		return (1);
	}
	return (0);
}

int		ft_we_tex(t_all_info *all, char *str)
{
	int			j;
	char		*tmp;
	char		*tmp2;

	tmp2 = NULL;
	if (str[0] == 'W' && str[1] == 'E' && (str[2] == ' ' || str[2] == '\t'))
	{
		j = ft_key_str_txtr(str);
		if (str[j] == '\0' || !ft_duptxtr(str))
			return (ft_print_err(all, 8));
		tmp = ft_strdup(str + j);
		if (!(tmp2 = ft_minus_end(tmp)))
			return (ft_print_err(all, 8));
		if ((j = open(tmp2, O_RDONLY)) == -1)
			return (ft_print_err(all, 8));
		all->we_tex_inf = tmp2;
		free(tmp);
		return (1);
	}
	return (0);
}

int		ft_so_tex(t_all_info *all, char *str)
{
	int		j;
	char	*tmp;
	char	*tmp2;

	tmp2 = NULL;
	if (str[0] == 'S' && str[1] == 'O' && (str[2] == ' ' || str[2] == '\t'))
	{
		j = ft_key_str_txtr(str);
		if (str[j] == '\0' || !ft_duptxtr(str))
			return (ft_print_err(all, 8));
		tmp = ft_strdup(str + j);
		if (!(tmp2 = ft_minus_end(tmp)))
			return (ft_print_err(all, 8));
		if ((j = open(tmp2, O_RDONLY)) == -1)
			return (ft_print_err(all, 8));
		all->no_tex_inf = tmp2;
		free(tmp);
		return (1);
	}
	return (0);
}

int		ft_ln_txtr(t_all_info *all, char *str)
{
	int		j;
	char	*tmp;
	char	*tmp2;

	j = 0;
	if (str[0] == 'S' && (str[1] == ' ' || str[1] == '\t'))
	{
		j = ft_key_str_txtr(str);
		if (str[j] == '\0' || !ft_duptxtr(str))
			return (ft_print_err(all, 8));
		tmp = ft_strdup(str + j);
		if (!(tmp2 = ft_minus_end(tmp)))
			return (ft_print_err(all, 8));
		if ((j = open(tmp2, O_RDONLY)) == -1)
			return (ft_print_err(all, 8));
		all->spr_tex_inf = tmp2;
		free(tmp);
	}
	else if (!ft_so_tex(all, str) && !ft_we_tex(all, str) &&\
		!ft_ea_tex(all, str) && !ft_no_tex(all, str) && j == 0)
		return (ft_print_err(all, 8));
	return (1);
}
