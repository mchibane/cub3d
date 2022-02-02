/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:59:03 by mchibane          #+#    #+#             */
/*   Updated: 2022/02/02 19:17:13 by mchibane         ###   ########.fr       */
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
	data->ray->player_dir.x = old_dir_x
		* cos(dir * R_SP) - data->ray->player_dir.y * sin(dir * R_SP);
	data->ray->player_dir.y = old_dir_x
		* sin(dir * R_SP) + data->ray->player_dir.y * cos(dir * R_SP);
	data->ray->plane.x = old_plane_x
		* cos(dir * R_SP) - data->ray->plane.y * sin(dir * R_SP);
	data->ray->plane.y = old_plane_x
		* sin(dir * R_SP) + data->ray->plane.y * cos(dir * R_SP);
	printf("DIR X : %f DIR Y : %f\n\n", data->ray->player_dir.x, data->ray->player_dir.y);
}

void	walk(t_data	*data, int keysym)
{
	int		dir;
	float	dir_x;
	float	dir_y;
	float	x;
	float	y;

	dir = 1;
	dir_x = data->ray->player_dir.x;
	dir_y = data->ray->player_dir.y;
	if (keysym == XK_s)
		dir = -1;
	x = data->ray->player_pos.x + (dir * dir_x * M_SP);
	y = data->ray->player_pos.y + (dir * dir_y * M_SP);
	if (data->conf->map[(int)(y)][(int)(x)] != '1')
	{
		data->ray->player_pos.x = x;
		data->ray->player_pos.y = y;
	}
}

void	strafe(t_data *data, int keysym)
{
	int		dir;
	float	dir_x;
	float	dir_y;
	float	x;
	float	y;

	dir = 1;
	if (keysym == XK_a)
		dir = -1;
	dir_x = data->ray->plane.x;
	dir_y = data->ray->plane.y;
	x = data->ray->player_pos.x + (dir * dir_x * S_SP);
	y = data->ray->player_pos.y + (dir * dir_y * S_SP);
	if (data->conf->map[(int)(y)][(int)(x)] != '1')
	{
		data->ray->player_pos.x = x;
		data->ray->player_pos.y = y;
	}
}

int	input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		c3d_exit(data);
	else if (keysym == XK_Left || keysym == XK_Right)
		rotate(data, keysym);
	else if (keysym == XK_w || keysym == XK_s)
		walk(data, keysym);
	else if (keysym == XK_a || keysym == XK_d)
		strafe(data, keysym);
	return (0);
}
