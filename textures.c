/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jondeflo <jondeflo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 14:56:00 by jondeflo          #+#    #+#             */
/*   Updated: 2020/09/30 12:29:19 by jondeflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	read_textures(t_cub *cub)
{
	cub->tex[0]->img = mlx_xpm_file_to_image(cub->mlx,
	cub->tex[0]->path, &cub->tex[0]->w, &cub->tex[0]->h);
	cub->tex[1]->img = mlx_xpm_file_to_image(cub->mlx,
	cub->tex[1]->path, &cub->tex[1]->w, &cub->tex[1]->h);
	cub->tex[2]->img = mlx_xpm_file_to_image(cub->mlx,
	cub->tex[2]->path, &cub->tex[2]->w, &cub->tex[2]->h);
	cub->tex[3]->img = mlx_xpm_file_to_image(cub->mlx,
	cub->tex[3]->path, &cub->tex[3]->w, &cub->tex[3]->h);
	cub->tex[4]->img = mlx_xpm_file_to_image(cub->mlx,
	cub->tex[4]->path, &cub->tex[4]->w, &cub->tex[4]->h);
	if (!cub->tex[0]->img || !cub->tex[1]->img || !cub->tex[2]->img ||
	!cub->tex[3]->img || !cub->tex[4]->img)
		proc_exit(&(*cub), 5);
	cub->tex[0]->addr = (int *)mlx_get_data_addr(cub->tex[0]->img,
	&cub->tex[0]->bpp, &cub->tex[0]->line, &cub->tex[0]->endian);
	cub->tex[1]->addr = (int *)mlx_get_data_addr(cub->tex[1]->img,
	&cub->tex[1]->bpp, &cub->tex[1]->line, &cub->tex[1]->endian);
	cub->tex[2]->addr = (int *)mlx_get_data_addr(cub->tex[2]->img,
	&cub->tex[2]->bpp, &cub->tex[2]->line, &cub->tex[2]->endian);
	cub->tex[3]->addr = (int *)mlx_get_data_addr(cub->tex[3]->img,
	&cub->tex[3]->bpp, &cub->tex[3]->line, &cub->tex[3]->endian);
	cub->tex[4]->addr = (int *)mlx_get_data_addr(cub->tex[4]->img,
	&cub->tex[4]->bpp, &cub->tex[4]->line, &cub->tex[4]->endian);
}

void	load_texture(t_cub *cub, t_cfg *cfg)
{
	cub->tex[0] = init_tex(&(*cub), cfg->north);
	cub->tex[1] = init_tex(&(*cub), cfg->east);
	cub->tex[2] = init_tex(&(*cub), cfg->south);
	cub->tex[3] = init_tex(&(*cub), cfg->west);
	cub->tex[4] = init_tex(&(*cub), cfg->sprite);
}
