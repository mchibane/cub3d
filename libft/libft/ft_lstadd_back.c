/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 14:07:54 by mchibane          #+#    #+#             */
/*   Updated: 2020/12/10 17:09:37 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (alst && new)
	{
		if (!(*alst))
		{
			*alst = new;
			new->next = NULL;
			return ;
		}
		tmp = *alst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->next = NULL;
	}
}
