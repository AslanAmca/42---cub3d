/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:19:44 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/24 00:37:19 by aaslan           ###   ########.fr       */
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

#include "../common/common.h"
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

typedef struct s_player
{
	// t_vectord pos;
	// t_vectord dir;
	// t_vectord plane;
	double angle;
} t_player;

typedef struct s_game
{
	void *mlx;
	void *mlx_window;
} t_game;

typedef struct s_cub3d
{
	t_config *config;
	t_game *game;
} t_cub3d;

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

// error
t_cub3d *init_cub3d(int argument_count, char *filename);
void free_cub3d(t_cub3d *cub3d);
void print_error(t_cub3d *cub3d, char *message);

#endif