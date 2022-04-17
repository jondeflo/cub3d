/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jondeflo <jondeflo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 14:33:52 by jondeflo          #+#    #+#             */
/*   Updated: 2020/09/28 17:42:35 by jondeflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	write_bmp_image(t_cub *cub, int fd)
{
	int i;
	int row;
	int firstinrow;
	int lastinrow;

	i = cub->cfg.screen_h * cub->cfg.screen_w - 1;
	while (i >= 0)
	{
		row = ((int)(i / cub->cfg.screen_w)) + 1;
		firstinrow = cub->cfg.screen_w *
		row - cub->cfg.screen_w;
		lastinrow = ((row - 1) * cub->cfg.screen_w) +
		cub->cfg.screen_w - 1;
		while (firstinrow <= lastinrow)
		{
			write(fd, &cub->img->addr[firstinrow *
			cub->img->bpp / 8], 4);
			i--;
			firstinrow++;
		}
	}
}

void	write_bmp_info(t_cub *cub, int fd)
{
	int info_header;
	int color_plane;
	int zeroes;
	int res;

	info_header = 40;
	color_plane = 1;
	zeroes = 0;
	res = 2835;
	write(fd, &info_header, 4);
	write(fd, &cub->cfg.screen_w, 4);
	write(fd, &cub->cfg.screen_h, 4);
	write(fd, &color_plane, 2);
	write(fd, &cub->img->bpp, 2);
	while (zeroes++ < 8)
		write(fd, "\0", 1);
	write(fd, &res, 4);
	write(fd, &res, 4);
	zeroes = 0;
	while (zeroes++ < 12)
		write(fd, "\0", 1);
}

void	write_bmp(t_cub *cub)
{
	int fd;
	int img_size;
	int offset;

	if (!(fd = open("screen.bmp", O_CREAT |
	O_WRONLY | O_TRUNC, S_IRWXU)))
		proc_exit(&(*cub), 7);
	offset = 58;
	img_size = offset + (cub->cfg.screen_w *
	cub->cfg.screen_h * 4);
	write(fd, "BM", 2);
	write(fd, &img_size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &offset, 4);
	write_bmp_info(&(*cub), fd);
	write_bmp_image(&(*cub), fd);
	close(fd);
	proc_exit(&(*cub), 0);
}
