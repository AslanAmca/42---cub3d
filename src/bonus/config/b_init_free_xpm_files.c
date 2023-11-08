/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_clear_textures.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:08:29 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/14 20:26:55 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_cub3d.h"

void	b_init_xpm_files(t_cub3d *cub3d)
{
	cub3d->config->xpm_files = malloc(sizeof(t_xpm_files));
	if (cub3d->config->xpm_files == NULL)
		b_print_error(cub3d, "xpm_files malloc error.");
	cub3d->config->xpm_files->north = NULL;
	cub3d->config->xpm_files->south = NULL;
	cub3d->config->xpm_files->west = NULL;
	cub3d->config->xpm_files->east = NULL;
	cub3d->config->xpm_files->north_count = 0;
	cub3d->config->xpm_files->south_count = 0;
	cub3d->config->xpm_files->west_count = 0;
	cub3d->config->xpm_files->east_count = 0;
}

void	b_free_xpm_files(t_cub3d *cub3d)
{
	if (cub3d->config->xpm_files == NULL)
		return ;
	if (cub3d->config->xpm_files->north != NULL)
		free(cub3d->config->xpm_files->north);
	if (cub3d->config->xpm_files->south != NULL)
		free(cub3d->config->xpm_files->south);
	if (cub3d->config->xpm_files->west != NULL)
		free(cub3d->config->xpm_files->west);
	if (cub3d->config->xpm_files->east != NULL)
		free(cub3d->config->xpm_files->east);
	free(cub3d->config->xpm_files);
}
