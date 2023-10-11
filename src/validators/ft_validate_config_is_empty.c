/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_config_is_empty.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:19:26 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/11 20:19:42 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void ft_validate_config_is_empty(t_data *data)
{
	char character;
	int readed_byte;
	int fd;

	character = '\0';
	readed_byte = 0;
	fd = open(data->config->filename, O_RDONLY);
	if (fd == -1)
		ft_print_error(data, "An error occurred while opening the map file.");
	readed_byte = read(fd, &character, 1);
	if (readed_byte == -1)
		ft_print_error(data, "An error occurred while reading the map file.");
	if (readed_byte == 0)
		ft_print_error(data, "Map file must not be empty.");
	close(fd);
}
