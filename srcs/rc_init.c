/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:41:08 by mchibane          #+#    #+#             */
/*   Updated: 2022/02/03 18:15:24 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_vec2	empty_vec2(void)
{
	t_vec2	ret;

	ret.x = 0.0f;
	ret.y = 0.0f;
	return (ret);
}

static t_ivec2	empty_ivec2(void)
{
	t_ivec2	ret;

	ret.x = 0;
	ret.y = 0;
	return (ret);
}

t_ray	init_ray(void)
{
	t_ray	ret;

	ret.dir = empty_vec2();
	ret.side_dist = empty_vec2();
	ret.d_dist = empty_vec2();
	ret.map = empty_ivec2();
	ret.step = empty_ivec2();
	ret.line = 0;
	return (ret);
}
