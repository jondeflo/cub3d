/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jondeflo <jondeflo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:06:55 by jondeflo          #+#    #+#             */
/*   Updated: 2020/09/28 16:06:56 by jondeflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_tex_x(t_cub *cub, int side)
{
	int		tex_x;
	double	hit_x;

	if (cub->side == 0)
		hit_x = cub->pos_y + cub->dist * cub->ray_y;
	else
		hit_x = cub->pos_x + cub->dist * cub->ray_x;
	hit_x -= floor((hit_x));
	tex_x = hit_x * (double)(cub->tex[side]->w);
	if (cub->side == 0 && cub->ray_x > 0)
		tex_x = cub->tex[side]->w - tex_x - 1;
	if (cub->side == 1 && cub->ray_y < 0)
		tex_x = cub->tex[side]->w - tex_x - 1;
	return (tex_x);
}

double	get_texture_position(t_cub *cub, int side, int start)
{
	double res;

	cub->tex[side]->height = cub->cfg.screen_h / cub->dist;
	cub->tex[side]->step = 1.0 * cub->tex[side]->h /
	cub->tex[side]->height;
	res = (start - cub->cfg.screen_h /
	2 + cub->tex[side]->height / 2) * cub->tex[side]->step;
	return (res);
}

void	texcast(t_cub *cub, int x, int start, int end)
{
	int		y;
	int		side;
	int		tex_x;
	int		tex_y;
	double	tex_pos;

	y = 0;
	side = get_tex_index(&(*cub));
	while (y < start)
		my_mlx_pixel_put(&(*cub), x, y++, cub->cfg.sky);
	tex_x = get_tex_x(&(*cub), side);
	tex_pos = get_texture_position(&(*cub), side, start);
	while (y < end)
	{
		tex_y = (int)tex_pos & (cub->tex[side]->h - 1);
		tex_pos += cub->tex[side]->step;
		my_mlx_pixel_put(&(*cub), x, y++,
		cub->tex[side]->addr[cub->tex[side]->w * tex_y + tex_x]);
	}
	while (y < cub->cfg.screen_h)
		my_mlx_pixel_put(&(*cub), x, y++, cub->cfg.floor);
	cub->dist_arr[x] = cub->dist;
}

int		get_tex_index(t_cub *cub)
{
	if (cub->side == 0 && cub->ray_x < 0.)
		return (0);
	if (cub->side == 1 && cub->ray_y > 0.)
		return (1);
	if (cub->side == 0 && cub->ray_x > 0.)
		return (2);
	if (cub->side == 1 && cub->ray_y < 0.)
		return (3);
	return (4);
}
