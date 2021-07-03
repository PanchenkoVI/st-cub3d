/*
* Created: 2020/10/27 17:21:07
*/

#include "../header/cub3d.h"

static int	ft_write_gnl(int fd, char **line, char **str)
{
	size_t	l;
	char	*tp;

	tp = 0;
	l = 0;
	while (str[fd][l] != '\n' && str[fd][l])
		l++;
	if (str[fd][l] == '\n')
		if (!(tp = ft_strdup(str[fd] + l + 1)))
			return (-1);
	if (!(*line = ft_substr(str[fd], 0, l)))
		return (-1);
	free(str[fd]);
	str[fd] = tp;
	if (tp)
		return (1);
	return (0);
}

static int	ft_gnl_continue(int fd, char **line, char *buffer)
{
	static char	*str[13000];
	char		*tm;
	int			i;

	while ((i = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[i] = 0;
		if (str[fd] == NULL)
			str[fd] = ft_strdup("");
		if (!(tm = ft_strjoin(str[fd], buffer)))
			return (-1);
		free(str[fd]);
		str[fd] = tm;
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	free(buffer);
	if (i < 0)
		return (-1);
	if (i == 0 && str[fd] == 0)
	{
		*line = ft_strdup("");
		return (0);
	}
	return (ft_write_gnl(fd, line, str));
}

int			get_next_line(int fd, char **line)
{
	char	buf[1];
	int		spr;
	char	*buffer;

	if (line == NULL)
		return (-1);
	if (fd < 0)
		return (-1);
	spr = 0;
	if ((spr = read(fd, buf, 0)) < 0)
		return (-1);
	if (BUFFER_SIZE < 1)
		return (-1);
	if (fd > 13000)
		return (-1);
	if (!(buffer = (char*)malloc(BUFFER_SIZE + 1)))
		return (-1);
	return (ft_gnl_continue(fd, line, buffer));
}
