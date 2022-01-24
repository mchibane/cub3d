/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:34:40 by mchibane          #+#    #+#             */
/*   Updated: 2021/11/23 14:48:08 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	size;
	char	*str;

	size = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	str = malloc(sizeof(*str) * (size + 1));
	if (!str)
		return (NULL);
	while (s1 && *s1)
	{
		str[i] = *s1;
		i++;
		s1++;
	}
	while (s2 && *s2)
	{
		str[i] = *s2;
		i++;
		s2++;
	}
	str[i] = 0;
	return (str);
}
