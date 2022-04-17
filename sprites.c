/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jondeflo <jondeflo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:07:12 by jondeflo          #+#    #+#             */
/*   Updated: 2020/09/30 12:27:53 by jondeflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	read_map_obj(t_cub *cub, int i, int j)
{
	char ch;

	while (cub->cfg.map[i])
	{
		while (cub->cfg.map[i][j] != '\0')
		{
			ch = cub->cfg.map[i][j];
			if (seekchar(MAPVAL, ch))
			{
				if (ch == '2')
					spr_add_back(&(*cub), new_spr(&(*cub), i + 0.5, j + 0.5));
				if (ch == 'N' || ch == 'S')
					init_player_ns(&(*cub), ch, j, i);
				if (ch == 'W' || ch == 'E')
					init_player_we(&(*cub), ch, j, i);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	get_sprite_distance(t_cub *cub)
{
	t_spr	*tmp;

	tmp = cub->sprite;
	while (tmp->next != 0)
	{
		tmp->dist = ((cub->pos_x - tmp->x) * (cub->pos_x - tmp->x)
		+ (cub->pos_y - tmp->y) * (cub->pos_y - tmp->y));
		tmp = tmp->next;
	}
	tmp->dist = ((cub->pos_x - tmp->x) * (cub->pos_x - tmp->x)
	+ (cub->pos_y - tmp->y) * (cub->pos_y - tmp->y));
}

void	swap_sprites(t_spr *a, t_spr *b)
{
	double	temp_dist;
	double	temp_x;
	double	temp_y;

	temp_dist = a->dist;
	a->dist = b->dist;
	b->dist = temp_dist;
	temp_x = a->x;
	a->x = b->x;
	b->x = temp_x;
	temp_y = a->y;
	a->y = b->y;
	b->y = temp_y;
}

void	sort_sprites(t_cub *cub)
{
	t_spr	*a;
	t_spr	*b;

	get_sprite_distance(&(*cub));
	a = cub->sprite;
	while (a)
	{
		b = a->next;
		while (b)
		{
			if (a->dist < b->dist)
				swap_sprites(&(*a), &(*b));
			b = b->next;
		}
		a = a->next;
	}
}
