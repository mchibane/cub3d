/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:58:45 by mchibane          #+#    #+#             */
/*   Updated: 2022/01/24 22:27:28 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include "libft.h"

# define F_TOK "F"
# define C_TOK "C"
# define N_TOK "NO"
# define S_TOK "SO"
# define W_TOK "WE"
# define E_TOK "EA"

# define E_ARGS "Error\nUsage: ./cub3D [map].cub"
# define E_ENVI "Error\nPlease don't do this !"

typedef struct s_texture
{
	char	*path;
	int		exists;
}				t_texture;

typedef struct s_color
{
	char	*raw;
	int		color;
	int		exists;
}				t_color;

typedef struct s_map_config
{
	t_texture	no;
	t_texture	so;
	t_texture	ea;
	t_texture	we;
	t_color		f;
	t_color		c;
	char		**map;
}				t_map_config;

int				parse_file(char *path, t_map_config *conf);
t_map_config	init_map_conf(void);

void			print_map_conf(t_map_config	conf);
int				print_error(char *s);

int				check_textures(t_map_config *conf);
int				tab_len(char **tab);
void			free_tab(char **tab);
void			free_conf(t_map_config conf);
void			free_strs(char *s1, char *s2, char *s3, char *s4);
int				get_width(char **tab);
char			**add_spaces(char **map);

int				set_colors(t_map_config *conf);

int				map_parsing(t_map_config *conf, int fd);

#endif
