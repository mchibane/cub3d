/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:36:56 by mchibane          #+#    #+#             */
/*   Updated: 2022/02/04 14:44:18 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	hooks(t_data *data)
{
	mlx_loop_hook(data->win->mlx_ptr, &raycasting, data);
	mlx_hook(data->win->win_ptr, KeyPress, KeyPressMask, &input, data);
	mlx_hook(data->win->win_ptr, DestroyNotify, StructureNotifyMask,
		&c3d_exit, data);
	mlx_loop(data->win->mlx_ptr);
}
