/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:32:13 by mchibane          #+#    #+#             */
/*   Updated: 2022/02/07 16:58:16 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

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

int	c3d_exit(t_data *data)
{
	free_textures(data->conf, data->win);
	if (data->win->win_ptr != NULL)
	{
		mlx_destroy_window(data->win->mlx_ptr, data->win->win_ptr);
		data->win->win_ptr = NULL;
	}
	return (0);
}
