/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:42:00 by mchibane          #+#    #+#             */
/*   Updated: 2020/11/18 15:21:50 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	int		i;

	len = ft_strlen(s);
	i = len;
	while (i >= 0)
	{
		if (c == s[i])
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
