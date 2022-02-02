/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:39:31 by mchibane          #+#    #+#             */
/*   Updated: 2022/02/02 16:18:56 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cub3d(t_map_config *conf, t_ray *ray)
{
	t_window	win;
	t_data		data;

	win = init_window();
	data.win = &win;
	data.conf = conf;
	data.ray = ray;
	if (!set_textures(conf, &win))
	{
		mlx_loop_hook(data.win->mlx_ptr, &raycasting, &data);
		mlx_hook(data.win->win_ptr, KeyPress, KeyPressMask, &input, &data);
		mlx_hook(data.win->win_ptr, DestroyNotify, StructureNotifyMask,
			&c3d_exit, &data);
		mlx_loop(data.win->mlx_ptr);
	}
	else
	{
		printf("Error\nInvalid textures.\n");
		c3d_exit(&data);
	}
	mlx_destroy_image(data.win->mlx_ptr, data.win->img.img_ptr);
	mlx_destroy_display(data.win->mlx_ptr);
	free(data.win->mlx_ptr);
	return (0);
}
