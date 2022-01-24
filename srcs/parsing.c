/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:34:26 by mchibane          #+#    #+#             */
/*   Updated: 2022/01/24 22:05:58 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int	get_path(char **t, t_map_config *m)
{
	if (ft_strequal(t[0], N_TOK) && ++m->no.exists == 1)
		m->no.path = ft_strdup(t[1]);
	else if (ft_strequal(t[0], S_TOK) && ++m->so.exists == 1)
		m->so.path = ft_strdup(t[1]);
	else if (ft_strequal(t[0], E_TOK) && ++m->ea.exists == 1)
		m->ea.path = ft_strdup(t[1]);
	else if (ft_strequal(t[0], W_TOK) && ++m->we.exists == 1)
		m->we.path = ft_strdup(t[1]);
	else if (ft_strequal(t[0], F_TOK) && ++m->f.exists == 1)
		m->f.raw = ft_strdup(t[1]);
	else if (ft_strequal(t[0], C_TOK) && ++m->c.exists == 1)
		m->c.raw = ft_strdup(t[1]);
	else
		return (1);
	return (0);
}

int	get_line_info(char *str, t_map_config *conf)
{
	char	**tab;

	tab = ft_split(str, ' ');
	if (!tab || tab_len(tab) != 2)
	{
		free_tab(tab);
		return (1);
	}
	if (get_path(tab, conf))
	{
		free_tab(tab);
		return (1);
	}
	free_tab(tab);
	return (0);
}

static int	parse_lines(int fd, t_map_config *conf, int *line)
{
	char	*str;
	int		gnl;
	int		check;

	check = 0;
	gnl = 1;
	while (gnl > 0 && !check)
	{
		gnl = get_next_line(fd, &str);
		(*line)++;
		if (str[0])
		{
			if (get_line_info(str, conf))
			{
				printf("Error\nInvalid configuration file. (line %d)\n", *line);
				free(str);
				return (1);
			}
		}
		check = check_textures(conf);
		free(str);
	}
	return (0);
}

int	parse_file(char *path, t_map_config *conf)
{
	int	fd;
	int	head;

	head = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\n");
		perror(path);
		return (1);
	}
	if (parse_lines(fd, conf, &head) || set_colors(conf))
	{
		close(fd);
		return (1);
	}
	if (map_parsing(conf, fd))
	{
		printf("Error\nsomething went wrong when parsing the map.\n");
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}
