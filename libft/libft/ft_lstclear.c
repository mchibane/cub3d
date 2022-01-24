/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 14:47:55 by mchibane          #+#    #+#             */
/*   Updated: 2020/12/10 17:13:33 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (lst)
	{
		tmp = *lst;
		while (tmp)
		{
			*lst = tmp;
			del(tmp->content);
			tmp = (*lst)->next;
			free(*lst);
			*lst = NULL;
		}
	}
}
