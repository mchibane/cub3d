/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:16:59 by mchibane          #+#    #+#             */
/*   Updated: 2022/01/31 19:51:21 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	init_texture(t_texture *tex, t_window *win)
{
	tex->img.img_ptr = mlx_xpm_file_to_image(win->mlx_ptr, tex->path,
			&tex->img.width, &tex->img.height);
	if (tex->img.img_ptr != NULL)
	{
		tex->img.addr = mlx_get_data_addr(tex->img.img_ptr, &tex->img.bpp,
				&tex->img.line_len, &tex->img.endian);
	}
	else
		return (1);
	return (0);
}

int	set_textures(t_map_config *conf, t_window *win)
{
	return (init_texture(&conf->no, win)
		|| init_texture(&conf->so, win)
		|| init_texture(&conf->ea, win)
		|| init_texture(&conf->we, win));
}
