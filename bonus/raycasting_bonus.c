/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:59:11 by mchibane          #+#    #+#             */
/*   Updated: 2022/02/07 16:59:30 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static int	set_side(t_ray *ray, int dir)
{
	if (!dir)
	{
		if (ray->dir.x > 0)
			return (EA);
		return (WE);
	}
	else
	{
		if (ray->dir.y < 0)
			return (NO);
		return (SO);
	}
}

static int	hit_loop(t_data *data, t_ray *ray)
{
	int	hit;
	int	ret;

	hit = 0;
	while (!hit)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->d_dist.x;
			ray->map.x += ray->step.x;
			ret = set_side(ray, 0);
		}
		else
		{
			ray->side_dist.y += ray->d_dist.y;
			ray->map.y += ray->step.y;
			ret = set_side(ray, 1);
		}
		if (data->conf->map[ray->map.y][ray->map.x] == '1')
			hit = 1;
	}
	return (ret);
}

static void	redisplay(t_data *data)
{
	if (data->keys->tab)
		minimap(data);
	if (data->win->win_ptr != NULL)
		mlx_put_image_to_window(data->win->mlx_ptr,
			data->win->win_ptr, data->win->img.img_ptr, 0, 0);
}

int	raycasting(t_data *data)
{
	float	perp_wall;
	int		side;
	t_ray	ray;
	int		i;

	ray = init_ray();
	i = 0;
	data->ray = &ray;
	input(data);
	while (i < WIN_W)
	{
		update_ray(data, i, &ray);
		side = hit_loop(data, &ray);
		if (side > 1)
			perp_wall = (ray.side_dist.x - ray.d_dist.x);
		else
			perp_wall = (ray.side_dist.y - ray.d_dist.y);
		draw(data, perp_wall, side);
		i++;
	}
	data->ray = NULL;
	redisplay(data);
	return (0);
}
