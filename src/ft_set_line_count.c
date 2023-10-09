/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_non_empty_line_count.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:46:14 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/09 12:56:47 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_clear_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		line[i] = '\0';
		i++;
	}
}

static int	ft_is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

static void	ft_handle_line(t_data *data, char *line, int readed_byte, int *i)
{
	if (line[*i] == '\n' || readed_byte == 0)
	{
		line[*i + 1] = '\0';
		if (!ft_is_empty_line(line))
			(data->line_count)++;
		ft_clear_line(line);
		*i = -1;
	}
}

void	ft_set_line_count(t_data *data)
{
	char	line[1024];
	char	character;
	int		readed_byte;
	int		i;
	int		fd;

	character = '\0';
	readed_byte = 1;
	i = 0;
	fd = open(data->map_filename, O_RDONLY);
	if (fd == -1)
		ft_print_error(data, "An error occurred while opening the map file.");
	while (readed_byte > 0)
	{
		readed_byte = read(fd, &character, 1);
		if (readed_byte == -1)
			ft_print_error(data, "An error occurred while reading the map file.");
		line[i] = character;
		ft_handle_line(data, line, readed_byte, &i);
		i++;
	}
	close(fd);
}
