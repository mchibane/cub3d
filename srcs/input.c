/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:59:03 by mchibane          #+#    #+#             */
/*   Updated: 2022/02/04 18:08:31 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate(t_data	*data)
{
	float	old_dir_x;
	float	old_plane_x;
	int		dir;

	dir = 1;
	if (data->keys->left)
		dir *= -1;
	old_dir_x = data->player->dir.x;
	old_plane_x = data->player->plane.x;
	data->player->dir.x = old_dir_x
		* cos(dir * R_SP) - data->player->dir.y * sin(dir * R_SP);
	data->player->dir.y = old_dir_x
		* sin(dir * R_SP) + data->player->dir.y * cos(dir * R_SP);
	data->player->plane.x = old_plane_x
		* cos(dir * R_SP) - data->player->plane.y * sin(dir * R_SP);
	data->player->plane.y = old_plane_x
		* sin(dir * R_SP) + data->player->plane.y * cos(dir * R_SP);
}

void	walk(t_data	*data)
{
	int		dir;
	float	dir_x;
	float	dir_y;
	float	x;
	float	y;

	dir = 1;
	dir_x = data->player->dir.x;
	dir_y = data->player->dir.y;
	if (data->keys->s)
		dir = -1;
	x = data->player->pos.x + (dir * dir_x * M_SP);
	y = data->player->pos.y + (dir * dir_y * M_SP);
	if (data->conf->map[(int)(y)][(int)(data->player->pos.x)] == '0')
		data->player->pos.y = y;
	if (data->conf->map[(int)(data->player->pos.y)][(int)(x)] == '0')
		data->player->pos.x = x;
}

void	strafe(t_data *data)
{
	int		dir;
	float	dir_x;
	float	dir_y;
	float	x;
	float	y;

	dir = 1;
	if (data->keys->a)
		dir = -1;
	dir_x = data->player->plane.x;
	dir_y = data->player->plane.y;
	x = data->player->pos.x + (dir * dir_x * S_SP);
	y = data->player->pos.y + (dir * dir_y * S_SP);
	if (data->conf->map[(int)(y)][(int)(data->player->pos.x)] == '0')
		data->player->pos.y = y;
	if (data->conf->map[(int)(data->player->pos.y)][(int)(x)] == '0')
		data->player->pos.x = x;
}

int	input(t_data *data)
{
	if (data->keys->esc)
	{
		mlx_loop_end(data->win->mlx_ptr);
		return (0);
	}
	if (data->keys->left || data->keys->right)
		rotate(data);
	if (data->keys->w || data->keys->s)
		walk(data);
	if (data->keys->a || data->keys->d)
		strafe(data);
	return (0);
}
