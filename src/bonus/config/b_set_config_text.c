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

#include "../b_cub3d.h"

void	b_set_config_text(t_cub3d *cub3d)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(cub3d->config->filename, O_RDONLY);
	if (fd == -1)
		b_print_error(cub3d, "An error occurred while opening the map file.");
	cub3d->config->text = malloc(
			sizeof(char *) * (cub3d->config->full_line_count + 1));
	if (cub3d->config->text == NULL)
		b_print_error(cub3d, "config->text malloc error.");
	cub3d->config->text[cub3d->config->full_line_count] = NULL;
	i = 0;
	while (i < cub3d->config->full_line_count)
	{
		line = b_get_next_line(cub3d, fd);
		if (!b_is_empty_line(line))
		{
			cub3d->config->text[i] = line;
			i++;
		}
		else
			free(line);
	}
	close(fd);
}
