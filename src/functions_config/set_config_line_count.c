/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_config_line_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:46:14 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/14 16:57:38 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void clear_line(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		line[i] = '\0';
		i++;
	}
}

static void handle_line(t_data *data, char *line, int readed_byte, int *i)
{
	if (line[*i] == '\n' || readed_byte == 0)
	{
		data->config->total_line_count++;
		line[*i + 1] = '\0';
		if (!is_empty_line(line))
		{
			data->config->full_line_count++;
			if (data->config->full_line_count == 7)
				data->map->starting_line = data->config->total_line_count;
		}
		else
			data->config->empty_line_count++;
		clear_line(line);
		*i = -1;
	}
}

void set_config_line_count(t_data *data, char *filename)
{
	char line[1024];
	char character;
	int readed_byte;
	int i;
	int fd;

	character = '\0';
	readed_byte = 1;
	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		print_error(data, "An error occurred while opening the map file.");
	while (readed_byte > 0)
	{
		readed_byte = read(fd, &character, 1);
		if (readed_byte == -1)
			print_error(data,
						   "An error occurred while reading the map file.");
		line[i] = character;
		handle_line(data, line, readed_byte, &i);
		i++;
	}
	close(fd);

	// 4 texture, 2 color, en az 3 satırdan oluşan harita olacak.
	// dolayısıyla en az 9 satır olmalıdır.
	// 9 satırdan az varsa hiç uğraşmadan hata vermek mantıklı mı?
	if (data->config->full_line_count < 9)
		print_error(data, "There must be at least 9 text in the configuration file. \
(4 texture, 2 color, min 3 for map)");
}
