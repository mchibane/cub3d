/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:02:32 by mchibane          #+#    #+#             */
/*   Updated: 2022/01/24 21:16:06 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
		free(tab);
}

void	free_conf(t_map_config conf)
{
	if (conf.no.path)
		free(conf.no.path);
	if (conf.so.path)
		free(conf.so.path);
	if (conf.ea.path)
		free(conf.ea.path);
	if (conf.we.path)
		free(conf.we.path);
	if (conf.f.raw)
		free(conf.f.raw);
	if (conf.c.raw)
		free(conf.c.raw);
	free_tab(conf.map);
}

void	free_strs(char *s1, char *s2, char *s3, char *s4)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	if (s3)
		free(s3);
	if (s4)
		free(s4);
}
