/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:39:31 by mchibane          #+#    #+#             */
/*   Updated: 2022/01/31 19:43:53 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cub3d(t_map_config *conf)
{
	t_window	win;

	win = init_window();
	if (set_textures(conf, &win))
	{
		printf("Error\nInvalid textures.\n");
		c3d_exit(conf, &win);
		return (1);
	}
	c3d_exit(conf, &win);
	return (0);
}
