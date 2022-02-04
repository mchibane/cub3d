/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 16:57:13 by mchibane          #+#    #+#             */
/*   Updated: 2022/02/04 15:01:40 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vec2	get_player_pos(char **map)
{
	int		y;
	int		x;
	t_vec2	ret;

	y = 0;
	while (map && map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_ischarset(map[y][x], SPAWN))
			{
				ret.y = (float)y + 0.49f;
				ret.x = (float)x + 0.49f;
				map[y][x] = '0';
				break ;
			}
			x++;
		}
		y++;
	}
	return (ret);
}

t_vec2	get_plane_dir(t_map_config *conf)
{
	t_vec2	ret;

	ret.x = 0.0f;
	ret.y = 0.0f;
	if (conf->spawn_dir == 'W')
		ret.y = -FOV;
	else if (conf->spawn_dir == 'E')
		ret.y = FOV;
	else if (conf->spawn_dir == 'N')
		ret.x = FOV;
	else if (conf->spawn_dir == 'S')
		ret.x = -FOV;
	return (ret);
}

t_vec2	get_player_dir(t_map_config	*conf)
{
	t_vec2	ret;

	ret.x = 0.0f;
	ret.y = 0.0f;
	if (conf->spawn_dir == 'N')
		ret.y = -1.0f;
	else if (conf->spawn_dir == 'S')
		ret.y = 1.0f;
	else if (conf->spawn_dir == 'W')
		ret.x = -1.0f;
	else if (conf->spawn_dir == 'E')
		ret.x = 1.0f;
	return (ret);
}

float	f_abs(float f)
{
	if (f < 0)
		f *= -1;
	return (f);
}
