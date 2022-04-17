/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jondeflo <jondeflo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 14:54:31 by jondeflo          #+#    #+#             */
/*   Updated: 2020/09/28 17:26:22 by jondeflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean_cfg(t_cfg *cfg)
{
	int i;

	i = 0;
	if (cfg->north)
		free(cfg->north);
	if (cfg->south)
		free(cfg->south);
	if (cfg->west)
		free(cfg->west);
	if (cfg->east)
		free(cfg->east);
	if (cfg->sprite)
		free(cfg->sprite);
	if (cfg->map != NULL)
	{
		while (cfg->map[i] != NULL)
		{
			if (cfg->map[i])
				free(cfg->map[i]);
			i++;
		}
		free(cfg->map);
	}
}

int		cfg_exit(t_cfg *cfg, int code)
{
	clean_cfg(&(*cfg));
	if (code > 1)
	{
		ft_putstr_fd("Error\n", 1);
		get_error_code(code);
	}
	exit(0);
	return (1);
}

int		proc_exit(t_cub *cub, int code)
{
	int i;

	i = 0;
	clean_cfg(&(*cub).cfg);
	while (i < 5)
	{
		if (cub->tex[i]->img)
		{
			free(cub->tex[i]->img);
			free(cub->tex[i]->addr);
		}
		i++;
	}
	if (code > 1)
	{
		ft_putstr_fd("Error\n", 1);
		get_error_code(code);
	}
	exit(0);
	return (1);
}

void	get_error_code(int code)
{
	if (code == 2)
		ft_putstr_fd("Invalid .cub file\n", 1);
	if (code == 3)
		ft_putstr_fd("Memory allocation error\n", 1);
	if (code == 4)
		ft_putstr_fd("File reading error\n", 1);
	if (code == 5)
		ft_putstr_fd("Wrong texture file(s)\n", 1);
	if (code == 6)
		ft_putstr_fd("Invalid program argument(s)\n", 1);
	if (code == 7)
		ft_putstr_fd("Screenshot write error\n", 1);
}
