/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_cub3d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 23:24:22 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/24 01:05:44 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_cub3d *init_cub3d(int argument_count, char *filename)
{
	t_cub3d *cub3d;

	cub3d = malloc(sizeof(t_cub3d));
	if (cub3d == NULL)
		print_error(cub3d, "cub3d malloc error.");
	cub3d->config = malloc(sizeof(t_config));
	if (cub3d->config == NULL)
		print_error(cub3d, "config malloc error.");
	cub3d->config->argument_count = argument_count;
	cub3d->config->filename = filename;
	cub3d->config->text = NULL;
	cub3d->config->total_line_count = 0;
	cub3d->config->full_line_count = 0;
	cub3d->config->empty_line_count = 0;
	init_xpm_files(cub3d);
	init_colors(cub3d);
	init_map(cub3d);
	return (cub3d);
}

void free_cub3d(t_cub3d *cub3d)
{
	if (cub3d == NULL)
		return;
	if (cub3d->config != NULL)
	{
		free_double_pointer(cub3d->config->text);
		free_xpm_files(cub3d);
		free_colors(cub3d);
		free_map(cub3d);
		free(cub3d->config);
	}
	free(cub3d);
}