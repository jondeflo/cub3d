/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jondeflo <jondeflo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 14:53:48 by jondeflo          #+#    #+#             */
/*   Updated: 2020/09/30 12:29:02 by jondeflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	*init_img(t_cub *cub)
{
	t_img *res;

	if (!(res = (t_img *)malloc(sizeof(t_img))))
		proc_exit(&(*cub), 3);
	res->img = NULL;
	res->addr = NULL;
	res->bpp = 32;
	res->line = cub->cfg.screen_w;
	res->endian = 1;
	return (res);
}

t_tex	*init_tex(t_cub *cub, char *path)
{
	t_tex *res;

	if (!(res = (t_tex *)malloc(sizeof(t_tex))))
		proc_exit(&(*cub), 3);
	res->img = NULL;
	res->addr = NULL;
	res->path = path;
	res->w = 64;
	res->h = 64;
	res->bpp = 32;
	res->line = res->w;
	res->endian = 1;
	res->height = 0;
	res->step = 1.0;
	return (res);
}

void	initlist(t_cub *cub, t_cfg *cfg)
{
	cub->cfg = *cfg;
	if (!(cub->mlx = mlx_init()))
		proc_exit(&(*cub), 3);
	if (cub->cfg.save != 1 && (!(cub->win =
	mlx_new_window(cub->mlx, cub->cfg.screen_w,
	cub->cfg.screen_h, "cub3D"))))
		proc_exit(&(*cub), 3);
	cub->speed = 0.3;
	cub->rotate = 0.1;
	cub->sprite = NULL;
	cub->sprite_cnt = 0;
}

void	spr_add_back(t_cub *cub, t_spr *new)
{
	t_spr *tmp;

	if (!new)
		proc_exit(&(*cub), 3);
	if (cub->sprite)
	{
		tmp = cub->sprite;
		while ((tmp)->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		cub->sprite = new;
	cub->sprite_cnt++;
}

t_spr	*new_spr(t_cub *cub, double coord_x, double coord_y)
{
	t_spr *res;

	if (!(res = (t_spr *)malloc(sizeof(t_spr))))
		proc_exit(&(*cub), 3);
	else
	{
		res->x = coord_x;
		res->y = coord_y;
		res->dist = 0.0;
		res->sprite_x = 0.0;
		res->sprite_y = 0.0;
		res->tr_x = 0.0;
		res->tr_y = 0.0;
		res->scr_x = 0;
		res->width = 0;
		res->height = 0;
		res->start_x = 0;
		res->end_y = 0;
		res->start_y = 0;
		res->end_y = 0;
		res->next = NULL;
	}
	return (res);
}
