/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:59:14 by mchibane          #+#    #+#             */
/*   Updated: 2022/01/24 21:07:36 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	envp_error(char **envp)
{
	if (!envp[0])
		printf("Please don't do that !\n");
}

int	main(int ac, char **av, char **envp)
{
	t_map_config	conf;

	(void)av;
	if (ac != 2 || !envp[0])
	{
		printf("Error: Usage: ./cub3D [map_path]\n");
		envp_error(envp);
		return (1);
	}
	conf = init_map_conf();
	if (parse_file(av[1], &conf))
	{
		free_conf(conf);
		return (1);
	}
	printf("Welcome to Cub3D !\n");
	print_map_conf(conf);
	free_conf(conf);
	return (0);
}
