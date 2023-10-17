/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_textures.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:26:26 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/12 12:42:13 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void validate_north_texture(t_data *data, char *line)
{
	int fd;

	fd = -1;
	if (ft_strncmp("NO", line, 2) == 0)
	{
		data->texture->north = ft_strtrim(line + 2, " \t");
		if (data->texture->north[0] == '\0')
			print_error(data, "NO element can't be null.");
		if (ft_strcmp(data->texture->north + ft_strlen(data->texture->north) - 4, ".xpm") != 0)
			print_error(data, "NO element must end with the .xpm extension.");
		fd = open(data->texture->north, O_RDONLY);
		if (fd == -1)
			print_error(data, "NO xpm file not found or can't be opened.");
		close(fd);
	}
}

static void validate_south_texture(t_data *data, char *line)
{
	int fd;

	fd = -1;
	if (ft_strncmp("SO", line, 2) == 0)
	{
		data->texture->south = ft_strtrim(line + 2, " \t");
		if (data->texture->south[0] == '\0')
			print_error(data, "SO element cant' be empty.");
		if (ft_strcmp(data->texture->south + ft_strlen(data->texture->south) - 4, ".xpm") != 0)
			print_error(data, "SO element must end with the .xpm extension.");
		fd = open(data->texture->south, O_RDONLY);
		if (fd == -1)
			print_error(data, "SO xpm file not found or can't be opened.");
		close(fd);
	}
}

static void validate_west_texture(t_data *data, char *line)
{
	int fd;

	fd = -1;
	if (ft_strncmp("WE", line, 2) == 0)
	{
		data->texture->west = ft_strtrim(line + 2, " \t");
		if (data->texture->west[0] == '\0')
			print_error(data, "WE element cant' be empty.");
		if (ft_strcmp(data->texture->west + ft_strlen(data->texture->west) - 4, ".xpm") != 0)
			print_error(data, "WE element must end with the .xpm extension.");
		fd = open(data->texture->west, O_RDONLY);
		if (fd == -1)
			print_error(data, "WE xpm file not found or can't be opened.");
		close(fd);
	}
}

static void validate_east_texture(t_data *data, char *line)
{
	int fd;

	fd = -1;
	if (ft_strncmp("EA", line, 2) == 0)
	{
		data->texture->east = ft_strtrim(line + 2, " \t");
		if (data->texture->east[0] == '\0')
			print_error(data, "EA element cant' be empty.");
		if (ft_strcmp(data->texture->east + ft_strlen(data->texture->east) - 4, ".xpm") != 0)
			print_error(data, "EA element must end with the .xpm extension.");
		fd = open(data->texture->east, O_RDONLY);
		if (fd == -1)
			print_error(data, "EA xpm file not found or can't be opened.");
		close(fd);
	}
}

void validate_textures(t_data *data, char *line)
{
	validate_north_texture(data, line);
	validate_south_texture(data, line);
	validate_west_texture(data, line);
	validate_east_texture(data, line);
}
