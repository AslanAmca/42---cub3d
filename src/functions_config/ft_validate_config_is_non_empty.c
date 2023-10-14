/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_config_is_non_empty.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:29:29 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/14 18:29:41 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void ft_validate_config_is_non_empty(char *filename)
{
	char character;
	int readed_byte;
	int fd;

	character = '\0';
	readed_byte = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("An error occurred while opening the map file.\n");
		exit(EXIT_FAILURE);
	}
	readed_byte = read(fd, &character, 1);
	if (readed_byte == -1)
	{
		printf("An error occurred while reading the map file.\n");
		exit(EXIT_FAILURE);
	}
	if (readed_byte == 0)
	{
		printf("Map file must not be empty.\n");
		exit(EXIT_FAILURE);
	}
	close(fd);
}
