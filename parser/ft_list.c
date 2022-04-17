/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jondeflo <jondeflo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 16:04:35 by jondeflo          #+#    #+#             */
/*   Updated: 2020/09/30 16:10:27 by jondeflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_list	*ft_lstnew(void *content)
{
	t_list *res;

	if (!(res = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	else
	{
		res->content = content;
		res->next = NULL;
	}
	return (res);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *tmp;

	if (!new)
		return ;
	if (*lst)
	{
		tmp = *lst;
		while ((tmp)->next)
		{
			tmp = tmp->next;
		}
		tmp->next = new;
	}
	else
		*lst = new;
}

int		ft_lstsize(t_list *lst)
{
	int		res;
	t_list	*tmp;

	res = 1;
	tmp = lst;
	if (tmp != 0)
		while (tmp->next != 0)
		{
			tmp = tmp->next;
			res++;
		}
	else
		return (0);
	return (res);
}
