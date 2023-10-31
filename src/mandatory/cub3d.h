/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:19:44 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/31 06:32:13 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#ifdef __linux__
#define KEY_ESC 65307
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_E 101
#define KEY_LEFT 65361
#define KEY_RIGHT 65363
#define KEY_DOWN 65364
#define KEY_UP 65362
#endif

#ifdef __APPLE__
#define KEY_ESC 53
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_E 14
#define KEY_LEFT 123
#define KEY_RIGHT 124
#define KEY_DOWN 125
#define KEY_UP 126
#endif

#define ON_KEYDOWN 2
#define ON_KEYUP 3
#define ON_MOUSEDOWN 4
#define ON_MOUSEUP 5
#define ON_MOUSEMOVE 6
#define ON_EXPOSE 12
#define ON_DESTROY 17

#ifdef __linux__
#include "../../mlx_linux/mlx.h"
#endif

#ifdef __APPLE__
#include "../../mlx/mlx.h"
#endif

#include "../utilities/utilities.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_xpm_files
{
	char *north;
	char *south;
	char *west;
	char *east;

	int north_count;
	int south_count;
	int west_count;
	int east_count;
} t_xpm_files;

typedef struct s_color
{
	char *red_string;
	char *green_string;
	char *blue_string;
	char *string;
	int count;
	int red;
	int green;
	int blue;
} t_color;

typedef struct s_map
{
	char **text;
	int starting_line;
	int row_count;
	int col_count;

	int player_count;
	int player_row;
	int player_col;
} t_map;

typedef struct s_config
{
	int argument_count;
	char *filename;

	char **text;
	int total_line_count;
	int full_line_count;
	int empty_line_count;

	t_xpm_files *xpm_files;
	t_color *floor_color;
	t_color *ceiling_color;
	t_map *map;
} t_config;


// game
typedef struct s_vector_double
{
	double x;
	double y;
} t_vector_double;

typedef struct s_vector_int
{
	int x;
	int y;
} t_vector_int;

typedef struct s_player
{
	// açı
	double angle;

	// Oyuncunun konumunu temsil eder. Bu, oyuncunun harita üzerindeki nerede başlayacağını belirtir.
	t_vector_double position;

	// Oyuncunun bakış yönünü temsil eder. Bu, oyuncunun hangi yönde bakacağını belirtir.
	// x ve y ekseni 1 veya -1 olur ve yönü temsil eder. 0 ise o eksen ile ilgili bir durum yok demektir.
	// Örneğin x -1 ise sol tarafa, 1 ise sağ tarafa bakıyor demektir.
	t_vector_double direction;

	// Kamera düzlemini temsil eder.
	// Kamera düzlemi, ekranın 2D yüzeyini temsil eder ve oyuncunun bakış yönüne dik olmalıdır.
	// Bu vektörün uzunluğu, görüş açısını (FOV) belirler.
	t_vector_double camera_plane;
} t_player;

// mlx için lazım olan image ve özellikleri
typedef struct s_mlx_image
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int size_line;
	int endian;
} t_mlx_image;

typedef struct s_game
{
	void *mlx;
	void *mlx_window;
	t_mlx_image *mlx_image;

	t_player *player;
} t_game;

typedef struct s_cub3d
{
	t_config *config;
	t_game *game;
} t_cub3d;

// config
void init_config(t_cub3d *cub3d, int argument_count, char *filename);
void free_config(t_cub3d *cub3d);
void init_xpm_files(t_cub3d *cub3d);
void free_xpm_files(t_cub3d *cub3d);
void init_colors(t_cub3d *cub3d);
void free_colors(t_cub3d *cub3d);
void init_map(t_cub3d *cub3d);
void free_map(t_cub3d *cub3d);
void validate_argument(t_cub3d *cub3d);
void validate_config_is_non_empty(t_cub3d *cub3d);
void set_config_line_count(t_cub3d *cub3d);
void set_config_text(t_cub3d *cub3d);
void set_elements_count(t_cub3d *cub3d);
void validate_elements(t_cub3d *cub3d);
void validate_xpm_files(t_cub3d *cub3d, char *line);
void validate_floor_color(t_cub3d *cub3d, char *line);
void validate_ceiling_color(t_cub3d *cub3d, char *line);
void set_map_text(t_cub3d *cub3d);
char **create_map_same_row_len(t_cub3d *cub3d);
void check_map_empty_line(t_cub3d *cub3d);
void validate_map_characters(t_cub3d *cub3d);
void validate_map_walls(t_cub3d *cub3d);
void validate_map_spaces(t_cub3d *cub3d);
void validate_map(t_cub3d *cub3d);
char *get_next_line(t_cub3d *cub3d, int fd);
int is_empty_line(char *line);

// game
void init_game(t_cub3d *cub3d);
void free_game(t_cub3d *cub3d);
void init_mlx(t_cub3d *cub3d);
void free_mlx(t_cub3d *cub3d);
void init_mlx_image(t_cub3d *cub3d);
void free_mlx_image(t_cub3d *cub3d);
void init_player(t_cub3d *cub3d);
void free_player(t_cub3d *cub3d);

// cub3d
t_cub3d *init_cub3d(int argument_count, char *filename);
void free_cub3d(t_cub3d *cub3d);
void print_error(t_cub3d *cub3d, char *message);

#endif