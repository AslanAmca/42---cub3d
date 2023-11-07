/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rgb_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:36:51 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/07 21:36:58 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void init_ceiling_rgb(t_cub3d *cub3d)
{
	int red;
	int green;
	int blue;

	red = cub3d->config->ceiling_color->red;
	green = cub3d->config->ceiling_color->green;
	blue = cub3d->config->ceiling_color->blue;
	cub3d->game->ceiling_rgb = (red << 16 | green << 8 | blue);
}

void init_floor_rgb(t_cub3d *cub3d)
{
	int red;
	int green;
	int blue;

	red = cub3d->config->floor_color->red;
	green = cub3d->config->floor_color->green;
	blue = cub3d->config->floor_color->blue;
	cub3d->game->floor_rgb = (red << 16 | green << 8 | blue);
}