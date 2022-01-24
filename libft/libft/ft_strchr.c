/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:16:22 by mchibane          #+#    #+#             */
/*   Updated: 2020/11/16 18:39:38 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s) + 1;
	i = 0;
	while (i < len)
	{
		if (c == s[i])
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
