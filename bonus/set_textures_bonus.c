/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:16:59 by mchibane          #+#    #+#             */
/*   Updated: 2022/02/03 20:07:11 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*get_info(char *path)
{
	int		ret;
	int		fd;
	char	*str;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	ret = 0;
	while (ret < 3)
	{
		get_next_line(fd, &str);
		free(str);
		ret++;
	}
	get_next_line(fd, &str);
	return (str);
}

static int	set_width(char *info)
{
	while (*info == '\"')
		info++;
	return (ft_atoi(info));
}

static int	set_height(char *info)
{
	while (*info == '\"')
		info++;
	while (ft_isdigit(*info))
		info++;
	return (ft_atoi(info));
}

static int	init_texture(t_texture *tex, t_window *win)
{
	char	*info;

	tex->img.img_ptr = mlx_xpm_file_to_image(win->mlx_ptr, tex->path,
			&tex->img.width, &tex->img.height);
	if (tex->img.img_ptr != NULL)
	{
		tex->img.addr = mlx_get_data_addr(tex->img.img_ptr, &tex->img.bpp,
				&tex->img.line_len, &tex->img.endian);
	}
	else
		return (1);
	info = get_info(tex->path);
	if (!info)
		return (1);
	tex->w = set_width(info);
	tex->h = set_height(info);
	free(info);
	return (0);
}

int	set_textures(t_map_config *conf, t_window *win)
{
	return (init_texture(&conf->no, win)
		|| init_texture(&conf->so, win)
		|| init_texture(&conf->ea, win)
		|| init_texture(&conf->we, win));
}
