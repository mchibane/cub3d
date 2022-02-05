/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:06:13 by mchibane          #+#    #+#             */
/*   Updated: 2022/01/24 18:46:57 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	str_isdigit(char *s)
{
	while (s && *s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

static int	get_color(t_color *color)
{
	char	**tab;
	int		i;

	tab = ft_split(color->raw, ',');
	if (tab_len(tab) != 3 || !tab)
	{
		free_tab(tab);
		return (1);
	}
	i = 0;
	while (tab[i])
	{
		if ((ft_strlen(tab[i]) == 3 && ft_strncmp(tab[i], "255", 3) > 0)
			|| ft_strlen(tab[i]) > 3
			|| !str_isdigit(tab[i]))
		{
			free_tab(tab);
			return (1);
		}
		color->color |= ft_atoi(tab[i]) << (8 * (2 - i));
		i++;
	}
	free_tab(tab);
	return (0);
}

int	set_colors(t_map_config *conf)
{
	if (get_color(&conf->f) || get_color(&conf->c))
	{
		printf("Error\nInavlid Floor or Ceiling color formating.\n");
		return (1);
	}
	return (0);
}
