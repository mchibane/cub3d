/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:50:47 by mchibane          #+#    #+#             */
/*   Updated: 2022/02/07 16:58:11 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	get_pix_color(t_img *tex, int x, int y)
{
	char	*ret;

	ret = tex->addr + ((y * tex->line_len) + (x * (tex->bpp / 8)));
	return (*(int *)ret);
}

void	img_pix_put(t_img *img, int x, int y, int color)
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

int	wall_end(int height)
{
	int	ret;

	ret = (height >> 1) + (WIN_H >> 1);
	if (ret >= WIN_H)
		ret = WIN_H - 1;
	return (ret);
}

int	wall_start(int height)
{
	int	ret;

	ret = (-height >> 1) + (WIN_H >> 1);
	if (ret < 0)
		ret = 0;
	return (ret);
}
