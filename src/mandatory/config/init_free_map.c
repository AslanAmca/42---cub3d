/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_clear_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:09:13 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/16 23:48:20 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void init_map(t_cub3d *cub3d)
{
	cub3d->config->map = malloc(sizeof(t_map));
	if (cub3d->config->map == NULL)
		print_error(cub3d, "map malloc error.");
	cub3d->config->map->text = NULL;
	cub3d->config->map->starting_line = 0;
	cub3d->config->map->row_count = 0;
	cub3d->config->map->col_count = 0;
}

void free_map(t_cub3d *cub3d)
{
	if (cub3d->config->map == NULL)
		return;
	free_double_pointer(cub3d->config->map->text);
	free(cub3d->config->map);
}
