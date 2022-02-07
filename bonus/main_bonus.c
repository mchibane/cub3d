/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:59:14 by mchibane          #+#    #+#             */
/*   Updated: 2022/02/07 16:58:54 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static int	set_start(t_map_config	*conf)
{
	int	i;
	int	j;

	i = 0;
	while (conf->map && conf->map[i] && !conf->spawn_dir)
	{
		j = 0;
		while (conf->map[i][j])
		{
			if (ft_ischarset(conf->map[i][j], SPAWN))
			{
				conf->spawn_dir = conf->map[i][j];
				break ;
			}
			j++;
		}
		i++;
	}
	return (0);
}

t_player	init_player(t_map_config *conf)
{
	t_player	ret;

	ret.pos = get_player_pos(conf->map);
	ret.dir = get_player_dir(conf);
	ret.plane = get_plane_dir(conf);
	return (ret);
}

void	envp_error(char **envp)
{
	if (!envp[0])
		printf("Please don't do that !\n");
}

int	main(int ac, char **av, char **envp)
{
	t_map_config	conf;
	t_player		player;

	if (ac != 2)
		return (print_error(E_ARGS));
	if (!envp[0])
		return (print_error(E_ENVI));
	conf = init_map_conf();
	if (parse_file(av[1], &conf) || check_map(conf.map) || set_start(&conf))
	{
		free_conf(conf);
		return (1);
	}
	player = init_player(&conf);
	cub3d(&conf, &player);
	free_conf(conf);
	return (0);
}
