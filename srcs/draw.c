/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:52:40 by mchibane          #+#    #+#             */
/*   Updated: 2022/02/02 21:13:04 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

static int	wall_end(int height)
{
	int	ret;

	ret = (height / 2) + (WIN_H / 2);
	if (ret >= WIN_H)
		ret = WIN_H - 1;
	return (ret);
}

static int	wall_start(int height)
{
	int	ret;

	ret = (-height / 2) + (WIN_H / 2);
	if (ret < 0)
		ret = 0;
	return (ret);
}

static int	set_wall_color(int side)
{
	int	ret;

	if (side == NO)
		ret = RED;
	else if (side == SO)
		ret = BLUE;
	else if (side == WE)
		ret = GREEN;
	else if (side == EA)
		ret = YELLOW;
	return (ret);
}

void	draw(t_data *data, float dist, int x, int side)
{
	int	height;
	int	y;
	int	start;
	int	end;
	int	wall_color;

	height = (int)(WIN_H / dist);
	y = 0;
	start = wall_start(height);
	end = wall_end(height);
	wall_color = set_wall_color(side);
	while (y < start)
		img_pix_put(&data->win->img, x, y++, data->conf->c.color);
	while (y < end)
		img_pix_put(&data->win->img, x, y++, wall_color);
	while (y < WIN_H)
		img_pix_put(&data->win->img, x, y++, data->conf->f.color);
}
