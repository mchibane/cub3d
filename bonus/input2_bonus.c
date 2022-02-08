/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:27:21 by mchibane          #+#    #+#             */
/*   Updated: 2022/02/08 14:02:57 by mchibane         ###   ########.fr       */
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
