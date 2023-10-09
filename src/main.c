/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:38:43 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/09 21:38:30 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void ft_init_data(t_data *data, int argument_count, char *config_filename)
{
	data->argument_count = argument_count;

	data->config_filename = config_filename;
	data->config_total_line_count = 0;
	data->config_full_line_count = 0;
	data->config_empty_line_count = 0;
	data->config_lines = NULL;

	data->north_texture = NULL;
	data->north_texture = NULL;
	data->south_texture = NULL;
	data->west_texture = NULL;
	data->east_texture = NULL;
	data->floor_color = -10;
	data->ceiling_color = -10;
}

void ft_validate_argument(t_data *data)
{
	if (data->argument_count == 1)
		ft_print_error(data, "Map name not entered. You must enter the map name for the program to work.");
	if (data->argument_count > 2)
		ft_print_error(data, "Only the map name should be entered as an argument.");
	if (data->config_filename == NULL || *data->config_filename == '\0')
		ft_print_error(data, "Map name cannot be null or empty.");
	if (ft_strcmp(data->config_filename + ft_strlen(data->config_filename) - 4, ".cub") != 0)
		ft_print_error(data, "Map name does not end with the .cub extension.");
}

void ft_validate_config_is_empty(t_data *data)
{
	char character;
	int readed_byte;
	int fd;

	character = '\0';
	readed_byte = 0;
	fd = open(data->config_filename, O_RDONLY);
	if (fd == -1)
		ft_print_error(data, "An error occurred while opening the map file.");
	readed_byte = read(fd, &character, 1);
	if (readed_byte == -1)
		ft_print_error(data, "An error occurred while reading the map file.");
	if (readed_byte == 0)
		ft_print_error(data, "Map file must not be empty.");
	close(fd);
}

char *ft_get_next_line(t_data *data, int fd)
{
	char *line = malloc(1024);
	char character;
	int readed_byte;
	int i;

	character = '\0';
	readed_byte = 1;
	i = 0;
	if (fd == -1)
		ft_print_error(data, "An error occurred while opening the map file.");
	while (1)
	{
		readed_byte = read(fd, &character, 1);
		if (readed_byte == -1)
			ft_print_error(data,
						   "An error occurred while reading the map file.");
		line[i] = character;
		if (character == '\n' || readed_byte == 0)
		{
			line[i] = '\0';
			break;
		}
		i++;
	}
	return (line);
}

void ft_check_map_empty_line(t_data *data)
{
	char *line;
	int i;
	int fd;

	fd = open(data->config_filename, O_RDONLY);
	if (fd == -1)
		ft_print_error(data, "An error occurred while opening the map file.");
	line = NULL;
	i = 1;
	while (i <= data->config_total_line_count)
	{
		line = ft_get_next_line(data, fd);
		if (ft_is_empty_line(line) && i > data->map_starting_line)
		{
			free(line);
			line = NULL;
			ft_print_error(data, "There can't be empty line within or after the map.");
		}
		free(line);
		line = NULL;
		i++;
	}
	close(fd);
}

void ft_set_lines(t_data *data)
{
	int fd = open(data->config_filename, O_RDONLY);
	if (fd == -1)
		ft_print_error(data, "An error occurred while opening the map file.");

	data->config_lines = (char **)malloc(sizeof(char *) * (data->config_full_line_count + 1));
	if (data->config_lines == NULL)
		ft_print_error(data, "malloc error");
	data->config_lines[data->config_full_line_count] = NULL;

	int i = 0;
	char *line = NULL;
	while (i < data->config_full_line_count)
	{
		line = ft_get_next_line(data, fd);

		if (!ft_is_empty_line(line))
		{
			data->config_lines[i] = line;
			i++;
		}
		else
		{
			free(line);
			line = NULL;
		}
	}
	close(fd);
}


static void ft_validate_north_texture(t_data *data, char *line, int space)
{
	if (space == 1 && ft_strncmp("NO ", line, 3) == 0)
	{
		if (data->north_texture != NULL)
			ft_print_error(data, "There can't be more than one NO element.");
		data->north_texture = ft_strtrim(line + 3, " \t");
		if (data->north_texture[0] == '\0')
			ft_print_error(data, "North Texture cant' be empty.");
		if (ft_strcmp(data->north_texture + ft_strlen(data->north_texture) - 4, ".xpm") != 0)
			ft_print_error(data, "North Texture must end with the .xpm extension.");
	}
	if (space == 0 && ft_strncmp("NO", line, 2) == 0 && line[2] != ' ')
	{
		ft_print_error(data, "The NO identifier must be followed by a space character.");
	}

}

