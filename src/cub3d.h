/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:40:21 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/16 00:07:04 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

// libft
int ft_atoi(char *nptr);
int ft_is_digit(int c);
char **ft_split(char *string, char delimiter);
char *ft_strchr(char *s, int c);
int ft_strcmp(char *s1, char *s2);
char *ft_strdup(char *s);
int ft_strlcpy(char *dest, char *src, int n);
int ft_strlen(char *string);
int ft_strncmp(char *s1, char *s2, int n);
char *ft_strncpy(char *dest, char *src, int n);
char *ft_strtrim_start(char *s1, char *set);
char *ft_strtrim(char *s1, char *set);
char *ft_substr(char *s, int start, int len);

// utilities
char *ft_get_next_line(t_data *data, int fd);
int ft_is_empty_line(char *line);
void ft_print_error(t_data *data, char *message);
void ft_clear_double_pointer(char **pointer);

// init_and_clears
void ft_init_colors(t_data *data);
void ft_clear_colors(t_data *data);
void ft_init_config(t_data *data);
void ft_clear_config(t_data *data);
t_data *ft_init_data(void);
void ft_clear_data(t_data *data);
void ft_init_map(t_data *data);
void ft_clear_map(t_data *data);
void ft_init_player(t_data *data);
void ft_clear_player(t_data *data);
void ft_init_textures(t_data *data);
void ft_clear_textures(t_data *data);

// elements
void ft_set_elements_count(t_data *data);
void ft_validate_elements(t_data *data);
void ft_validate_textures(t_data *data, char *line);
void ft_validate_floor_color(t_data *data, char *line);
void ft_validate_ceiling_color(t_data *data, char *line);

// map
void ft_set_map_text(t_data *data);
void ft_check_map_empty_line(t_data *data, char *filename);
char **ft_create_map_temp_text(t_data *data);
void ft_validate_map_characters(t_data *data);
void ft_validate_map_walls(t_data *data);
void ft_validate_map_spaces(t_data *data);
void ft_validate_map(t_data *data, char *filename);

// config
void ft_validate_config_is_non_empty(char *filename);
void ft_set_config_line_count(t_data *data, char *filename);
void ft_set_config_text(t_data *data, char *filename);

#endif
