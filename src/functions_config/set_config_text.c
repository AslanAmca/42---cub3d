/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:44:45 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/14 13:09:17 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void set_config_text(t_data *data, char *filename)
{
	char *line;
	int fd;
	int i;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		print_error(data, "An error occurred while opening the map file.");
	data->config->text = malloc(
		sizeof(char *) * (data->config->full_line_count + 1));
	if (data->config->text == NULL)
		print_error(data, "data->config->text malloc error.");
	data->config->text[data->config->full_line_count] = NULL;
	i = 0;
	while (i < data->config->full_line_count)
	{
		line = get_next_line(data, fd);
		if (!is_empty_line(line))
		{
			data->config->text[i] = line;
			i++;
		}
		else
			free(line);
	}
	close(fd);
}
