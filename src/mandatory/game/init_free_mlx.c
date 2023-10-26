/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_mlx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:55:30 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/26 19:27:23 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void init_mlx(t_cub3d *cub3d)
{
	t_game *game;

	game = cub3d->game;
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		print_error(cub3d, "mlx malloc error.");
	game->mlx_window = mlx_new_window(game->mlx, 1920, 1080, "Cub3D");
	if (game->mlx_window == NULL)
		print_error(cub3d, "mlx_window malloc error.");
}

void free_mlx(t_cub3d *cub3d)
{
	if (cub3d->game->mlx == NULL)
		return;
	if (cub3d->game->mlx_window != NULL)
		mlx_destroy_window(cub3d->game->mlx, cub3d->game->mlx_window);
	mlx_destroy_display(cub3d->game->mlx); // sadece linux'ta lazım diye hatırlıyorum, macos'ta gereksiz olabilir.
	free(cub3d->game->mlx);
}