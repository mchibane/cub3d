/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:24:29 by mchibane          #+#    #+#             */
/*   Updated: 2022/01/31 17:38:00 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	add_sep(char **s)
{
	char	*tmp;

	tmp = *s;
	*s = ft_strjoin(tmp, "-");
	free(tmp);
	if (!*s)
		return (1);
	return (0);
}

char	*set_begin(int fd)
{
	char	*ret;
	int		gnl;

	gnl = 1;
	while (gnl > 0)
	{
		gnl = get_next_line(fd, &ret);
		if (gnl == -1)
		{
			free(ret);
			return (NULL);
		}
		if (ret[0])
			break ;
		free(ret);
	}
	if (add_sep(&ret))
		return (NULL);
	return (ret);
}

int	set_map(t_map_config *conf, char *s)
{
	char	**tmp;
	char	**map;

	if (!s)
		return (1);
	tmp = ft_split(s, '-');
	if (!tmp)
	{
		free(s);
		return (1);
	}
	map = add_spaces(tmp);
	if (!map)
	{
		free_tab(tmp);
		free(s);
		return (1);
	}
	conf->map = map;
	free(s);
	free_tab(tmp);
	return (0);
}

static int	gnl_loop(char **str, int fd)
{
	char	*buff;
	char	*tmp;
	int		ret;

	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &buff);
		if (buff[0])
		{
			tmp = *str;
			*str = ft_strjoin(tmp, buff);
			if (!str)
			{
				free_strs(tmp, buff, NULL, NULL);
				return (1);
			}
			add_sep(str);
			free_strs(tmp, buff, NULL, NULL);
			continue ;
		}
		free(buff);
		break ;
	}
	return (0);
}

int	map_parsing(t_map_config *conf, int fd)
{
	char	*str;

	str = set_begin(fd);
	if (!str)
		return (1);
	if (gnl_loop(&str, fd))
		return (1);
	return (set_map(conf, str));
}
