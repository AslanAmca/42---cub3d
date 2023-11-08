/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_empty_line.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:42:06 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/14 18:32:03 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_cub3d.h"

void	b_check_map_empty_line(t_cub3d *cub3d)
{
	t_config	*config;
	char		*line;
	int			i;
	int			fd;

	config = cub3d->config;
	fd = open(config->filename, O_RDONLY);
	if (fd == -1)
		b_print_error(cub3d, "An error occurred while opening the map file.");
	line = NULL;
	i = 1;
	while (i <= config->total_line_count)
	{
		line = b_get_next_line(cub3d, fd);
		if (b_is_empty_line(line) && i > config->map->starting_line)
		{
			free(line);
			b_print_error(cub3d,
				"There can't be empty line within or after the map.");
		}
		free(line);
		i++;
	}
	close(fd);
}
