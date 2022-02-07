/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 21:10:45 by mchibane          #+#    #+#             */
/*   Updated: 2022/02/07 18:19:19 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

t_minimap	init_minimap(t_data *data)
{
	t_minimap	ret;

	ret.width = WIN_W / 4;
	ret.height = WIN_H / 4;
	ret.tile_size = ret.width / get_width(data->conf->map);
	return (ret);
}

static int	get_color(int i, int j, t_data *data)
{
	if (i == (int)data->player->pos.y && j == (int)data->player->pos.x)
		return (0xAF24E0);
	else if (data->conf->map[i][j] == '1')
		return (0x3d3d3d);
	else if (data->conf->map[i][j] == '0')
		return (0xcfcfcf);
	else if (data->conf->map[i][j] == 'C')
		return (GREEN);
	else
		return (0x000000);
}

static int	blend_color(int x, int y, int color, t_img *img)
{
	int	bg;

	bg = get_pix_color(img, x, y);
	return (((color >> 1) & 8355711) + ((bg >> 1) & 8355711));
}

static void	draw_tile(int i, int j, t_data *data, t_minimap *minimap)
{
	int	x_start;
	int	y_start;
	int	x;
	int	y;
	int	color;

	color = get_color(i, j, data);
	if (!color)
		return ;
	x_start = j * minimap->tile_size + minimap->tile_size;
	y_start = i * minimap->tile_size + minimap->tile_size;
	y = y_start;
	while (y < WIN_H && y < (i + 1) * minimap->tile_size + minimap->tile_size)
	{
		x = x_start;
		while (x < (j + 1) * minimap->tile_size + minimap->tile_size)
		{
			img_pix_put(&data->win->img, x, y,
				blend_color(x, y, color, &data->win->img));
			x++;
		}
		y++;
	}
}

void	minimap(t_data *data)
{
	int			i;
	int			j;
	t_minimap	minimap;

	minimap = init_minimap(data);
	i = 0;
	while (data->conf->map && data->conf->map[i])
	{
		j = 0;
		while (data->conf->map[i][j])
		{
			draw_tile(i, j, data, &minimap);
			j++;
		}
		i++;
	}
}
