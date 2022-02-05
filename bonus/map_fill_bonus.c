/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 22:20:40 by mchibane          #+#    #+#             */
/*   Updated: 2022/01/24 22:55:55 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*fill_line(char *s, size_t width)
{
	size_t		i;
	char		*ret;

	ret = malloc(sizeof(*ret) * (width + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		ret[i] = s[i];
		i++;
	}
	while (i < width)
	{
		ret[i] = ' ';
		i++;
	}
	ret[i] = 0;
	return (ret);
}

char	**add_spaces(char **map)
{
	size_t			height;
	size_t			width;
	char			**ret;
	size_t			i;

	height = tab_len(map);
	width = get_width(map);
	if (height < 3 || width < 3)
		return (NULL);
	ret = malloc(sizeof(*ret) * (height + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < height)
	{
		ret[i] = fill_line(map[i], width);
		if (!ret[i])
		{
			free_tab(ret);
			return (NULL);
		}
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
