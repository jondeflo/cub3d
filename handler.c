/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jondeflo <jondeflo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 14:49:20 by jondeflo          #+#    #+#             */
/*   Updated: 2020/09/27 14:50:18 by jondeflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mouse_handler(t_cub *cub)
{
	proc_exit(&(*cub), 1);
	return (0);
}

int	key_handler(int key, t_cub *cub)
{
	if (key == 126 || key == 13)
		move_forward(&(*cub));
	if (key == 125 || key == 1)
		move_backward(&(*cub));
	if (key == 0)
		move_left(&(*cub));
	if (key == 2)
		move_right(&(*cub));
	if (key == 123)
		rotate_ccw(&(*cub));
	if (key == 124)
		rotate_cw(&(*cub));
	if (key == 53)
		proc_exit(&(*cub), 0);
	draw_screen(&(*cub), 0);
	return (0);
}
