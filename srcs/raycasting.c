/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:59:11 by mchibane          #+#    #+#             */
/*   Updated: 2022/02/03 16:46:08 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	print_ray_info(t_ray *ray)
// {
// 	printf("RAY INFO \n");
// 	printf("DIR X : %f DIR Y : %f\n", ray->dir.x, ray->dir.y);
// 	printf("S_DIST X : %f S_DIST Y : %f\n", ray->side_dist.x, ray->side_dist.y);
// 	printf("D_DIST X : %f D_DIST Y : %f\n", ray->d_dist.x, ray->d_dist.y);
// 	printf("MAP X : %d MAP Y : %d\n", ray->map.x, ray->map.y);
// 	printf("STEP X : %d STEP Y : %d\n\n", ray->step.x, ray->step.y);
// }

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

int	raycasting(t_data *data)
{
	float	perp_wall;
	int		side;
	t_ray	ray;

	ray = init_ray();
	int		i;
	i = 0;
	while (i < WIN_W)
	{
		update_ray(data, i, &ray);
		side = hit_loop(data, &ray);
		if (side > 1)
			perp_wall = (ray.side_dist.x - ray.d_dist.x);
		else
			perp_wall = (ray.side_dist.y - ray.d_dist.y);

		draw(data, perp_wall, i, side);
		i++;
	}
	if (data->win->win_ptr != NULL)
		mlx_put_image_to_window(data->win->mlx_ptr, data->win->win_ptr, data->win->img.img_ptr, 0, 0);
	return (0);
}
