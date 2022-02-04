/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:11:37 by mchibane          #+#    #+#             */
/*   Updated: 2022/02/04 17:25:30 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_keys	init_keys(void)
{
	t_keys	ret;

	ret.w = 0;
	ret.a = 0;
	ret.s = 0;
	ret.d = 0;
	ret.esc = 0;
	ret.left = 0;
	ret.right = 0;
	return (ret);
}

int	key_press(int keysym, t_data *data)
{
	if (keysym == XK_w)
		data->keys->w = 1;
	if (keysym == XK_a)
		data->keys->a = 1;
	if (keysym == XK_s)
		data->keys->s = 1;
	if (keysym == XK_d)
		data->keys->d = 1;
	if (keysym == XK_Escape)
		data->keys->esc = 1;
	if (keysym == XK_Left)
		data->keys->left = 1;
	if (keysym == XK_Right)
		data->keys->right = 1;
	return (0);
}

int	key_release(int keysym, t_data *data)
{
	if (keysym == XK_w)
		data->keys->w = 0;
	if (keysym == XK_a)
		data->keys->a = 0;
	if (keysym == XK_s)
		data->keys->s = 0;
	if (keysym == XK_d)
		data->keys->d = 0;
	if (keysym == XK_Escape)
		data->keys->esc = 0;
	if (keysym == XK_Left)
		data->keys->left = 0;
	if (keysym == XK_Right)
		data->keys->right = 0;
	return (0);
}
