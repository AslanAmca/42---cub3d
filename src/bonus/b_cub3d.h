/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_cub3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:19:44 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/09 04:07:29 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_CUB3D_H
# define B_CUB3D_H

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
# define MOVE_SPEED 0.075
# define TURN_SPEED 0.05
# define CURSOR_SPEED 0.02

# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_MOUSEMOVE 6
# define ON_DESTROY 17

# ifdef __linux__
#  define KEY_ESC 65307
#  define KEY_W 119
#  define KEY_S 115
#  define KEY_A 97
#  define KEY_D 100
#  define KEY_E 101
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
# endif

# ifdef __APPLE__
#  define KEY_ESC 53
#  define KEY_W 13
#  define KEY_S 1
#  define KEY_A 0
#  define KEY_D 2
#  define KEY_E 14
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
# endif

# ifdef __linux__
#  include "../../mlx_linux/mlx.h"
# endif

# ifdef __APPLE__
#  include "../../mlx/mlx.h"
# endif

# include "../utilities/utilities.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

typedef struct s_xpm_files
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;

	int		north_count;
	int		south_count;
	int		west_count;
	int		east_count;
}			t_xpm_files;

typedef struct s_color
{
	char	*red_string;
	char	*green_string;
	char	*blue_string;
	char	*string;

	int		count;
	int		red;
	int		green;
	int		blue;
}			t_color;

typedef struct s_map
{
	char	**text;
	int		starting_line;
	int		row_count;
	int		col_count;

	int		player_count;
	int		player_row;
	int		player_col;

	int		door_count;
}			t_map;

typedef struct s_config
{
	int			argument_count;
	char		*filename;

	char		**text;
	int			total_line_count;
	int			full_line_count;
	int			empty_line_count;

	t_xpm_files	*xpm_files;
	t_color		*floor_color;
	t_color		*ceiling_color;
	t_map		*map;
}				t_config;

typedef struct s_vector_double
{
	double	x;
	double	y;
}			t_vector_double;

typedef struct s_vector_int
{
	int	x;
	int	y;
}		t_vector_int;

typedef struct s_player
{
	t_vector_double	position;
	t_vector_double	direction;
	t_vector_double	camera_plane;
}				t_player;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
}		t_keys;

typedef struct s_mlx_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}			t_mlx_image;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_mlx_image	*screen;
	t_mlx_image	*north_image;
	t_mlx_image	*south_image;
	t_mlx_image	*west_image;
	t_mlx_image	*east_image;
	int			floor_rgb;
	int			ceiling_rgb;
	t_keys		keys;
	t_player	*player;

	int			cursor_x;
	int			is_cursor_move;
	t_mlx_image	*door0_image;
	t_mlx_image	*door1_image;
	t_mlx_image	*door2_image;
	t_mlx_image	*door3_image;
}				t_game;

typedef struct s_cub3d
{
	t_config	*config;
	t_game		*game;
}				t_cub3d;

typedef struct s_screen
{
	long	wall_height;
	int		wall_start_point;
	int		wall_end_point;
	int		hit_point_wall_texture;
	double	texture_offset_y;
	double	texture_pixel_ratio;
}			t_screen;

typedef struct s_ray
{
	t_vector_int	map_position;
	t_vector_double	real_position;
	t_vector_double	direction;
	t_vector_double	initial_hit_dist;
	t_vector_double	next_hit_dist;
	t_vector_int	map_step;
	int				hit_wall;
	char			hit_wall_side;
	double			wall_perp_dist;
	double			hit_point_wall;
	t_screen		screen;
}					t_ray;

