/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:15:05 by mchibane          #+#    #+#             */
/*   Updated: 2022/01/24 22:29:18 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map_conf(t_map_config	conf)
{
	printf("NO : %25.25s | EXISTS : %d |\n", conf.no.path, conf.no.exists);
	printf("SO : %25.25s | EXISTS : %d |\n", conf.so.path, conf.so.exists);
	printf("WE : %25.25s | EXISTS : %d |\n", conf.we.path, conf.we.exists);
	printf("EA : %25.25s | EXISTS : %d |\n", conf.ea.path, conf.ea.exists);
	printf("F  : %25X | EXISTS : %d | RAW : %8s |\n", conf.f.color, conf.f.exists, conf.f.raw);
	printf("C  : %25X | EXISTS : %d | RAW : %8s |\n", conf.c.color, conf.c.exists, conf.c.raw);
	printf("======================== MAP ========================\n");
	for (int i = 0; conf.map[i]; i++)
	{
		printf("=>");
		for (int j = 0; conf.map[i][j]; j++)
			printf("%c", conf.map[i][j]);
		printf("<=\n");
	}
	printf("=====================================================\n");
}

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
