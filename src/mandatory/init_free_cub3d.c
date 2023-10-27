/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_cub3d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 23:24:22 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/27 18:39:25 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_cub3d *init_cub3d(int argument_count, char *filename)
{
	t_cub3d *cub3d;

	cub3d = malloc(sizeof(t_cub3d));
	if (cub3d == NULL)
		print_error(cub3d, "cub3d malloc error.");
	init_config(cub3d, argument_count, filename);
	init_xpm_files(cub3d);
	init_colors(cub3d);
	init_map(cub3d);
	cub3d->game = NULL;
	return (cub3d);
}

void free_cub3d(t_cub3d *cub3d)
{
	if (cub3d == NULL)
		return;
	free_config(cub3d);
	free_game(cub3d);
	free(cub3d);
}