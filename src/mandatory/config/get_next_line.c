/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:20:10 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/11 20:20:47 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*get_next_line(t_cub3d *cub3d, int fd)
{
	char	*line;
	char	character;
	int		readed_byte;
	int		i;

	line = malloc(1024);
	character = '\0';
	readed_byte = 1;
	i = 0;
	if (fd == -1)
		print_error(cub3d, "An error occurred while opening the map file.");
	while (1)
	{
		readed_byte = read(fd, &character, 1);
		if (readed_byte == -1)
			print_error(cub3d, "The map file could not be read.");
		line[i] = character;
		if (character == '\n' || readed_byte == 0)
		{
			line[i] = '\0';
			break ;
		}
		i++;
	}
	return (line);
}
