/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:00:52 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/10 12:13:46 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void ft_clear_colors(t_data *data)
{
	if (data->floor_color != NULL)
	{
		free(data->floor_color);
		data->floor_color = NULL;
	}
	if (data->ceiling_color != NULL)
	{
		free(data->ceiling_color);
		data->ceiling_color = NULL;
	}
}

static void ft_clear_textures(t_data *data)
{
	if (data->texture == NULL)
		return;
	if (data->texture->north != NULL)
	{
		free(data->texture->north);
		data->texture->north = NULL;
	}
	if (data->texture->south != NULL)
	{
		free(data->texture->south);
		data->texture->south = NULL;
	}
	if (data->texture->west != NULL)
	{
		free(data->texture->west);
		data->texture->west = NULL;
	}
	if (data->texture->east != NULL)
	{
		free(data->texture->east);
		data->texture->east = NULL;
	}
	free(data->texture);
	data->texture = NULL;
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
		lines = NULL;
	}
	free(data->config);
	data->config = NULL;
}

void ft_clear_data(t_data *data)
{
	ft_clear_config(data);
	ft_clear_textures(data);
	ft_clear_colors(data);
	free(data);
	data = NULL;
}
