/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jondeflo <jondeflo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 15:47:29 by jondeflo          #+#    #+#             */
/*   Updated: 2020/09/30 11:56:58 by jondeflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_conf(t_cfg *cfg)
{
	cfg->screen_w = 0;
	cfg->screen_h = 0;
	cfg->north = NULL;
	cfg->south = NULL;
	cfg->west = NULL;
	cfg->east = NULL;
	cfg->sprite = NULL;
	cfg->floor = -1;
	cfg->sky = -1;
	cfg->map_lst = NULL;
	cfg->map = NULL;
	cfg->map_emptystr = 0;
	cfg->err = 1;
	cfg->save = 0;
}

void	add_param(t_cfg *cfg, char *line)
{
	if (line[0] == 82 && line[1] == 32 &&
	cfg->screen_h == 0 && cfg->screen_w == 0)
		get_screen_size(&(*cfg), line);
	else if (line[0] == 78 && line[1] == 79 && cfg->north == 0)
		get_tex_path(&(*cfg), line, 2);
	else if (line[0] == 83 && line[1] == 79 && cfg->south == 0)
		get_tex_path(&(*cfg), line, 2);
	else if (line[0] == 87 && line[1] == 69 && cfg->west == 0)
		get_tex_path(&(*cfg), line, 2);
	else if (line[0] == 69 && line[1] == 65 && cfg->east == 0)
		get_tex_path(&(*cfg), line, 2);
	else if (line[0] == 83 && line[1] == 32 && cfg->sprite == 0)
		get_sprite_path(&(*cfg), line);
	else if (line[0] == 70 && line[1] == 32 && cfg->floor == -1)
		cfg->floor = get_color(&(*cfg), line, 0);
	else if (line[0] == 67 && line[1] == 32 && cfg->sky == -1)
		cfg->sky = get_color(&(*cfg), line, 0);
	else if (line[0] != 0)
		cfg->err = -1;
}

int		get_sprite_path(t_cfg *cfg, char *line)
{
	int		start;
	int		end;
	char	*res;

	start = 1;
	end = ft_strlen(line) - 1;
	while (line[start] == ' ')
		start++;
	while (line[end] == ' ')
		end--;
	if (start <= 1 || end - start <= 0 ||
	!(res = ft_substr(line, start, end - start + 1)))
		return (ret_err(&(*cfg)));
	else
	{
		cfg->sprite = ft_strdup(res);
		free(res);
		return (1);
	}
}

int		get_tex_path(t_cfg *cfg, char *line, int start)
{
	int		end;
	char	*res;

	while (line[start] == ' ')
		start++;
	end = ft_strlen(line) - 1;
	while (line[end] == ' ')
		end--;
	if (start <= 2 || end - start <= 0 ||
	!(res = ft_substr(line, start, end - start + 1)))
		return (ret_err(&(*cfg)));
	else
	{
		if (line[0] == 78 && line[1] == 79)
			cfg->north = ft_strdup(res);
		if (line[0] == 83 && line[1] == 79)
			cfg->south = ft_strdup(res);
		if (line[0] == 87 && line[1] == 69)
			cfg->west = ft_strdup(res);
		if (line[0] == 69 && line[1] == 65)
			cfg->east = ft_strdup(res);
		free(res);
		return (1);
	}
}
