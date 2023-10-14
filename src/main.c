/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:38:43 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/14 12:26:23 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_validate_file_is_non_empty(t_data *data)
{
	char character;
	int readed_byte;
	int fd;

	character = '\0';
	readed_byte = 0;
	fd = open(data->config->filename, O_RDONLY);
	if (fd == -1)
		ft_print_error(data, "An error occurred while opening the map file.");
	readed_byte = read(fd, &character, 1);
	if (readed_byte == -1)
		ft_print_error(data, "An error occurred while reading the map file.");
	if (readed_byte == 0)
		ft_print_error(data, "Map file must not be empty.");
	close(fd);
}

void ft_validate_argument(t_data *data, int argument_count)
{
	if (argument_count == 1)
		ft_print_error(data, "Map name not entered. You must enter the map name for the program to work.");
	if (argument_count > 2)
		ft_print_error(data, "Only the map name should be entered as an argument.");
	if (data->config->filename == NULL || *data->config->filename == '\0')
		ft_print_error(data, "Map name cannot be null or empty.");
	if (ft_strcmp(data->config->filename + ft_strlen(data->config->filename) - 4, ".cub") != 0)
		ft_print_error(data, "Map name does not end with the .cub extension.");
}

int main(int argc, char **argv)
{
	t_data *data;

	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		ft_print_error(data, "t_data is null.");
	ft_init_data(data, argv[1]);
	ft_validate_argument(data, argc);
	ft_validate_file_is_non_empty(data);

	ft_set_line_count(data);
	ft_set_lines(data);

	ft_set_elements_count(data);
	ft_validate_elements(data);

	// buna texture ve color sonrasında bakacağız.
	ft_check_map_empty_line(data);
	ft_validate_map_characters(data);


	// buraya kadar hata olmazsa ft_print_error üzerinden clear_data çalışmıyor.
	// dolayısıyla memory leak oluyor. şimdilik burada manuel clear yapalım.
	ft_clear_data(data);

	return 0;
}
