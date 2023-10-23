/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_argument.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:04:21 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/24 00:18:41 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void validate_argument(t_cub3d *cub3d)
{
	char *filename;

	filename = cub3d->config->filename;
	if (cub3d->config->argument_count == 1)
		print_error(cub3d, "Map name not entered. You must enter the map name for the program to work.");
	if (cub3d->config->argument_count > 2)
		print_error(cub3d, "Only the map name should be entered as an argument.");
	if (filename == NULL || *filename == '\0')
		print_error(cub3d, "Map name cannot be null or empty.");
	if (ft_strcmp(filename + ft_strlen(filename) - 4, ".cub") != 0)
		print_error(cub3d, "Map name does not end with the .cub extension.");
}
