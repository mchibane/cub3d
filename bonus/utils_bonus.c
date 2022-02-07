/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:15:05 by mchibane          #+#    #+#             */
/*   Updated: 2022/02/07 17:00:09 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	check_textures(t_map_config *conf)
{
	return (conf->ea.exists
		&& conf->we.exists
		&& conf->no.exists
		&& conf->so.exists
		&& conf->f.exists
		&& conf->c.exists);
}

int	tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		i++;
	return (i);
}

int	print_error(char *s)
{
	printf("%s\n", s);
	return (1);
}

int	get_width(char **tab)
{
	size_t	ret;
	int		i;

	i = 0;
	ret = 0;
	while (tab && tab[i])
	{
		if (ft_strlen(tab[i]) > ret)
			ret = ft_strlen(tab[i]);
		i++;
	}
	return (ret);
}
