/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jondeflo <jondeflo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 14:51:00 by jondeflo          #+#    #+#             */
/*   Updated: 2020/09/27 14:52:42 by jondeflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_ccw(t_cub *cub)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = cub->dir_x;
	old_plane_x = cub->plane_x;
	cub->dir_x = cub->dir_x * cos(cub->rotate) - cub->dir_y * sin(cub->rotate);
	cub->dir_y = old_dir_x * sin(cub->rotate) + cub->dir_y * cos(cub->rotate);
	cub->plane_x = cub->plane_x *
	cos(cub->rotate) - cub->plane_y * sin(cub->rotate);
	cub->plane_y = old_plane_x *
	sin(cub->rotate) + cub->plane_y * cos(cub->rotate);
}

void	rotate_cw(t_cub *cub)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = cub->dir_x;
	old_plane_x = cub->plane_x;
	cub->dir_x = cub->dir_x *
	cos(-cub->rotate) - cub->dir_y * sin(-cub->rotate);
	cub->dir_y = old_dir_x *
	sin(-cub->rotate) + cub->dir_y * cos(-cub->rotate);
	cub->plane_x = cub->plane_x *
	cos(-cub->rotate) - cub->plane_y * sin(-cub->rotate);
	cub->plane_y = old_plane_x *
	sin(-cub->rotate) + cub->plane_y * cos(-cub->rotate);
}
