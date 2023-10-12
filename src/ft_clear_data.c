/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:00:52 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/12 15:08:41 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void ft_clear_colors(t_data *data)
{
	if (data->floor_color != NULL)
	{
		if (data->floor_color->string != NULL)
			free(data->floor_color->string);
		if (data->floor_color->red_string != NULL)
			free(data->floor_color->red_string);
		if (data->floor_color->green_string != NULL)
			free(data->floor_color->green_string);
		if (data->floor_color->blue_string != NULL)
			free(data->floor_color->blue_string);
		free(data->floor_color);
	}
	if (data->ceiling_color != NULL)
	{
		if (data->ceiling_color->string != NULL)
			free(data->ceiling_color->string);
		if (data->ceiling_color->red_string != NULL)
			free(data->ceiling_color->red_string);
		if (data->ceiling_color->green_string != NULL)
			free(data->ceiling_color->green_string);
		if (data->ceiling_color->blue_string != NULL)
			free(data->ceiling_color->blue_string);
		free(data->ceiling_color);
	}
}

static void ft_clear_textures(t_data *data)
{
	if (data->texture == NULL)
		return;
	if (data->texture->north != NULL)
		free(data->texture->north);
	if (data->texture->south != NULL)
		free(data->texture->south);
	if (data->texture->west != NULL)
		free(data->texture->west);
	if (data->texture->east != NULL)
		free(data->texture->east);
	free(data->texture);
}

static void ft_clear_config(t_data *data)
{
	char **lines;
	int i;

	if (data->config == NULL)
		return;
	lines = data->config->lines;
	i = 0;
	if (lines != NULL)
	{
		while (lines[i] != NULL)
		{
			free(lines[i]);
			i++;
		}
		free(lines);
	}
	free(data->config);
}

void ft_clear_data(t_data *data)
{
	ft_clear_config(data);
	ft_clear_textures(data);
	ft_clear_colors(data);
	free(data);
}
