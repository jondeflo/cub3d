/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jondeflo <jondeflo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 11:25:25 by jondeflo          #+#    #+#             */
/*   Updated: 2020/09/28 16:36:21 by jondeflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_cub *cub, int x, int y, int color)
{
	char *dst;

	dst = cub->img->addr + (y * cub->img->line + x * (cub->img->bpp / 8));
	*(unsigned int*)dst = color;
}

void	init_player_ns(t_cub *cub, char ch, int x, int y)
{
	cub->pos_y = x + 0.5;
	cub->pos_x = y + 0.5;
	if (ch == 'N')
	{
		cub->dir_x = -1;
		cub->dir_y = 0;
		cub->plane_x = 0;
		cub->plane_y = 0.66;
	}
	if (ch == 'S')
	{
		cub->dir_x = 1;
		cub->dir_y = 0;
		cub->plane_x = 0;
		cub->plane_y = -0.66;
	}
	cub->cfg.map[y][x] = '0';
}

void	init_player_we(t_cub *cub, char ch, int x, int y)
{
	cub->pos_y = x + 0.5;
	cub->pos_x = y + 0.5;
	if (ch == 'W')
	{
		cub->dir_x = 0;
		cub->dir_y = -1;
		cub->plane_x = -0.66;
		cub->plane_y = 0;
	}
	if (ch == 'E')
	{
		cub->dir_x = 0;
		cub->dir_y = 1;
		cub->plane_x = 0.66;
		cub->plane_y = 0;
	}
	cub->cfg.map[y][x] = '0';
}

int		seek_end(char *str, char *tail)
{
	int	len;
	int tail_len;

	len = ft_strlen(str);
	tail_len = ft_strlen(tail);
	if (tail_len > len)
		return (0);
	if (ft_strncmp(str + (len - tail_len),
	tail, tail_len) == 0)
		return (1);
	else
		return (0);
}

int		seekchar(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i++] == c)
			return (1);
	}
	return (0);
}
