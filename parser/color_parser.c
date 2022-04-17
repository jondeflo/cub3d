/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jondeflo <jondeflo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 15:50:04 by jondeflo          #+#    #+#             */
/*   Updated: 2020/09/27 11:14:12 by jondeflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_color_string(char ch)
{
	if (ch != ' ' && ch != ',' && (ch < '0' || ch > '9'))
		return (0);
	return (1);
}

int	cnt_char(char const *s, char c)
{
	unsigned int	elem;
	unsigned int	i;

	elem = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i] != '\0')
			elem++;
		i++;
	}
	return (elem);
}

int	get_color(t_cfg *cfg, char *line, int i)
{
	char	**res;
	char	*tmp;
	int		color;

	if (!(tmp = ft_substr(line, 2, ft_strlen(line) - 1)))
		return (ret_err(&(*cfg)));
	while (tmp[i] != '\0')
		if (check_color_string(tmp[i++]) == 0)
			return (ret_err_free(&(*cfg), &tmp));
	if (cnt_char(tmp, ',') != 2 || cnt_elem(tmp, ',') != 3)
		return (ret_err_free(&(*cfg), &tmp));
	if (!(res = str_split(tmp, ',')))
		return (ret_err_free(&(*cfg), &tmp));
	free(tmp);
	color = 65536 * get_one_color(&(*cfg), res[0]) +
	256 * get_one_color(&(*cfg), res[1]) +
	get_one_color(&(*cfg), res[2]);
	free_params(&(*res));
	if (cfg->err > 0)
		return (color);
	return (-1);
}

int	check_one_color(char *str)
{
	int i;
	int found;

	i = 0;
	found = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
			found = 1;
		if (found == 1 && ft_isspace(str[i]))
			while (str[i] != '\0')
			{
				if (ft_isdigit(str[i]))
					return (0);
				i++;
			}
		if (str[i] != '\0')
			i++;
	}
	return (1);
}

int	get_one_color(t_cfg *cfg, char *str)
{
	int		color;

	if (check_one_color(str) == 0)
		return (ret_err(&(*cfg)));
	color = ft_atoi(str);
	if (color < 0 || color > 255)
		return (ret_err(&(*cfg)));
	return (color);
}