int		b_not_wall(char character);
void	b_get_player_position(t_cub3d *cub3d, int *row, int *col);
void	b_init_config(t_cub3d *cub3d, int argument_count, char *filename);
void	b_free_config(t_cub3d *cub3d);
void	b_init_xpm_files(t_cub3d *cub3d);
void	b_free_xpm_files(t_cub3d *cub3d);
void	b_init_colors(t_cub3d *cub3d);
void	b_free_colors(t_cub3d *cub3d);
void	b_init_map(t_cub3d *cub3d);
void	b_free_map(t_cub3d *cub3d);
void	b_validate_argument(t_cub3d *cub3d);
void	b_validate_config_is_non_empty(t_cub3d *cub3d);
void	b_set_config_line_count(t_cub3d *cub3d);
void	b_set_config_text(t_cub3d *cub3d);
void	b_set_elements_count(t_cub3d *cub3d);
void	b_validate_elements(t_cub3d *cub3d);
void	b_validate_xpm_files(t_cub3d *cub3d, char *line);
void	b_validate_floor_color(t_cub3d *cub3d, char *line);
void	b_validate_ceiling_color(t_cub3d *cub3d, char *line);
void	b_set_map_text(t_cub3d *cub3d);
char	**b_create_map_same_row_len(t_cub3d *cub3d);
void	b_check_map_empty_line(t_cub3d *cub3d);
void	b_validate_map_characters(t_cub3d *cub3d);
void	b_validate_map_walls(t_cub3d *cub3d);
void	b_validate_map_spaces(t_cub3d *cub3d);
void	b_validate_map(t_cub3d *cub3d);
char	*b_get_next_line(t_cub3d *cub3d, int fd);
int		b_is_empty_line(char *line);

void	b_init_game(t_cub3d *cub3d);
void	b_free_game(t_cub3d *cub3d);
void	b_init_mlx(t_cub3d *cub3d);
void	b_free_mlx(t_cub3d *cub3d);
void	b_init_screen(t_cub3d *cub3d);
void	b_free_screen(t_cub3d *cub3d);
void	b_init_north_mlx_image(t_cub3d *cub3d);
void	b_init_south_mlx_image(t_cub3d *cub3d);
void	b_init_west_mlx_image(t_cub3d *cub3d);
void	b_init_east_mlx_image(t_cub3d *cub3d);
void	b_init_ceiling_rgb(t_cub3d *cub3d);
void	b_init_floor_rgb(t_cub3d *cub3d);
void	b_free_xpm_images(t_cub3d *cub3d);
void	b_init_player(t_cub3d *cub3d);
void	b_free_player(t_cub3d *cub3d);

void	b_ray_properties(t_ray *ray, t_player *player, int x);
void	b_ray_draw_until_hit_wall(t_ray *ray, t_map *map);
void	b_ray_wall_properties(t_ray *ray, t_player *player);
void	b_ray_texture_properties(t_ray *ray);
void	b_ray_fill_screen(t_ray *ray, t_game *game, t_map *map, int x);
void	b_raycasting(t_cub3d *cub3d);

void	b_player_move_up(t_map *map, t_player *player);
void	b_player_move_down(t_map *map, t_player *player);
void	b_player_move_left(t_map *map, t_player *player);
void	b_player_move_right(t_map *map, t_player *player);
void	b_player_turn_left(t_player *player);
void	b_player_turn_right(t_player *player);
void	b_cursor_left(t_player *player);
void	b_cursor_right(t_player *player);

size_t	b_get_image_color(t_mlx_image *image, int x, int y);
void	b_put_pixel_to_mlx_image(t_mlx_image *image, int x, int y, int color);
int		b_destroy_handler(t_cub3d *cub3d);
int		b_keydown_handler(int key, t_cub3d *cub3d);
int		b_keyup_handler(int key, t_cub3d *cub3d);
int		b_loop_handler(t_cub3d *cub3d);
int		b_mouse_handler(int x, int y, t_cub3d *cub3d);

t_cub3d	*b_init_cub3d(int argument_count, char *filename);
void	b_free_cub3d(t_cub3d *cub3d);
void	b_print_error(t_cub3d *cub3d, char *message);

void	b_init_door0_image(t_cub3d *cub3d);
void	b_init_door1_image(t_cub3d *cub3d);
void	b_init_door2_image(t_cub3d *cub3d);
void	b_init_door3_image(t_cub3d *cub3d);
void	b_free_door_images(t_cub3d *cub3d);

#endif