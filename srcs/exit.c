/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:32:13 by mchibane          #+#    #+#             */
/*   Updated: 2022/01/31 19:49:38 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_textures(t_map_config *conf, t_window *win)
{
	if (conf->no.img.img_ptr != NULL)
		mlx_destroy_image(win->mlx_ptr, conf->no.img.img_ptr);
	if (conf->so.img.img_ptr != NULL)
		mlx_destroy_image(win->mlx_ptr, conf->so.img.img_ptr);
	if (conf->we.img.img_ptr != NULL)
		mlx_destroy_image(win->mlx_ptr, conf->we.img.img_ptr);
	if (conf->ea.img.img_ptr != NULL)
		mlx_destroy_image(win->mlx_ptr, conf->ea.img.img_ptr);
}

void	c3d_exit(t_map_config *conf, t_window *win)
{
	free_textures(conf, win);
	if (win->win_ptr != NULL)
	{
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
		win->win_ptr = NULL;
	}
	mlx_destroy_image(win->mlx_ptr, win->img.img_ptr);
	mlx_destroy_display(win->mlx_ptr);
	free(win->mlx_ptr);
}
