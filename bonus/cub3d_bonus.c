/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:39:31 by mchibane          #+#    #+#             */
/*   Updated: 2022/02/07 16:57:58 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static t_data	init_data(t_map_config *conf, t_player *player,
	t_window *win, t_keys *keys)
{
	t_data	ret;

	ret.conf = conf;
	ret.player = player;
	ret.win = win;
	ret.ray = NULL;
	ret.keys = keys;
	return (ret);
}

int	cub3d(t_map_config *conf, t_player *player)
{
	t_window	win;
	t_data		data;
	t_keys		keys;

	win = init_window();
	keys = init_keys();
	data = init_data(conf, player, &win, &keys);
	printf("BONUS !\n");
	if (!set_textures(conf, &win))
		hooks(&data);
	else
		printf("Error\nTextures must be .xpm format.\n");
	c3d_exit(&data);
	mlx_destroy_image(data.win->mlx_ptr, data.win->img.img_ptr);
	mlx_destroy_display(data.win->mlx_ptr);
	free(data.win->mlx_ptr);
	return (0);
}
