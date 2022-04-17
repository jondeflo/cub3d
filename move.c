/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jondeflo <jondeflo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 14:47:51 by jondeflo          #+#    #+#             */
/*   Updated: 2020/09/27 14:48:10 by jondeflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_cub *cub)
{
	if (cub->cfg.map[(int)(cub->pos_x + cub->dir_x * cub->speed)]
	[(int)(cub->pos_y)] == '0')
		cub->pos_x += cub->dir_x * cub->speed;
	if (cub->cfg.map[(int)(cub->pos_x)]
	[(int)(cub->pos_y + cub->dir_y * cub->speed)] == '0')
		cub->pos_y += cub->dir_y * cub->speed;
}

void	move_backward(t_cub *cub)
{
	if (cub->cfg.map[(int)(cub->pos_x - cub->dir_x * cub->speed)]
	[(int)(cub->pos_y)] == '0')
		cub->pos_x -= cub->dir_x * cub->speed;
	if (cub->cfg.map[(int)(cub->pos_x)]
	[(int)(cub->pos_y - cub->dir_y * cub->speed)] == '0')
		cub->pos_y -= cub->dir_y * cub->speed;
}

void	move_left(t_cub *cub)
{
	double new_x;
	double new_y;

	if (cub->cfg.map[(int)(cub->pos_x)]
	[(int)(cub->pos_y - cub->plane_y * cub->speed)] == '0')
	{
		new_x = cub->pos_x - cub->plane_x * cub->speed;
		if (cub->cfg.map[(int)(new_x)][(int)(cub->pos_y)] == '0')
			cub->pos_x = new_x;
	}
	if (cub->cfg.map[(int)(cub->pos_x - cub->plane_x * cub->speed)]
	[(int)cub->pos_y] == '0')
	{
		new_y = cub->pos_y - cub->plane_y * cub->speed;
		if (cub->cfg.map[(int)(cub->pos_x)][(int)(new_y)] == '0')
			cub->pos_y = new_y;
	}
}

void	move_right(t_cub *cub)
{
	double new_x;
	double new_y;

	if (cub->cfg.map[(int)(cub->pos_x)]
	[(int)(cub->pos_y - cub->plane_y * cub->speed)] == '0')
	{
		new_x = cub->pos_x + cub->plane_x * cub->speed;
		if (cub->cfg.map[(int)(new_x)][(int)(cub->pos_y)] == '0')
			cub->pos_x = new_x;
	}
	if (cub->cfg.map[(int)(cub->pos_x - cub->plane_x * cub->speed)]
	[(int)cub->pos_y] == '0')
	{
		new_y = cub->pos_y + cub->plane_y * cub->speed;
		if (cub->cfg.map[(int)(cub->pos_x)][(int)(new_y)] == '0')
			cub->pos_y = new_y;
	}
}
