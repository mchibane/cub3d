/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:59:03 by mchibane          #+#    #+#             */
/*   Updated: 2022/02/08 14:23:21 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	rotate(t_data	*data, int x)
{
	float	old_dir_x;
	float	old_plane_x;
	int		dir;

	dir = 0;
	if (x > WIN_W >> 1 || data->keys->right)
		dir++;
	if (x < WIN_W >> 1 || data->keys->left)
		dir--;
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

static void	walk(t_data	*data)
{
	int		dir;
	float	dir_x;
	float	dir_y;
	float	x;
	float	y;

	dir = 0;
	dir_x = data->player->dir.x;
	dir_y = data->player->dir.y;
	if (data->keys->s)
		dir--;
	if (data->keys->w)
		dir++;
	x = data->player->pos.x + (dir * dir_x * M_SP);
	y = data->player->pos.y + (dir * dir_y * M_SP);
	if (ft_ischarset(data->conf->map[(int)(y)][(int)(data->player->pos.x)],
		WALK))
		data->player->pos.y = y;
	if (ft_ischarset(data->conf->map[(int)(data->player->pos.y)][(int)(x)],
		WALK))
		data->player->pos.x = x;
}

static void	strafe(t_data *data)
{
	int		dir;
	float	dir_x;
	float	dir_y;
	float	x;
	float	y;

	dir = 0;
	if (data->keys->a)
		dir--;
	if (data->keys->d)
		dir++;
	dir_x = data->player->plane.x;
	dir_y = data->player->plane.y;
	x = data->player->pos.x + (dir * dir_x * S_SP);
	y = data->player->pos.y + (dir * dir_y * S_SP);
	if (ft_ischarset(data->conf->map[(int)(y)][(int)(data->player->pos.x)],
		WALK))
		data->player->pos.y = y;
	if (ft_ischarset(data->conf->map[(int)(data->player->pos.y)][(int)(x)],
		WALK))
		data->player->pos.x = x;
}

static void	mouse_rotate(t_data *data)
{
	static int	x = 0;
	int			now;
	int			y;

	y = 0;
	now = 0;
	mlx_mouse_get_pos(data->win->mlx_ptr, data->win->win_ptr, &x, &y);
	mlx_mouse_get_pos(data->win->mlx_ptr, data->win->win_ptr, &now, &y);
	if (x != WIN_W >> 1 || data->keys->left || data->keys->right)
		rotate(data, x);
	if (now == x)
		mlx_mouse_move(data->win->mlx_ptr, data->win->win_ptr,
			WIN_W >> 1, WIN_H - 2);
}

void	lol(t_data *data);

int	input(t_data *data)
{
	if (data->keys->esc)
	{
		mlx_loop_end(data->win->mlx_ptr);
		return (0);
	}
	if (data->keys->mouse_mov)
		mouse_rotate(data);
	else if (data->keys->left || data->keys->right)
		rotate(data, WIN_W >> 1);
	if (data->keys->w || data->keys->s)
		walk(data);
	if (data->keys->a || data->keys->d)
		strafe(data);
	if (data->keys->open)
		open_door(data);
	return (0);
}
