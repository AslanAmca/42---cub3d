/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:38:43 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/09 16:40:12 by aaslan           ###   ########.fr       */
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
	ft_check_map_empty_line(data);

	// buraya kadar hata olmazsa data'yı freeleyen bir şey yok ona göre.
	free(data);

	return 0;
}
