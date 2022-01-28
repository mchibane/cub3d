/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:59:14 by mchibane          #+#    #+#             */
/*   Updated: 2022/01/28 14:54:05 by mchibane         ###   ########.fr       */
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

	if (ac != 2)
		return (print_error(E_ARGS));
	if (!envp[0])
		return (print_error(E_ENVI));
	conf = init_map_conf();
	if (parse_file(av[1], &conf) || check_map(conf.map))
	{
		free_conf(conf);
		return (1);
	}
	printf("Welcome to Cub3D !\n");
	print_map_conf(conf);
	free_conf(conf);
	return (0);
}
