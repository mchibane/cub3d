/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:36:56 by mchibane          #+#    #+#             */
/*   Updated: 2022/02/07 16:58:28 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	hooks(t_data *data)
{
	mlx_loop_hook(data->win->mlx_ptr, &raycasting, data);
	mlx_hook(data->win->win_ptr, KeyPress, KeyPressMask, &key_press, data);
	mlx_hook(data->win->win_ptr, KeyRelease, KeyReleaseMask,
		&key_release, data);
	mlx_hook(data->win->win_ptr, DestroyNotify, StructureNotifyMask,
		&mlx_loop_end, data->win->mlx_ptr);
	mlx_loop(data->win->mlx_ptr);
}
