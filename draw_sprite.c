/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jondeflo <jondeflo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:06:59 by jondeflo          #+#    #+#             */
/*   Updated: 2020/09/30 12:29:04 by jondeflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_sprite_params(t_cub *cub, t_spr *tmp)
{
	double sprite_x;
	double sprite_y;
	double invert;

	sprite_x = tmp->x - cub->pos_x;
	sprite_y = tmp->y - cub->pos_y;
	invert = 1.0 / (cub->plane_x * cub->dir_y - cub->dir_x * cub->plane_y);
	tmp->tr_x = invert * (cub->dir_y * sprite_x - cub->dir_x * sprite_y);
	tmp->tr_y = invert * (-cub->plane_y * sprite_x + cub->plane_x * sprite_y);
	tmp->scr_x = (int)((cub->cfg.screen_w / 2) * (1 + tmp->tr_x / tmp->tr_y));
	tmp->height = abs((int)(cub->cfg.screen_h / (tmp->tr_y)));
	tmp->width = abs((int)(cub->cfg.screen_h / (tmp->tr_y)));
	tmp->start_y = -tmp->height / 2 + cub->cfg.screen_h / 2;
	if (tmp->start_y < 0)
		tmp->start_y = 0;
	tmp->end_y = tmp->height / 2 + cub->cfg.screen_h / 2;
	if (tmp->end_y >= cub->cfg.screen_h)
		tmp->end_y = cub->cfg.screen_h;
	tmp->start_x = -tmp->width / 2 + tmp->scr_x;
	if (tmp->start_x < 0)
		tmp->start_x = 0;
	tmp->end_x = tmp->width / 2 + tmp->scr_x;
	if (tmp->end_x >= cub->cfg.screen_w)
		tmp->end_x = cub->cfg.screen_w;
}

int		is_column_visible(t_cub *cub, t_spr *tmp, int col)
{
	if (tmp->tr_y > 0 && col >= 0 &&
	col < cub->cfg.screen_w &&
	tmp->tr_y < cub->dist_arr[col])
		return (1);
	return (0);
}

void	draw_sprite_column(t_cub *cub, t_spr *tmp, int col)
{
	int tex_x;
	int tex_y;
	int y;
	int d;
	int color;

	tex_x = (int)(col - (-tmp->width / 2
	+ tmp->scr_x)) * cub->tex[4]->w / tmp->width;
	if (is_column_visible(&(*cub), &(*tmp), col) == 1)
	{
		y = tmp->start_y;
		while (y < tmp->end_y)
		{
			d = (y) * 2 - cub->cfg.screen_h + tmp->height;
			tex_y = ((d * cub->tex[4]->h) / tmp->height) / 2;
			color = cub->tex[4]->addr[cub->tex[4]->w * tex_y + tex_x];
			if (color != 0)
				my_mlx_pixel_put(&(*cub), col, y, color);
			y++;
		}
	}
}

void	draw_sprite(t_cub *cub)
{
	t_spr	*tmp;
	int		col;

	sort_sprites(&(*cub));
	tmp = cub->sprite;
	while (tmp)
	{
		get_sprite_params(&(*cub), &(*tmp));
		col = tmp->start_x;
		while (col < tmp->end_x)
			draw_sprite_column(&(*cub), &(*tmp), col++);
		tmp = tmp->next;
	}
}
