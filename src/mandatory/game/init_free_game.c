/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 23:24:22 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/08 09:48:24 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void init_game(t_cub3d *cub3d)
{
	cub3d->game = malloc(sizeof(t_game));
	if (cub3d->game == NULL)
		print_error(cub3d, "game malloc error.");
	cub3d->game->mlx = NULL;
	cub3d->game->window = NULL;
	cub3d->game->screen = NULL;
	cub3d->game->player = NULL;
	cub3d->game->ceiling_rgb = 0;
	cub3d->game->floor_rgb = 0;
	init_mlx(cub3d);
	init_screen(cub3d);
	init_north_mlx_image(cub3d);
	init_south_mlx_image(cub3d);
	init_west_mlx_image(cub3d);
	init_east_mlx_image(cub3d);
	init_ceiling_rgb(cub3d);
	init_floor_rgb(cub3d);
	init_player(cub3d);
}

void free_game(t_cub3d *cub3d)
{
	if (cub3d->game == NULL)
		return;
	free_player(cub3d);
	free_xpm_images(cub3d);
	free_screen(cub3d);
	free_mlx(cub3d);
	free(cub3d->game);
}