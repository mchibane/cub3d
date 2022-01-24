/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:10:47 by mchibane          #+#    #+#             */
/*   Updated: 2022/01/24 19:43:21 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_color	init_color(void)
{
	t_color	ret;

	ret.color = 0;
	ret.exists = 0;
	ret.raw = NULL;
	return (ret);
}

static t_texture	init_texture(void)
{
	t_texture	ret;

	ret.path = NULL;
	ret.exists = 0;
	return (ret);
}

t_map_config	init_map_conf(void)
{
	t_map_config	ret;

	ret.no = init_texture();
	ret.so = init_texture();
	ret.we = init_texture();
	ret.ea = init_texture();
	ret.f = init_color();
	ret.c = init_color();
	ret.map = NULL;
	return (ret);
}
