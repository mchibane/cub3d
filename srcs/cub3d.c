/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:39:31 by mchibane          #+#    #+#             */
/*   Updated: 2022/02/04 14:49:22 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_data	init_data(t_map_config *conf, t_player *player, t_window *win)
{
	t_data	ret;

	ret.conf = conf;
	ret.player = player;
	ret.win = win;
	ret.ray = NULL;
	return (ret);
}

int	cub3d(t_map_config *conf, t_player *player)
{
	t_window	win;
	t_data		data;

	win = init_window();
	data = init_data(conf, player, &win);
	if (!set_textures(conf, &win))
		hooks(&data);
	else
	{
		printf("Error\nTextures must be .xpm format.\n");
		c3d_exit(&data);
	}
	mlx_destroy_image(data.win->mlx_ptr, data.win->img.img_ptr);
	mlx_destroy_display(data.win->mlx_ptr);
	free(data.win->mlx_ptr);
	return (0);
}
