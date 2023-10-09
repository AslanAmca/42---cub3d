/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:40:21 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/09 12:57:58 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

// veri yapıları
typedef struct s_data
{
	int argument_count;
	char *map_filename;

	int line_count;

	char *map_string;
	char **map_lines;

	char *north_texture;
	char *south_texture;
	char *west_texture;
	char *east_texture;
	int floor_color;
	int ceiling_color;
} t_data;

// utilities
int ft_strlen(char *string);
int ft_strcmp(const char *s1, const char *s2);
// char *get_next_line(t_data *data);

// get_next_line
int ft_has_line_feed(char *line);
char *ft_create_empty_string(int size);
char *ft_add_buffer_to_string(char *string, char *buffer);
char *ft_fill_string(char *string, int fd);
char *ft_get_first_line(char *string);
char *ft_delete_first_line(char *string);
char *get_next_line(int fd);

// diğerleri
void ft_print_error(t_data *data, char *message);
void ft_clear_data(t_data *data);
void ft_set_line_count(t_data *data);

#endif
