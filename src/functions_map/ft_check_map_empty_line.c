/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_empty_line.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:42:06 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/14 10:42:50 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void ft_check_map_empty_line(t_data *data)
{
	char *line;
	int i;
	int fd;

	fd = open(data->config->filename, O_RDONLY);
	if (fd == -1)
		ft_print_error(data, "An error occurred while opening the map file.");
	line = NULL;
	i = 1;
	while (i <= data->config->total_line_count)
	{
		line = ft_get_next_line(data, fd);
		if (ft_is_empty_line(line) && i > data->map_starting_line)
		{
			free(line);
			ft_print_error(data, "There can't be empty line within or after the map.");
		}
		free(line);
		i++;
	}
	close(fd);
}