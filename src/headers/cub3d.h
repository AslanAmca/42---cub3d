/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:40:21 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/18 21:05:12 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "structs.h"
#include "libft.h"
#include "game.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

// utilities
char *get_next_line(t_data *data, int fd);
int is_empty_line(char *line);
void print_error(t_data *data, char *message);
void clear_double_pointer(char **pointer);

// init_and_clears
void init_colors(t_data *data);
void clear_colors(t_data *data);
void init_config(t_data *data);
void clear_config(t_data *data);
t_data *init_data(void);
void clear_data(t_data *data);
void init_map(t_data *data);
void clear_map(t_data *data);
void init_player(t_data *data);
void clear_player(t_data *data);
void init_textures(t_data *data);
void clear_textures(t_data *data);

// config
void validate_argument(int argument_count, char *filename);
void validate_config_is_non_empty(char *filename);
void set_config_line_count(t_data *data, char *filename);
void set_config_text(t_data *data, char *filename);

// elements
void set_elements_count(t_data *data);
void validate_elements(t_data *data);
void validate_textures(t_data *data, char *line);
void validate_floor_color(t_data *data, char *line);
void validate_ceiling_color(t_data *data, char *line);

// map
void set_map_text(t_data *data);
char **create_map_same_row_len(t_data *data);
void check_map_empty_line(t_data *data, char *filename);
void validate_map_characters(t_data *data);
void validate_map_walls(t_data *data);
void validate_map_spaces(t_data *data);
void validate_map(t_data *data, char *filename);

#endif
