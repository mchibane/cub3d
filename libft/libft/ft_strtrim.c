/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:20:21 by mchibane          #+#    #+#             */
/*   Updated: 2020/11/23 21:29:19 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_charset(char const c, char const *set)
{
	size_t	i;

	i = 0;
	if (!set)
		return (0);
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	set_start(char const *str, char const *set, size_t start)
{
	while (is_charset(str[start], set) && start != ft_strlen(str))
		start++;
	return (start);
}

static size_t	set_end(char const *str, char const *set, size_t end)
{
	while (is_charset(str[end], set) && end != 0)
		end--;
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*str;

	if (!s1)
	{
		str = malloc(1);
		if (!str)
			return (NULL);
		str[0] = 0;
		return (str);
	}
	start = 0;
	end = ft_strlen(s1) - 1;
	start = set_start(s1, set, start);
	end = set_end(s1, set, end);
	if (start > end)
		len = 0;
	else
		len = (end - start) + 1;
	str = ft_substr(s1, start, len);
	if (!str)
		return (NULL);
	return (str);
}
