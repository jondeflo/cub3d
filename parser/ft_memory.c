/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jondeflo <jondeflo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 15:58:11 by jondeflo          #+#    #+#             */
/*   Updated: 2020/09/30 16:10:49 by jondeflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void *res;

	if (!(res = malloc(size * nmemb)))
		return (0);
	ft_bzero(res, size * nmemb);
	return (res);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char *ch;

	ch = s;
	while (n > 0)
	{
		*ch = c;
		ch++;
		n--;
	}
	return (s);
}
