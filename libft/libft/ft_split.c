/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 13:24:46 by mchibane          #+#    #+#             */
/*   Updated: 2020/11/23 17:19:04 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_size(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			count++;
		i++;
	}
	return (count);
}

static char	*ft_new_str(char const *s, char c)
{
	size_t	i;
	char	*str;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	str = malloc(sizeof(*str) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

static char	**ft_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	size;
	size_t	i;
	size_t	j;

	size = ft_get_size(s, c);
	tab = malloc(sizeof(*tab) * (size + 1));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (j < size)
	{
		while (s[i] == c && s[i])
			i++;
		tab[j] = ft_new_str(&s[i], c);
		if (!(tab[j]))
			return (ft_free_tab(tab));
		j++;
		while (s[i] != c && s[i])
			i++;
	}
	tab[j] = 0;
	return (tab);
}
