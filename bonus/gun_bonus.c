/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:02:41 by mchibane          #+#    #+#             */
/*   Updated: 2022/02/08 16:15:37 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	draw_gun(t_data *data, int offset)
{
	int	y;
	int	x;
	int	tex_x;
	int	tex_y;
	int	color;

	tex_y = 0;
	y = WIN_H - data->conf->gun.h;
	while (y < WIN_H)
	{
		tex_x = offset * (data->conf->gun.w >> 2);
		x = (WIN_W >> 1) - (data->conf->gun.w >> 3);
		while (x < ((WIN_W >> 1) - (data->conf->gun.w >> 3))
			+ (data->conf->gun.w >> 2))
		{
			color = get_pix_color(&data->conf->gun.img, tex_x, tex_y);
			if (color != 0x000000)
				img_pix_put(&data->win->img, x, y, color);
			tex_x++;
			x++;
		}
		tex_y++;
		y++;
	}
}

time_t	get_t0(void)
{
	struct timeval	tv;
	time_t			ret;

	gettimeofday(&tv, NULL);
	ret = 1000 * tv.tv_sec;
	ret += tv.tv_usec / 1000;
	return (ret);
}

void	fire(t_data *data, int *start)
{
	static time_t	t0 = 0;
	time_t			now;

	if (*start)
	{
		t0 = get_t0();
		*start = 0;
	}
	now = get_t0();
	if (now - t0 < 100)
		draw_gun(data, 1);
	else if (now - t0 < 200)
		draw_gun(data, 2);
	else if (now - t0 < 300)
		draw_gun(data, 3);
	else
	{
		draw_gun(data, 1);
		data->keys->fire = 0;
	}
}

void	gun(t_data *data)
{
	static int	loop = 1;

	if (!data->keys->fire)
		draw_gun(data, 0);
	else
	{
		fire(data, &loop);
		if (!data->keys->fire)
			loop = 1;
	}
}
