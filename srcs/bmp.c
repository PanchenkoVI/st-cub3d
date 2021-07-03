/*
* Created: 2020/10/27 17:21:07
*/

#include "../header/cub3d.h"

int		ft_tst(int k)
{
	if (k == 0)
		return (0);
	k = k / 4;
	if (k == 0)
		k = 1;
	k = k * 4;
	return (k);
}

void	ft_char(unsigned char *buf, int ch)
{
	buf[0] = (unsigned char)(ch);
	buf[1] = (unsigned char)(ch >> 8);
	buf[2] = (unsigned char)(ch >> 16);
	buf[3] = (unsigned char)(ch >> 24);
}

void	ft_data(t_all_info *all, int fd)
{
	const unsigned char	z[3] = {0, 0, 0};
	int					len;
	int					n;
	int					m;

	len = ((4 - (all->width) * 3) % 4) % 4;
	n = (all->height);
	while (n >= 0)
	{
		m = 0;
		while (m < all->width)
		{
			write(fd, &(all->buf[n][m]), 3);
			if (len > 0)
				write(fd, &z, len);
			m++;
		}
		n--;
	}
}

int		ft_bmp(t_all_info *all)
{
	unsigned char		word[54];
	int					len;
	int					fd;

	if (all->width % 4)
		all->width = all->width - (all->width % 4);
	len = all->width * all->height + 54;
	if ((fd = open("screen.bmp", O_WRONLY | O_CREAT | O_TRUNC | \
										O_APPEND, (int)493)) < 0)
		return (0);
	ft_memset(word, 0, 54);
	word[0] = (unsigned char)'B';
	word[1] = (unsigned char)'M';
	ft_char(word + 2, len);
	word[10] = (unsigned char)54;
	word[14] = (unsigned char)40;
	ft_char(word + 18, all->width);
	ft_char(word + 22, all->height);
	word[26] = (unsigned char)1;
	word[28] = (unsigned char)24;
	write(fd, word, 54);
	ft_data(all, fd);
	return (1);
}
