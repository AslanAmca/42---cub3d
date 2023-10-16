/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 00:02:57 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/16 23:48:50 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct s_config
{
	char **text;
	int total_line_count;
	int full_line_count;
	int empty_line_count;
} t_config;

typedef struct s_texture
{
	char *north;
	char *south;
	char *west;
	char *east;

	int north_count;
	int south_count;
	int west_count;
	int east_count;
} t_texture;

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

typedef struct s_player
{
	int count;
	int row;
	int col;
} t_player;

typedef struct s_data
{
	t_config *config;
	t_texture *texture;
	t_color *floor_color;
	t_color *ceiling_color;
	t_map *map;
	t_player *player;
} t_data;

#endif