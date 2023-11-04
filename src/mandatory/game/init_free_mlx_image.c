/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_mlx_image.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:24:10 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/03 18:25:45 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void init_mlx_image(t_cub3d *cub3d)
{
	t_game *game;

	game = cub3d->game;

	game->mlx_image = malloc(sizeof(t_mlx_image));
	if (game->mlx_image == NULL)
		print_error(cub3d, "game->mlx_image malloc error.");

	game->mlx_image->img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (game->mlx_image->img == NULL)
		print_error(cub3d, "game->mlx_image->img malloc error.");

	game->mlx_image->addr = mlx_get_data_addr(game->mlx_image->img, &game->mlx_image->bits_per_pixel, &game->mlx_image->size_line, &game->mlx_image->endian);
	if (game->mlx_image->addr == NULL)
		print_error(cub3d, "game->mlx_image->addr malloc error.");
}

void free_mlx_image(t_cub3d *cub3d)
{
	if (cub3d->game->mlx_image == NULL)
		return;
	if (cub3d->game->mlx_image->img != NULL)
		mlx_destroy_image(cub3d->game->mlx, cub3d->game->mlx_image->img);
	free(cub3d->game->mlx_image);
}