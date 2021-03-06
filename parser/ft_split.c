/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jondeflo <jondeflo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 15:48:25 by jondeflo          #+#    #+#             */
/*   Updated: 2020/09/30 16:54:36 by jondeflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		count_elem(char const *s, char c)
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

char	**free_res(char **res)
{
	size_t i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (res);
}

void	plus_args(size_t *i, size_t *len)
{
	(*i)++;
	(*len)++;
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	**res;

	i = 0;
	j = 0;
	len = 0;
	if (!s || !(res = (char **)malloc(sizeof(char*) * (count_elem(s, c) + 1))))
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
			plus_args(&i, &len);
		if (len > 0)
			if (!(res[j++] = ft_substr(s, i - len, len)))
				return (free_res(res));
		len = 0;
	}
	res[j] = NULL;
	return (res);
}

char	**str_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	**res;

	i = 0;
	j = 0;
	len = 0;
	if (!s || !(res = (char **)malloc(sizeof(char*) * count_elem(s, c))))
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
			plus_args(&i, &len);
		if (len > 0)
			if (!(res[j++] = ft_substr(s, i - len, len)))
				return (free_res(res));
		len = 0;
	}
	return (res);
}
