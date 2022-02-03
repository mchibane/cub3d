/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 20:46:59 by mchibane          #+#    #+#             */
/*   Updated: 2022/02/03 16:21:47 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_rdir(t_data *data, int i, t_ray	*ray)
{
	float	cam_x;

	cam_x = 2 * i / (float)WIN_W - 1.0f;
	ray->dir.x = data->player->dir.x + data->player->plane.x * cam_x;
	ray->dir.y = data->player->dir.y + data->player->plane.y * cam_x;
}

static void	set_ddist(t_ray *ray)
{
	if (ray->dir.x != 0.0f)
		ray->d_dist.x = f_abs(1 / ray->dir.x);
	else
		ray->d_dist.x = FLT_MAX;
	if (ray->dir.y != 0.0f)
		ray->d_dist.y = f_abs(1 / ray->dir.y);
	else
		ray->d_dist.y = FLT_MAX;
}

static void	set_sdist(t_data *data, t_ray *ray)
{
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (data->player->pos.x - ray->map.x) * ray->d_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->map.x + 1.0f - data->player->pos.x) * ray->d_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (data->player->pos.y - ray->map.y) * ray->d_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->map.y + 1.0f - data->player->pos.y) * ray->d_dist.y;
	}
}

static void	set_map(t_player *player, t_ray *ray)
{
	ray->map.x = (int)player->pos.x;
	ray->map.y = (int)player->pos.y;
}

void	update_ray(t_data *data, int i, t_ray *ray)
{
	set_rdir(data, i, ray);
	set_map(data->player, ray);
	set_ddist(ray);
	set_sdist(data, ray);
}
