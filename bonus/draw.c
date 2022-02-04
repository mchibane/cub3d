/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:52:40 by mchibane          #+#    #+#             */
/*   Updated: 2022/02/03 18:57:04 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_text_x(t_data *data, t_texture tex, float dist, int side)
{
	float	wall_x;
	int		ret;

	if (side > 1)
		wall_x = data->player->pos.y + dist * data->ray->dir.y;
	else
		wall_x = data->player->pos.x + dist * data->ray->dir.x;
	wall_x -= floorf((wall_x));
	ret = (int)(wall_x * tex.w);
	if (side == EA || side == NO)
		ret = tex.w - ret - 1;
	return (ret);
}

static void	wall(t_data *data, t_texture tex, float dist, int height)
{
	int		tex_x;
	int		tex_y;
	float	step;
	float	tex_pos;
	int		y;

	tex_x = get_text_x(data, tex, dist, tex.side);
	step = 1.0f * tex.h / height;
	y = wall_start(height);
	tex_pos = (y - WIN_H / 2 - height / 2) * step;
	while (y < wall_end(height))
	{
		tex_y = (int)tex_pos & (tex.h - 1);
		tex_pos += step;
		if (data->win->win_ptr != NULL)
			img_pix_put(&data->win->img, data->ray->line, y,
				get_pix_color(&tex.img, tex_x, tex_y));
		y++;
	}
}

static void	draw_wall(t_data *data, float dist, int side, int height)
{
	if (side == NO)
		wall(data, data->conf->no, dist, height);
	if (side == SO)
		wall(data, data->conf->so, dist, height);
	if (side == EA)
		wall(data, data->conf->ea, dist, height);
	if (side == WE)
		wall(data, data->conf->we, dist, height);
}

void	draw(t_data *data, float dist, int side)
{
	int	height;
	int	y;

	height = (int)(WIN_H / dist);
	y = 0;
	while (y < wall_start(height))
		img_pix_put(&data->win->img, data->ray->line, y++,
			data->conf->c.color);
	draw_wall(data, dist, side, height);
	y = wall_end(height);
	while (y < WIN_H)
		img_pix_put(&data->win->img, data->ray->line, y++,
			data->conf->f.color);
}
