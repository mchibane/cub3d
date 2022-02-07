/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:10:47 by mchibane          #+#    #+#             */
/*   Updated: 2022/02/07 16:58:34 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static t_color	init_color(void)
{
	t_color	ret;

	ret.color = 0;
	ret.exists = 0;
	ret.raw = NULL;
	return (ret);
}

static t_img	init_img(void)
{
	t_img	ret;

	ret.addr = NULL;
	ret.bpp = 0;
	ret.endian = 0;
	ret.height = 0;
	ret.img_ptr = NULL;
	ret.line_len = 0;
	ret.width = 0;
	return (ret);
}

static t_texture	init_texture(void)
{
	t_texture	ret;

	ret.path = NULL;
	ret.exists = 0;
	ret.img = init_img();
	ret.side = 0;
	ret.h = 64;
	ret.w = 64;
	return (ret);
}

t_map_config	init_map_conf(void)
{
	t_map_config	ret;

	ret.no = init_texture();
	ret.no.side = NO;
	ret.so = init_texture();
	ret.so.side = SO;
	ret.we = init_texture();
	ret.we.side = WE;
	ret.ea = init_texture();
	ret.ea.side = EA;
	ret.f = init_color();
	ret.c = init_color();
	ret.map = NULL;
	ret.spawn_dir = 0;
	return (ret);
}

t_window	init_window(void)
{
	t_window	win;

	win.mlx_ptr = mlx_init();
	win.win_ptr = mlx_new_window(win.mlx_ptr, WIN_W, WIN_H, "Cub3D");
	win.img.img_ptr = mlx_new_image(win.mlx_ptr, WIN_W, WIN_H);
	if (win.img.img_ptr != NULL)
		win.img.addr = mlx_get_data_addr(win.img.img_ptr, &win.img.bpp,
				&win.img.line_len, &win.img.endian);
	return (win);
}
