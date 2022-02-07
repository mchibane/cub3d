/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:45:16 by mchibane          #+#    #+#             */
/*   Updated: 2022/02/07 17:16:16 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static int	check_charset(char **map)
{
	int	i;
	int	j;
	int	spawn;

	i = 0;
	spawn = 0;
	while (map && map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_ischarset(map[i][j], SPAWN))
				spawn++;
			if (!ft_ischarset(map[i][j], MAP_CHARSET))
			{
				print_error("Error\nUnauthorized character in map");
				return (1);
			}
			j++;
		}
		i++;
	}
	if (spawn != 1)
		return (print_error("Error\nThere must be exactly 1 spawn (N E S W)"));
	return (0);
}

static int	check_line(char **map, int i, int j)
{
	int	idx;

	if (j == 0)
		return (1);
	idx = j;
	while (map[i][idx])
	{
		if (map[i][idx] == '1')
			break ;
		if (map[i][idx] == ' ')
			return (1);
		idx++;
	}
	if (idx == (int)ft_strlen(map[i]))
		return (1);
	idx = j;
	while (idx >= 0)
	{
		if (map[i][idx] == '1')
			return (0);
		if (map[i][idx] == ' ')
			return (1);
		idx--;
	}
	return (0);
}

static int	check_col(char **map, int i, int j)
{
	int	idx;

	if (i == 0 || i == tab_len(map) - 1)
		return (1);
	idx = i;
	while (idx < tab_len(map))
	{
		if (map[idx][j] == '1')
			break ;
		if (map[idx][j] == ' ')
			return (1);
		idx++;
	}
	if (idx == tab_len(map))
		return (1);
	idx = i;
	while (idx >= 0)
	{
		if (map[idx][j] == '1')
			break ;
		if (map[idx][j] == ' ')
			return (1);
		idx--;
	}
	return (0);
}

static int	check_close(char **map, int i, int j)
{
	if (check_line(map, i, j) || check_col(map, i, j))
	{
		print_error("Error\nMap not closed. (surrounded by walls)");
		return (1);
	}
	return (0);
}

int	check_map(char **map)
{
	int	i;
	int	j;

	if (check_charset(map))
		return (1);
	i = 0;
	while (map && map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_ischarset(map[i][j], CHECK_CHARSET))
			{
				if (check_close(map, i, j))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
