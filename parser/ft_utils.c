/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jondeflo <jondeflo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 14:12:14 by jondeflo          #+#    #+#             */
/*   Updated: 2020/09/30 16:09:35 by jondeflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_atoi(const char *nptr)
{
	int					cnt;
	int					sign;
	unsigned long long	res;

	cnt = 0;
	res = 0;
	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == 45)
		sign = -1;
	if (*nptr == 45 || *nptr == 43)
		nptr++;
	while (*nptr >= 48 && *nptr <= 57)
	{
		res = *nptr - 48 + (res * 10);
		nptr++;
		cnt++;
	}
	if (cnt > 19)
		return (sign == -1 ? 0 : -1);
	return (int)(res * sign);
}

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	i;

	i = 0;
	if (!(res = malloc((sizeof(char) * (ft_strlen(s) + 1)))))
		return (0);
	while (s[i] != '\0')
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*res;
	unsigned int	i;
	unsigned int	j;

	if (!s1 || !s2)
		return (0);
	i = 0;
	j = 0;
	if (!(res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (0);
	while (s1[j] != '\0')
		res[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}

size_t	ft_strlen(const char *s)
{
	size_t res;

	res = 0;
	while (s[res] != '\0')
		res++;
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
		len = 0;
	if (!(res = malloc(sizeof(char) * len + 1)))
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
