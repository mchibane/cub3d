/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 20:46:59 by mchibane          #+#    #+#             */
/*   Updated: 2022/02/02 17:44:40 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_ray	*init_ray(t_map_config *conf)
{
	t_ray	*ret;

	ret = malloc(sizeof(*ret));
	ret->player_pos = get_player_pos(conf->map);
	ret->player_dir = get_player_dir(conf);
	ret->plane = get_plane_dir(conf);
	return (ret);
}
