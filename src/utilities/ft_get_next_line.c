/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:20:10 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/11 20:20:47 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
