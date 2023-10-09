/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:40:21 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/09 15:34:12 by aaslan           ###   ########.fr       */
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

	char *config_filename;
	char **config_lines;
	int config_total_line_count;
	int config_full_line_count;
	int config_empty_line_count;

	int map_starting_line;

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

// diğerleri
void ft_print_error(t_data *data, char *message);
void ft_clear_data(t_data *data);
void ft_set_line_count(t_data *data);
int ft_is_empty_line(char *line);

#endif
