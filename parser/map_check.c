/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jondeflo <jondeflo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 16:33:37 by jondeflo          #+#    #+#             */
/*   Updated: 2020/09/30 12:19:47 by jondeflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		check_map(t_cfg *cfg)
{
	if (fill_spaces(&(*cfg), 0, 0) != 1 || check_string(&(*cfg), 0, 0) != 1 ||
	check_column(&(*cfg), 0, 0) != 1 ||
	check_space_around(&(*cfg), 1, 1) != 1 ||
	check_double_player(&(*cfg), 1, 1) != 1)
		return (0);
	return (1);
}

int		check_double_player(t_cfg *cfg, int i, int j)
{
	int found;

	found = 0;
	while (i < cfg->map_height - 1)
	{
		while (cfg->map[i][j + 1] != '\0')
		{
			if (cfg->map[i][j] == 'N' ||
			cfg->map[i][j] == 'S' ||
			cfg->map[i][j] == 'W' ||
			cfg->map[i][j] == 'E')
				found++;
			j++;
		}
		i++;
		j = 1;
	}
	return (found);
}

int		check_space_around(t_cfg *cfg, int i, int j)
{
	while (i < cfg->map_height - 1)
	{
		while (cfg->map[i][j + 1] != '\0')
		{
			if (cfg->map[i][j] == '0' || cfg->map[i][j] == '2' ||
			cfg->map[i][j] == 'N' || cfg->map[i][j] == 'S' ||
			cfg->map[i][j] == 'W' || cfg->map[i][j] == 'E')
				if (cfg->map[i - 1][j] == ' ' || cfg->map[i + 1][j] == ' ' ||
				cfg->map[i][j - 1] == ' ' || cfg->map[i][j + 1] == ' ')
					return (0);
			j++;
		}
		i++;
		j = 1;
	}
	return (1);
}

char	*make_spaces(int amount, t_cfg *cfg)
{
	char	*res;
	int		i;

	i = 0;
	if (!(res = malloc((sizeof(char) * (amount + 1)))))
	{
		cfg->err = -1;
		return (0);
	}
	while (i < amount)
	{
		res[i] = ' ';
		i++;
	}
	res[i] = '\0';
	return (res);
}

void	get_map_size(t_cfg *cfg)
{
	int i;
	int j;
	int max;

	i = 0;
	j = 0;
	max = 0;
	while (cfg->map[i])
	{
		while (cfg->map[i][j] != '\0')
			j++;
		if (max < j)
			max = j;
		i++;
		j = 0;
	}
	cfg->map_width = max;
	cfg->map_height = i;
}
