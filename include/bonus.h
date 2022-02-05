/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:29:56 by mchibane          #+#    #+#             */
/*   Updated: 2022/02/04 21:46:49 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include "cub3d.h"

typedef struct s_minimap
{
	int	width;
	int	height;
	int	tile_size;
}				t_minimap;

void	minimap(t_data *data);

#endif
