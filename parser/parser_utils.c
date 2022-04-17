/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jondeflo <jondeflo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 15:48:09 by jondeflo          #+#    #+#             */
/*   Updated: 2020/09/30 12:07:02 by jondeflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		check_path(t_cfg *cfg)
{
	int fd;

	if ((fd = open(cfg->north, O_RDONLY)) < 0)
		return (0);
	if ((fd = open(cfg->south, O_RDONLY)) < 0)
		return (0);
	if ((fd = open(cfg->east, O_RDONLY)) < 0)
		return (0);
	if ((fd = open(cfg->west, O_RDONLY)) < 0)
		return (0);
	if ((fd = open(cfg->sprite, O_RDONLY)) < 0)
		return (0);
	close(fd);
	return (1);
}

void	check_screen(t_cfg *cfg)
{
	if (cfg->screen_w > MAX_WIDTH)
		cfg->screen_w = MAX_WIDTH;
	if (cfg->screen_h > MAX_HEIGHT)
		cfg->screen_h = MAX_HEIGHT;
	if (cfg->screen_w < 1)
		cfg->screen_w = MAX_WIDTH;
	if (cfg->screen_h < 1)
		cfg->screen_h = MAX_HEIGHT;
}

int		get_screen_size(t_cfg *cfg, char *line)
{
	int		i;
	char	**tmp;

	i = 1;
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && (line[i] < '0' || line[i] > '9'))
			return (ret_err(&(*cfg)));
		i++;
	}
	if (cnt_elem(line, ' ') != 3)
		return (ret_err(&(*cfg)));
	tmp = ft_split(line, ' ');
	if (!(tmp))
		return (ret_err(&(*cfg)));
	if (!(ft_atoi(tmp[1])) || !(ft_atoi(tmp[2])))
	{
		free_params(&(*tmp));
		return (ret_err(&(*cfg)));
	}
	cfg->screen_w = ft_atoi(tmp[1]);
	cfg->screen_h = ft_atoi(tmp[2]);
	check_screen(&(*cfg));
	free_params(&(*tmp));
	return (1);
}
