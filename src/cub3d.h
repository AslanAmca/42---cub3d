/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:40:21 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/11 16:23:48 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_config
{
	char *filename;
	char **lines;
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
} t_texture;

typedef struct s_color
{
	int red;
	int green;
	int blue;
} t_color;

typedef struct s_data
{
	t_config *config;
	t_texture *texture;
	t_color *floor_color;
	t_color *ceiling_color;

	int map_starting_line;
} t_data;

// utilities
char *ft_strchr(char *s, int c);
int ft_strcmp(char *s1, char *s2);
char *ft_strdup(char *s);
int ft_strlcpy(char *dest, char *src, int n);
char *ft_strncpy(char *dest, char *src, int n);
int ft_strlen(char *string);
int ft_strncmp(char *s1, char *s2, int n);
char *ft_strtrim(char *s1, char *set);
char *ft_substr(char *s, int start, int len);
char **ft_split(char *string, char delimiter);

// main
void ft_init_data(t_data *data, char *config_filename);

// config file
void ft_validate_textures(t_data *data, char *line);
void ft_validate_colors(t_data *data, char *line);
void ft_validate_config_elements(t_data *data);

// other
void ft_print_error(t_data *data, char *message);
void ft_clear_data(t_data *data);
void ft_set_line_count(t_data *data);
int ft_is_empty_line(char *line);

#endif