static void ft_validate_south_texture(t_data *data, char *line, int space)
{
	if (space == 1 && ft_strncmp("SO ", line, 3) == 0)
	{
		if (data->south_texture != NULL)
			ft_print_error(data, "There can't be more than one SO element.");
		data->south_texture = ft_strtrim(line + 3, " \t");
		if (data->south_texture[0] == '\0')
			ft_print_error(data, "South Texture cant' be empty.");
		if (ft_strcmp(data->south_texture + ft_strlen(data->south_texture) - 4, ".xpm") != 0)
			ft_print_error(data, "South Texture must end with the .xpm extension.");
	}
	if (space == 0 && ft_strncmp("SO", line, 2) == 0 && line[2] != ' ')
	{
		ft_print_error(data, "The SO identifier must be followed by a space character.");
	}
}

static void ft_validate_west_texture(t_data *data, char *line, int space)
{
	if (space == 1 && ft_strncmp("WE ", line, 3) == 0)
	{
		if (data->west_texture != NULL)
			ft_print_error(data, "There can't be more than one WE element.");
		data->west_texture = ft_strtrim(line + 3, " \t");
		if (data->west_texture[0] == '\0')
			ft_print_error(data, "West Texture cant' be empty.");
		if (ft_strcmp(data->west_texture + ft_strlen(data->west_texture) - 4, ".xpm") != 0)
			ft_print_error(data, "West Texture must end with the .xpm extension.");
	}
	if (space == 0 && ft_strncmp("WE", line, 2) == 0 && line[2] != ' ')
	{
		ft_print_error(data, "The WE identifier must be followed by a space character.");
	}
}

static void ft_validate_east_texture(t_data *data, char *line, int space)
{
	if (space == 1 && ft_strncmp("EA ", line, 3) == 0)
	{
		if (data->east_texture != NULL)
			ft_print_error(data, "There can't be more than one EA element.");
		data->east_texture = ft_strtrim(line + 3, " \t");
		if (data->east_texture[0] == '\0')
			ft_print_error(data, "East Texture cant' be empty.");
		if (ft_strcmp(data->east_texture + ft_strlen(data->east_texture) - 4, ".xpm") != 0)
			ft_print_error(data, "East Texture must end with the .xpm extension.");
	}
	if (space == 0 && ft_strncmp("EA", line, 2) == 0 && line[2] != ' ')
	{
		ft_print_error(data, "The EA identifier must be followed by a space character.");
	}
}

void ft_validate_textures(t_data *data)
{
	char *line;
	int i;

	line = NULL;
	i = 0;
	while (i < 6)
	{
		line = data->config_lines[i];
		ft_validate_north_texture(data, line, 1);
		ft_validate_south_texture(data, line, 1);
		ft_validate_west_texture(data, line, 1);
		ft_validate_east_texture(data, line, 1);
		i++;
	}
	line = NULL;
	i = 0;
	while (i < 6)
	{
		line = data->config_lines[i];
		ft_validate_north_texture(data, line, 0);
		ft_validate_south_texture(data, line, 0);
		ft_validate_west_texture(data, line, 0);
		ft_validate_east_texture(data, line, 0);
		i++;
	}
}



// void ft_validate_colors(t_data *data)
// {
// 	char *line;
// 	int i;

// 	line = NULL;
// 	i = 0;
// 	while (i < 6)
// 	{
// 		line = data->config_lines[i];
// 		ft_validate_north_texture(data, line, 1);
// 		ft_validate_south_texture(data, line, 1);
// 		ft_validate_west_texture(data, line, 1);
// 		ft_validate_east_texture(data, line, 1);
// 		i++;
// 	}
// }

int main(int argc, char **argv)
{
	t_data *data;

	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		ft_print_error(data, "t_data is null.");
	ft_init_data(data, argc, argv[1]);
	ft_validate_argument(data);
	ft_validate_config_is_empty(data);
	ft_set_line_count(data);
	ft_set_lines(data);
	ft_validate_textures(data);

	// buna texture ve color sonrasında bakacağız.
	// ft_check_map_empty_line(data);


	// buraya kadar hata olmazsa ft_print_error üzerinden clear_data çalışmıyor.
	// dolayısıyla memory leak oluyor. şimdilik burada manuel clear yapalım.
	ft_clear_data(data);

	return 0;
}
