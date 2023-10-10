/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:05:16 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/10 12:00:18 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void ft_init_colors(t_data *data)
{
	data->floor_color = (t_color *)malloc(sizeof(t_color));
	if (data->floor_color == NULL)
		ft_print_error(data, "t_data->floor_color is null.");
	data->ceiling_color = (t_color *)malloc(sizeof(t_color));
	if (data->ceiling_color == NULL)
		ft_print_error(data, "t_data->ceiling_color is null.");
	data->floor_color->red = 0;
	data->floor_color->green = 0;
	data->floor_color->blue = 0;
	data->ceiling_color->red = 0;
	data->ceiling_color->green = 0;
	data->ceiling_color->blue = 0;
}

static void ft_init_textures(t_data *data)
{
	data->texture = (t_texture *)malloc(sizeof(t_texture));
	if (data->texture == NULL)
		ft_print_error(data, "t_data->texture is null.");
	data->texture->north = NULL;
	data->texture->south = NULL;
	data->texture->west = NULL;
	data->texture->east = NULL;
}

static void ft_init_config(t_data *data, char *config_filename)
{
	data->config = (t_config *)malloc(sizeof(t_config));
	if (data->config == NULL)
		ft_print_error(data, "t_data->config is null.");
	data->config->filename = config_filename;
	data->config->lines = NULL;
	data->config->total_line_count = 0;
	data->config->full_line_count = 0;
	data->config->empty_line_count = 0;
}

void ft_init_data(t_data *data, char *config_filename)
{
	ft_init_config(data, config_filename);
	ft_init_textures(data);
	ft_init_colors(data);
}