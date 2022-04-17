/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jondeflo <jondeflo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 13:58:58 by jondeflo          #+#    #+#             */
/*   Updated: 2020/09/28 17:46:25 by jondeflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_dda_step(t_cub *cub)
{
	if (cub->ray_x < 0)
	{
		cub->step_x = -1;
		cub->side_x = (cub->pos_x - cub->map_x)
		* cub->d_x;
	}
	else
	{
		cub->step_x = 1;
		cub->side_x = (cub->map_x + 1.0 - cub->pos_x)
		* cub->d_x;
	}
	if (cub->ray_y < 0)
	{
		cub->step_y = -1;
		cub->side_y = (cub->pos_y - cub->map_y)
		* cub->d_y;
	}
	else
	{
		cub->step_y = 1;
		cub->side_y = (cub->map_y + 1.0 - cub->pos_y)
		* cub->d_y;
	}
}

void	get_wall_dist(t_cub *cub)
{
	cub->hit = 0;
	while (cub->hit == 0)
	{
		if (cub->side_x < cub->side_y)
		{
			cub->side_x += cub->d_x;
			cub->map_x += cub->step_x;
			cub->side = 0;
		}
		else
		{
			cub->side_y += cub->d_y;
			cub->map_y += cub->step_y;
			cub->side = 1;
		}
		if (cub->cfg.map[cub->map_x][cub->map_y] == '1')
			cub->hit = 1;
	}
	if (cub->side == 0)
		cub->dist = (cub->map_x - cub->pos_x +
		(1 - cub->step_x) / 2) / cub->ray_x;
	else
		cub->dist = (cub->map_y - cub->pos_y +
		(1 - cub->step_y) / 2) / cub->ray_y;
}

void	get_wall_height(t_cub *cub, int x)
{
	int wall_height;
	int wall_start;
	int wall_end;

	wall_height = (int)(cub->cfg.screen_h / cub->dist);
	wall_start = -wall_height / 2 + cub->cfg.screen_h / 2;
	if (wall_start < 0)
		wall_start = 0;
	wall_end = wall_height / 2 + cub->cfg.screen_h / 2;
	if (wall_end >= cub->cfg.screen_h || wall_end < 0)
		wall_end = cub->cfg.screen_h;
	texcast(&(*cub), x, wall_start, wall_end);
}

void	draw_screen(t_cub *cub, int x)
{
	if (!(cub->img->img = mlx_new_image(cub->mlx,
	cub->cfg.screen_w, cub->cfg.screen_h)))
		proc_exit(&(*cub), 3);
	cub->img->addr = mlx_get_data_addr(cub->img->img,
	&cub->img->bpp, &cub->img->line, &cub->img->endian);
	while (x < cub->cfg.screen_w)
	{
		cub->cam_x = 2 * x / (double)cub->cfg.screen_w - 1;
		cub->ray_x = cub->dir_x + cub->plane_x * cub->cam_x;
		cub->ray_y = cub->dir_y + cub->plane_y * cub->cam_x;
		cub->map_x = (int)(cub->pos_x);
		cub->map_y = (int)(cub->pos_y);
		cub->d_x = sqrt(1 + (pow(cub->ray_y, 2) / pow(cub->ray_x, 2)));
		cub->d_y = sqrt(1 + (pow(cub->ray_x, 2) / pow(cub->ray_y, 2)));
		get_dda_step(&(*cub));
		get_wall_dist(&(*cub));
		get_wall_height(&(*cub), x++);
	}
	if (cub->sprite_cnt > 0)
		draw_sprite(&(*cub));
	if (cub->cfg.save != 1)
		mlx_put_image_to_window(cub->mlx, cub->win, cub->img->img, 0, 0);
	mlx_destroy_image(cub->mlx, cub->img->img);
}

int		main(int ac, char **av)
{
	t_cub cub;
	t_cfg cfg;

	parse_cfg(&cfg, ac, av);
	initlist(&cub, &cfg);
	cub.img = init_img(&cub);
	load_texture(&cub, &cfg);
	read_textures(&cub);
	read_map_obj(&cub, 0, 0);
	draw_screen(&cub, 0);
	if (cub.cfg.save == 1)
	{
		write_bmp(&cub);
		cub.cfg.save = 2;
	}
	mlx_hook(cub.win, 2, 1L << 4, key_handler, &cub);
	mlx_hook(cub.win, 17, 0L, mouse_handler, &cub);
	mlx_loop(cub.mlx);
}
