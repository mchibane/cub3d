/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:59:11 by mchibane          #+#    #+#             */
/*   Updated: 2022/02/02 19:34:24 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	raycasting(t_data *data)
{
	t_vec2	player_pos;
	t_vec2	player_dir;
	t_vec2	plane;


	player_pos = data->ray->player_pos;
	player_dir = data->ray->player_dir;
	plane = data->ray->plane;

	int	i = 0;
	while (i < WIN_W)
	{
		// ray position and direction
		float	cam_x = 2 * i / (float)WIN_W - 1.0f;
		float	ray_x = player_dir.x + plane.x * cam_x;
		float	ray_y = player_dir.y + plane.y * cam_x;

		//which box of the map we're in
		int	map_x = (int)player_pos.x;
		int	map_y = (int)player_pos.y;

		//length of ray from current pos to next x or y side
		float	side_dist_x;
		float	side_dist_y;

		//length of ray from one x or y side to next x or y side
		float	d_dist_x = (ray_x == 0) ? FLT_MAX : f_abs(1 / ray_x);
		float	d_dist_y = (ray_y == 0) ? FLT_MAX : f_abs(1 / ray_y);
		float	perp_wall; // perpendicular wall distance

		// what direction to step in x or y direction (+1 or -1)
		int	step_x;
		int	step_y;

		int	hit = 0;	// was there a wall hit ?
		int	side;		// was a NO-SO or EA-WE wall hit ?

		// calculate step and initial side_dist
		if (ray_x < 0)
		{
			step_x = -1;
			side_dist_x = (player_pos.x - map_x) * d_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0f - player_pos.x) * d_dist_x;
		}
		if (ray_y < 0)
		{
			step_y = -1;
			side_dist_y = (player_pos.y - map_y) * d_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0f - player_pos.y) * d_dist_y;
		}
		while (!hit)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += d_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += d_dist_y;
				map_y += step_y;
				side = 1;
			}
			if (data->conf->map[map_y][map_x] == '1')
				hit = 1;
		}
		if (side == 0)
			perp_wall = (side_dist_x - d_dist_x);
		else
			perp_wall = (side_dist_y - d_dist_y);
		draw(data, perp_wall, i, side);
		i++;
	}
	if (data->win->win_ptr != NULL)
		mlx_put_image_to_window(data->win->mlx_ptr, data->win->win_ptr, data->win->img.img_ptr, 0, 0);
	return (0);
}
