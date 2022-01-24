/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 18:03:58 by mchibane          #+#    #+#             */
/*   Updated: 2020/12/10 17:22:31 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*new_begining;

	if (!lst)
		return (NULL);
	new = NULL;
	new = ft_lstnew(f(lst->content));
	if (!new)
		return (NULL);
	new_begining = new;
	lst = lst->next;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(&new_begining, del);
			return (NULL);
		}
		ft_lstadd_back(&new_begining, new);
		lst = lst->next;
	}
	return (new_begining);
}
