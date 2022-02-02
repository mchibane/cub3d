/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:58:45 by mchibane          #+#    #+#             */
/*   Updated: 2022/02/02 19:44:20 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <limits.h>
# include <float.h>
# include <math.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "libft.h"
# include "mlx.h"

# define F_TOK "F"
# define C_TOK "C"
# define N_TOK "NO"
# define S_TOK "SO"
# define W_TOK "WE"
# define E_TOK "EA"

# define E_ARGS "Error\nUsage: ./cub3D [map].cub"
# define E_ENVI "Error\nPlease don't do this !"

# define MAP_CHARSET " 01NSWE"
# define SPAWN "NWES"

# define WIN_W 1280
# define WIN_H 720

# define FOV 0.6f

# define M_SP 0.5f
# define R_SP 0.07f
# define S_SP 0.1f

typedef enum e_side
{
	NO,
	SO,
	EA,
	WE,
	MAX
}			t_side;

/*
**	VECTOR 2
*/

typedef struct s_vec2
{
	float	x;
	float	y;
}				t_vec2;

/*
**	MLX RELATED STRUCTS
*/

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}				t_window;

/*
**	CONFIGURATION FILE STRUCTS
*/

typedef struct s_texture
{
	char	*path;
	t_img	img;
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
	char		spawn_dir;
}				t_map_config;

typedef struct s_ray
{
	t_vec2	player_pos;
	t_vec2	player_dir;
	t_vec2	plane;
}				t_ray;

typedef struct s_data
{
	t_window		*win;
	t_map_config	*conf;
	t_ray			*ray;
}				t_data;

int				parse_file(char *path, t_map_config *conf);
t_map_config	init_map_conf(void);
t_window		init_window(void);
t_ray			*init_ray(t_map_config *conf);

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
int				set_textures(t_map_config *conf, t_window *win);

int				map_parsing(t_map_config *conf, int fd);
int				check_map(char **map);

int				cub3d(t_map_config *conf, t_ray *ray);
int				c3d_exit(t_data *data);

int				input(int keysym, t_data *data);
int				raycasting(t_data *data);
t_vec2			get_player_pos(char **map);
t_vec2			get_player_dir(t_map_config	*conf);
t_vec2			get_plane_dir(t_map_config *conf);

float			f_abs(float f);

void			draw(t_data *data, float dist, int x, int side);

int				move(int keysym, t_data *data);
int				turn(int keysym, t_data *data);

#endif
