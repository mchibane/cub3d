/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:27:21 by mchibane          #+#    #+#             */
/*   Updated: 2022/02/07 21:58:33 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	open_door(t_data *data)
{
	int	y;
	int	x;

	y = (int)(data->player->pos.y + data->player->dir.y);
	x = (int)(data->player->pos.x + data->player->dir.x);
	if (data->conf->map[y][x] == 'C')
		data->conf->map[y][x] = 'O';
	else if (data->conf->map[y][x] == 'O')
		data->conf->map[y][x] = 'C';
	data->keys->open = 0;
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
	if (now - t0 < 200)
		printf("--- 1 --- %lu\n", now - t0);
	else if (now - t0 < 400)
		printf("--- 2 --- %lu\n", now - t0);
	else if (now - t0 < 600)
		printf("--- 3 --- %lu\n", now - t0);
	else if (now - t0 < 800)
		printf("--- 4 --- %lu\n", now - t0);
	else
	{
		printf("end\n");
		data->keys->fire = 0;
	}
}

void	lol(t_data *data)
{
	static int	loop = 1;

	if (data->keys->fire)
	{
		fire(data, &loop);
		if (!data->keys->fire)
			loop = 1;
	}
}
