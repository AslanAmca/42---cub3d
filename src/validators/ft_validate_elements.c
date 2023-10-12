/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_elements.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:53:10 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/12 15:48:30 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void ft_check_unknown_element_type(t_data *data)
{
	char *line;
	int i;

	line = NULL;
	i = 0;
	while (i < 6)
	{
		line = data->config->lines[i];

		if (ft_strncmp("NO", line, 2) != 0 && ft_strncmp("SO", line, 2) != 0 && ft_strncmp("WE", line, 2) != 0 && ft_strncmp("EA", line, 2) != 0 && ft_strncmp("F", line, 1) != 0 && ft_strncmp("C", line, 1) != 0)
		{
			ft_print_error(data, "Only NO, SO, WE, EA, F and C element types can be in the first 6 filled lines.");
		}
		i++;
	}
}

static void ft_check_multiple_element_type(t_data *data)
{
	if (data->texture->north_count > 1)
		ft_print_error(data, "NO element type cannot be more than 1.");
	if (data->texture->south_count > 1)
		ft_print_error(data, "SO element type cannot be more than 1.");
	if (data->texture->west_count > 1)
		ft_print_error(data, "WE element type cannot be more than 1.");
	if (data->texture->east_count > 1)
		ft_print_error(data, "EA element type cannot be more than 1.");
	if (data->floor_color->count > 1)
		ft_print_error(data, "F element type cannot be more than 1.");
	if (data->ceiling_color->count > 1)
		ft_print_error(data, "C element type cannot be more than 1.");
}

static void ft_validate_different_texture(t_data *data)
{
	if (ft_strcmp(data->texture->north, data->texture->south) == 0 ||
		ft_strcmp(data->texture->north, data->texture->west) == 0 ||
		ft_strcmp(data->texture->north, data->texture->east) == 0)
	{
		ft_print_error(data, "NO texture can't be used for other textures.");
	}
	if (ft_strcmp(data->texture->south, data->texture->north) == 0 ||
		ft_strcmp(data->texture->south, data->texture->west) == 0 ||
		ft_strcmp(data->texture->south, data->texture->east) == 0)
	{
		ft_print_error(data, "SO texture can't be used for other textures.");
	}
	if (ft_strcmp(data->texture->west, data->texture->north) == 0 ||
		ft_strcmp(data->texture->west, data->texture->south) == 0 ||
		ft_strcmp(data->texture->west, data->texture->east) == 0)
	{
		ft_print_error(data, "WE texture can't be used for other textures.");
	}
	if (ft_strcmp(data->texture->east, data->texture->south) == 0 ||
		ft_strcmp(data->texture->east, data->texture->north) == 0 ||
		ft_strcmp(data->texture->east, data->texture->west) == 0)
	{
		ft_print_error(data, "EA texture can't be used for other textures.");
	}
}

static void ft_validate_different_color(t_data *data)
{
	if (data->floor_color->red == data->ceiling_color->red &&
		data->floor_color->green == data->ceiling_color->green &&
		data->floor_color->blue == data->ceiling_color->blue)
	{
		ft_print_error(data, "Floor and ceiling color should not be the same.");
	}
}

void ft_validate_elements(t_data *data)
{
	char *line;
	int i;

	ft_check_unknown_element_type(data);
	ft_check_multiple_element_type(data);
	line = NULL;
	i = 0;
	while (i < 6)
	{
		line = data->config->lines[i];
		ft_validate_textures(data, line);
		ft_validate_floor_color(data, line);
		ft_validate_ceiling_color(data, line);
		i++;
	}
	ft_validate_different_texture(data);
	ft_validate_different_color(data);
}
