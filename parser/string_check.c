/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jondeflo <jondeflo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 12:19:59 by jondeflo          #+#    #+#             */
/*   Updated: 2020/09/27 11:15:04 by jondeflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		check_string(t_cfg *cfg, int i, int j)
{
	int found;

	found = 0;
	while (i < cfg->map_height)
	{
		while (cfg->map[i][j] != '\0')
		{
			if (found == 0 && (cfg->map[i][j] != '1' && cfg->map[i][j] != ' '))
				return (0);
			if (cfg->map[i][j] == '1')
				found = 1;
			j++;
		}
		i++;
		j = 0;
		found = 0;
	}
	return (check_string_back(&(*cfg)));
}

int		check_string_back(t_cfg *cfg)
{
	int i;
	int j;
	int found;

	i = 0;
	j = 0;
	found = 0;
	while (i < cfg->map_height)
	{
		j = cfg->map_width - 1;
		while (j > 0 && found == 0)
		{
			if (cfg->map[i][j] == '1')
				found = 1;
			if (found == 0 && (cfg->map[i][j] != '1' && cfg->map[i][j] != ' '))
				return (0);
			j--;
		}
		i++;
		found = 0;
	}
	return (1);
}

int		check_column(t_cfg *cfg, int str, int col)
{
	int found;
	int end;

	found = 0;
	while (col < cfg->map_width)
	{
		end = cfg->map_height - 1;
		while (str < end && found == 0)
		{
			if (found == 0 && (cfg->map[str][col] != '1'
			&& cfg->map[str][col] != ' '))
				return (0);
			if (cfg->map[str][col] == '1')
				found = 1;
			str++;
		}
		str = 0;
		col++;
		found = 0;
	}
	return (check_column_back(&(*cfg)));
}

int		check_column_back(t_cfg *cfg)
{
	int found;
	int end;
	int col;

	col = 0;
	found = 0;
	end = 0;
	while (col < cfg->map_width)
	{
		end = cfg->map_height - 1;
		while (end > 0 && found == 0)
		{
			if (found == 0 && (cfg->map[end][col] != '1' &&
			cfg->map[end][col] != ' '))
				return (0);
			if (cfg->map[end][col] == '1')
				found = 1;
			end--;
		}
		col++;
		found = 0;
	}
	return (1);
}
