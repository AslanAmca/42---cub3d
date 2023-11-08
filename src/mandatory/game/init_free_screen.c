/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_screen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:24:10 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/08 09:48:24 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void init_screen(t_cub3d *cub3d)
{
	t_game *game;

	game = cub3d->game;

	game->screen = malloc(sizeof(t_mlx_image));
	if (game->screen == NULL)
		print_error(cub3d, "game->screen malloc error.");

	game->screen->img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (game->screen->img == NULL)
		print_error(cub3d, "game->screen->img malloc error.");

	game->screen->addr = mlx_get_data_addr(game->screen->img, &game->screen->bits_per_pixel, &game->screen->size_line, &game->screen->endian);
	if (game->screen->addr == NULL)
		print_error(cub3d, "game->screen->addr malloc error.");
}

void free_screen(t_cub3d *cub3d)
{
	if (cub3d->game->screen == NULL)
		return;
	if (cub3d->game->screen->img != NULL)
		mlx_destroy_image(cub3d->game->mlx, cub3d->game->screen->img);
	free(cub3d->game->screen);
}