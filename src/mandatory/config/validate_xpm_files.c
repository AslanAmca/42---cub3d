/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_xpm_files.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 01:00:30 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/24 01:02:16 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void validate_north_xpm(t_cub3d *cub3d, char *line)
{
	t_config *config;
	int fd;

	config = cub3d->config;
	fd = -1;
	if (ft_strncmp("NO", line, 2) == 0)
	{
		config->xpm_files->north = ft_strtrim(line + 2, " \t");
		if (config->xpm_files->north[0] == '\0')
			print_error(cub3d, "NO element can't be null.");
		if (ft_strcmp(config->xpm_files->north + ft_strlen(config->xpm_files->north) - 4, ".xpm") != 0)
			print_error(cub3d, "NO element must end with the .xpm extension.");
		fd = open(config->xpm_files->north, O_RDONLY);
		if (fd == -1)
			print_error(cub3d, "NO xpm file not found or can't be opened.");
		close(fd);
	}
}

static void validate_south_xpm(t_cub3d *cub3d, char *line)
{
	t_config *config;
	int fd;

	config = cub3d->config;
	fd = -1;
	if (ft_strncmp("SO", line, 2) == 0)
	{
		config->xpm_files->south = ft_strtrim(line + 2, " \t");
		if (config->xpm_files->south[0] == '\0')
			print_error(cub3d, "SO element cant' be empty.");
		if (ft_strcmp(config->xpm_files->south + ft_strlen(config->xpm_files->south) - 4, ".xpm") != 0)
			print_error(cub3d, "SO element must end with the .xpm extension.");
		fd = open(config->xpm_files->south, O_RDONLY);
		if (fd == -1)
			print_error(cub3d, "SO xpm file not found or can't be opened.");
		close(fd);
	}
}

static void validate_west_xpm(t_cub3d *cub3d, char *line)
{
	t_config *config;
	int fd;

	config = cub3d->config;
	fd = -1;
	if (ft_strncmp("WE", line, 2) == 0)
	{
		config->xpm_files->west = ft_strtrim(line + 2, " \t");
		if (config->xpm_files->west[0] == '\0')
			print_error(cub3d, "WE element cant' be empty.");
		if (ft_strcmp(config->xpm_files->west + ft_strlen(config->xpm_files->west) - 4, ".xpm") != 0)
			print_error(cub3d, "WE element must end with the .xpm extension.");
		fd = open(config->xpm_files->west, O_RDONLY);
		if (fd == -1)
			print_error(cub3d, "WE xpm file not found or can't be opened.");
		close(fd);
	}
}

static void validate_east_xpm(t_cub3d *cub3d, char *line)
{
	t_config *config;
	int fd;

	config = cub3d->config;
	fd = -1;
	if (ft_strncmp("EA", line, 2) == 0)
	{
		config->xpm_files->east = ft_strtrim(line + 2, " \t");
		if (config->xpm_files->east[0] == '\0')
			print_error(cub3d, "EA element cant' be empty.");
		if (ft_strcmp(config->xpm_files->east + ft_strlen(config->xpm_files->east) - 4, ".xpm") != 0)
			print_error(cub3d, "EA element must end with the .xpm extension.");
		fd = open(config->xpm_files->east, O_RDONLY);
		if (fd == -1)
			print_error(cub3d, "EA xpm file not found or can't be opened.");
		close(fd);
	}
}

void validate_xpm_files(t_cub3d *cub3d, char *line)
{
	validate_north_xpm(cub3d, line);
	validate_south_xpm(cub3d, line);
	validate_west_xpm(cub3d, line);
	validate_east_xpm(cub3d, line);
}
