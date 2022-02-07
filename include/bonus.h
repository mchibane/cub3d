/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:29:56 by mchibane          #+#    #+#             */
/*   Updated: 2022/02/07 20:02:10 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

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
# define D_TOK "D"
# define N_TOK "NO"
# define S_TOK "SO"
# define W_TOK "WE"
# define E_TOK "EA"

# define E_ARGS "Error\nUsage: ./cub3D [map].cub"
# define E_ENVI "Error\nPlease don't do this !"

# define MAP_CHARSET " 01NSWEC0"
# define SPAWN "NWES"
# define CHECK_CHARSET "0NSWECO"
# define WALK "0NSEWO"
# define WALL "1C"
# define OPEN "O"
# define CLOSED "C"

# define WIN_W 1280
# define WIN_H 720

# define FOV 0.9f

# define M_SP 0.18f
# define R_SP 0.10f
# define S_SP 0.1f

# define RED 0xff0000
# define GREEN 0x00ff00
# define BLUE 0x0000ff
# define YELLOW 0xe8ff00

typedef enum e_side
{
	NO,
	SO,
	EA,
	WE,
	DO,
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

typedef struct s_ivec2
{
	int	x;
	int	y;
}				t_ivec2;

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
	int		h;
	int		w;
	int		exists;
	int		side;
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
	t_texture	d;
	t_color		f;
	t_color		c;
	char		**map;
	char		spawn_dir;
}				t_map_config;

/*
**	PLAYER POS & DIR
*/

typedef struct s_player
{
	t_vec2	pos;
	t_vec2	dir;
	t_vec2	plane;
}				t_player;

/*
**	RAY STRUCT
*/

typedef struct s_ray
{
	t_vec2	dir;
	t_vec2	side_dist;
	t_vec2	d_dist;
	t_ivec2	map;
	t_ivec2	step;
	int		line;
}			t_ray;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	esc;
	int	left;
	int	right;
	int	tab;
	int	mouse_mov;
	int	open;
}				t_keys;

typedef struct s_data
{
	t_window		*win;
	t_map_config	*conf;
	t_player		*player;
	t_ray			*ray;
	t_keys			*keys;
}				t_data;

typedef struct s_minimap
{
	int	width;
	int	height;
	int	tile_size;
}				t_minimap;

int				parse_file(char *path, t_map_config *conf);
t_map_config	init_map_conf(void);
t_window		init_window(void);
t_ray			init_ray(void);
void			update_ray(t_data *data, int i, t_ray *ray);

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

int				cub3d(t_map_config *conf, t_player *ray);
int				c3d_exit(t_data *data);

int				input(t_data *data);
int				raycasting(t_data *data);
t_vec2			get_player_pos(char **map);
t_vec2			get_player_dir(t_map_config	*conf);
t_vec2			get_plane_dir(t_map_config *conf);

float			f_abs(float f);

void			draw(t_data *data, float dist, int side, int door);

int				move(int keysym, t_data *data);
int				turn(int keysym, t_data *data);

int				get_pix_color(t_img *tex, int x, int y);
void			img_pix_put(t_img *img, int x, int y, int color);
int				wall_end(int height);
int				wall_start(int height);

void			hooks(t_data *data);

t_keys			init_keys(void);
int				key_press(int keysym, t_data *data);
int				key_release(int keysym, t_data *data);

void	minimap(t_data *data);

#endif
