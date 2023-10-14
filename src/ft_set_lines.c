/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_lines.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:44:45 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/14 11:02:53 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_set_lines(t_data *data)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(data->config->filename, O_RDONLY);
	if (fd == -1)
		ft_print_error(data, "An error occurred while opening the map file.");
	data->config->lines = (char **)malloc(
			sizeof(char *) * (data->config->full_line_count + 1));
	if (data->config->lines == NULL)
		ft_print_error(data, "data->config->lines : malloc error");
	data->config->lines[data->config->full_line_count] = NULL;
	i = 0;
	while (i < data->config->full_line_count)
	{
		line = ft_get_next_line(data, fd);
		if (!ft_is_empty_line(line))
		{
			data->config->lines[i] = line;
			i++;
		}
		else
			free(line);
	}
	close(fd);
}
