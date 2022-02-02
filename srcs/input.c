/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:59:03 by mchibane          #+#    #+#             */
/*   Updated: 2022/02/02 16:35:39 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate(t_data	*data, int keysymm)
{
	float	old_dir_x;
	float	old_plane_x;
	int		dir;

	dir = 1;
	if (keysymm == XK_Left)
		dir *= -1;
	old_dir_x = data->ray->player_dir.x;
	old_plane_x = data->ray->plane.x;
	data->ray->player_dir.x = old_dir_x * cos(dir * R_SP) - data->ray->player_dir.y * sin(dir * R_SP);
	data->ray->player_dir.y = old_dir_x * sin(dir * R_SP) + data->ray->player_dir.y * cos(dir * R_SP);
	data->ray->plane.x = old_plane_x * cos(dir * R_SP) - data->ray->plane.y * sin(dir * R_SP);
	data->ray->plane.y = old_plane_x * sin(dir * R_SP) + data->ray->plane.y * cos(dir * R_SP);
	printf("PLANE X : %f PLANE Y : %f\n", data->ray->plane.x, data->ray->plane.y);
	printf("DIR X   : %f DIR Y   : %f\n\n", data->ray->player_dir.x, data->ray->player_dir.y);
}

int	input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		c3d_exit(data);
	else if (keysym == XK_Left || keysym == XK_Right)
		rotate(data, keysym);
	return (0);
}