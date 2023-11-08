/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_init_free_config.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:20:50 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/09 01:11:10 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_cub3d.h"

void	b_init_config(t_cub3d *cub3d, int argument_count, char *filename)
{
	cub3d->config = malloc(sizeof(t_config));
	if (cub3d->config == NULL)
		b_print_error(cub3d, "config malloc error.");
	cub3d->config->argument_count = argument_count;
	cub3d->config->filename = filename;
	cub3d->config->text = NULL;
	cub3d->config->total_line_count = 0;
	cub3d->config->full_line_count = 0;
	cub3d->config->empty_line_count = 0;
	cub3d->config->xpm_files = NULL;
	cub3d->config->floor_color = NULL;
	cub3d->config->ceiling_color = NULL;
	cub3d->config->map = NULL;
}

void	b_free_config(t_cub3d *cub3d)
{
	if (cub3d->config == NULL)
		return ;
	b_free_map(cub3d);
	b_free_colors(cub3d);
	b_free_xpm_files(cub3d);
	free_double_pointer(cub3d->config->text);
	free(cub3d->config);
}
