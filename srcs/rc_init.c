/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 20:46:59 by mchibane          #+#    #+#             */
/*   Updated: 2022/02/03 14:00:15 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_player	init_player(t_map_config *conf)
{
	t_player	ret;

	ret.pos = get_player_pos(conf->map);
	ret.dir = get_player_dir(conf);
	ret.plane = get_plane_dir(conf);
	return (ret);
}
