/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jondeflo <jondeflo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 14:55:05 by jondeflo          #+#    #+#             */
/*   Updated: 2020/09/30 12:27:29 by jondeflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		check_premap(t_cfg *cfg)
{
	if (cfg->screen_w == 0 || cfg->screen_h == 0)
		return (0);
	if (!cfg->north | !cfg->south || !cfg->west || !cfg->east || !cfg->sprite)
		return (0);
	if (cfg->floor < 0 || cfg->sky < 0 || cfg->err < 0)
		return (0);
	if (check_path(&(*cfg)) == 0)
		return (0);
	return (1);
}

int		is_map_string(char *line)
{
	char	ch;
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (line[i] != '\0')
	{
		ch = line[i];
		if (ch == '0' || ch == '1' || ch == '2' || ch == '\n' ||
		ch == 'N' || ch == 'S' || ch == 'W' || ch == 'E')
			res = 1;
		i++;
	}
	return (res);
}

int		check_map_string(char *line)
{
	char	ch;
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		ch = line[i];
		if (ch != ' ' && ch != '0' && ch != '1' && ch != '2' &&
		ch != '\n' && ch != 'N' && ch != 'S' && ch != 'W' && ch != 'E')
			return (0);
		i++;
	}
	return (1);
}

void	add_map_str(t_cfg *cfg, char *line)
{
	t_list *tmp;

	if (cfg->map_lst == NULL && line[0] == '\0')
		return ;
	else if (check_map_string(line) != 0 &&
	is_map_string(line) != 0 && cfg->map_emptystr == 0)
	{
		if (!(tmp = ft_lstnew(ft_strdup(line))))
			cfg->err = -1;
		ft_lstadd_back(&(cfg->map_lst), tmp);
	}
	if (cfg->map_lst != NULL && (line[0] == '\0' || line[0] == '\n'))
		cfg->map_emptystr = 1;
	if ((cfg->map_lst == NULL && line[0] != '\0') ||
	(check_map_string(line) == 0 ||
	(cfg->map_lst != NULL && is_map_string(line) == 0 &&
	cfg->map_emptystr == 1)))
		cfg->err = -1;
	if (cfg->map_lst != NULL && cfg->map_emptystr == 1 &&
	line[0] != '\0')
		cfg->err = -1;
}

void	map_to_arr(t_cfg *cfg)
{
	t_list	*ptr;
	int		i;

	i = 0;
	ptr = (cfg->map_lst);
	if (!(cfg->map = ft_calloc((ft_lstsize(cfg->map_lst) + 1), sizeof(char *))))
		cfg->err = -1;
	while (ptr)
	{
		if (!(cfg->map[i] = ft_strdup(ptr->content)))
			cfg->err = -1;
		i++;
		ptr = ptr->next;
	}
}
