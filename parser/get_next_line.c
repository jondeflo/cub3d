/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jondeflo <jondeflo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 16:47:54 by jondeflo          #+#    #+#             */
/*   Updated: 2020/09/30 16:15:39 by jondeflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		check_n(char *tail)
{
	int res;
	int i;

	i = 0;
	res = 0;
	if (!tail)
		return (i);
	while (tail[res] != '\0')
	{
		if (tail[res] == '\n')
			i++;
		res++;
	}
	if (i > 0)
		return (i);
	return (-1);
}

int		normal_call(char **line, char **tail)
{
	if ((*line = make_line(*tail)))
		if ((*tail = cut_tail(*tail)))
			return (1);
	return (-1);
}

int		last_call(char **line, char **tail)
{
	*line = make_line(*tail);
	free(*tail);
	*tail = NULL;
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*tail;
	char		*buf;
	int			rs;

	rs = 0;
	if (fd < 0 || !line || BUFFER_SIZE <= 0 ||
	!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (check_n(tail) <= 1 && ((rs = read(fd, buf, BUFFER_SIZE)) > 0))
	{
		buf[rs] = '\0';
		tail = gnl_strjoin(tail, buf);
		if (check_n(tail) > 0)
			break ;
	}
	free(buf);
	if (rs < 0)
		return (-1);
	if (tail && check_n(tail) > 0)
		return (normal_call(line, &tail));
	return (last_call(line, &tail));
}
