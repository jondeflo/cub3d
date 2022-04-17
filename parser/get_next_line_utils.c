/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jondeflo <jondeflo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 15:44:31 by jondeflo          #+#    #+#             */
/*   Updated: 2020/09/30 16:15:34 by jondeflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		gnl_len(const char *s)
{
	int res;

	if (!s)
		return (-1);
	res = 0;
	while (s[res])
		res++;
	return (res);
}

char	*gnl_substr(const char *s, int start, int len)
{
	char	*res;
	int		i;

	i = 0;
	if (!s)
		return (0);
	if (start >= gnl_len(s))
		len = 0;
	if (!(res = malloc(sizeof(char) * (len + 1))))
		return (0);
	while (i < len)
	{
		res[i] = s[start];
		i++;
		start++;
	}
	res[i] = '\0';
	return (res);
}

char	*gnl_strjoin(char *tail, char *buf)
{
	char			*res;
	unsigned int	i;
	unsigned int	j;
	size_t			len;

	len = gnl_len(tail) + gnl_len(buf) + 1;
	if (!tail)
		len++;
	if ((!tail && !buf) || !(res = malloc(sizeof(char) * len)))
		return (NULL);
	i = 0;
	j = 0;
	if (tail)
	{
		while (tail[j] != '\0')
			res[i++] = tail[j++];
	}
	i = 0;
	while (buf[i] != '\0')
		res[j++] = buf[i++];
	res[j] = '\0';
	if (tail)
		free(tail);
	return (res);
}

char	*make_line(char *tail)
{
	char	*res;
	int		len;

	if (!tail || tail[0] == '\n' || tail[0] == '\0')
	{
		res = gnl_substr("", 0, 1);
		return (res);
	}
	len = 0;
	while (tail[len] && tail[len] != '\n')
		len++;
	if (len == 0)
		len++;
	res = gnl_substr(tail, 0, len);
	return (res);
}

char	*cut_tail(char *tail)
{
	char	*res;
	int		i;

	i = 0;
	while (tail[i] && tail[i] != '\n')
		i++;
	res = gnl_substr(tail, i + 1, gnl_len(tail) - i);
	free(tail);
	return (res);
}
