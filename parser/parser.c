/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jondeflo <jondeflo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 16:12:56 by jondeflo          #+#    #+#             */
/*   Updated: 2020/09/30 12:20:16 by jondeflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parse_cfg(t_cfg *cfg, int ac, char **av)
{
	init_conf(&(*cfg));
	if (ac < 2 || ac > 3)
		cfg_exit(&(*cfg), 6);
	if (av[1] != NULL && seek_end(av[1], ".cub") == 0)
		cfg_exit(&(*cfg), 6);
	if (ac == 3)
	{
		if (ft_strlen(av[2]) == 6 && ft_strncmp(av[2], "--save", 6) == 0)
			cfg->save = 1;
		else
			cfg_exit(&(*cfg), 6);
	}
	if (read_conf(&(*cfg), av[1]) != 1)
		cfg_exit(&(*cfg), 2);
}

int		read_conf(t_cfg *cfg, char *av)
{
	int		fd;
	char	*line;

	line = 0;
	fd = open(av, O_RDONLY);
	if (fd < 0)
		exit(0);
	while (get_next_line(fd, &line))
	{
		if (check_premap(&(*cfg)) == 0)
			add_param(&(*cfg), line);
		else if (check_premap(&(*cfg)) == 1)
			add_map_str(&(*cfg), line);
		free(line);
	}
	if (check_premap(&(*cfg)) == 1)
		add_map_str(&(*cfg), line);
	if (line)
		free(line);
	close(fd);
	if (cfg->map_lst && cfg->err > 0)
		return (copy_map(&(*cfg)));
	return (0);
}

int		copy_map(t_cfg *cfg)
{
	int		res;

	if (check_premap(&(*cfg)) == 0)
		return (0);
	map_to_arr(&(*cfg));
	clear_map_list(&(cfg->map_lst));
	free(cfg->map_lst);
	cfg->map_lst = NULL;
	get_map_size(&(*cfg));
	res = check_map(&(*cfg));
	if (cfg->err > 0 && res == 1)
		return (1);
	return (0);
}

int		fill_spaces(t_cfg *cfg, int i, int j)
{
	char	*dup;
	char	*spaces;

	while (i < cfg->map_height)
	{
		while (cfg->map[i][j] != '\n' && cfg->map[i][j] != '\0')
			j++;
		if (j < cfg->map_width)
		{
			if (!(dup = ft_strdup(cfg->map[i])))
				return (ret_err(&(*cfg)));
			free(cfg->map[i]);
			if (!(spaces = make_spaces(cfg->map_width - j, &(*cfg))) ||
			!(cfg->map[i] = ft_strjoin(dup, spaces)))
				return (ret_err(&(*cfg)));
			free(dup);
			free(spaces);
			dup = NULL;
			spaces = NULL;
		}
		i++;
		j = 0;
	}
	return (1);
}

void	clear_map_list(t_list **begin_list)
{
	if (*begin_list && (*begin_list)->next)
	{
		clear_map_list(&(*begin_list)->next);
	}
	free((*begin_list)->content);
	(*begin_list)->content = NULL;
	free(*begin_list);
	*begin_list = NULL;
}
