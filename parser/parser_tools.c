/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jondeflo <jondeflo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 17:45:41 by jondeflo          #+#    #+#             */
/*   Updated: 2020/09/30 14:13:34 by jondeflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		cnt_elem(char const *s, char c)
{
	unsigned int	elem;
	unsigned int	i;

	elem = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i] != '\0')
		{
			elem++;
			i++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (elem);
}

void	free_params(char **tmp)
{
	if (tmp[0])
		free(tmp[0]);
	if (tmp[1])
		free(tmp[1]);
	if (tmp[2])
		free(tmp[2]);
	if (tmp)
		free(tmp);
	tmp = NULL;
}

int		ret_err(t_cfg *cfg)
{
	cfg->err = -1;
	return (-1);
}

int		ret_err_free(t_cfg *cfg, char **tmp)
{
	cfg->err = -1;
	free(*tmp);
	tmp = NULL;
	return (-1);
}
