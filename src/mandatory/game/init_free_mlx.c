/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_mlx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:55:30 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/08 12:32:27 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_mlx(t_cub3d *cub3d)
{
	int	w;
	int	h;

	w = SCREEN_WIDTH;
	h = SCREEN_HEIGHT;
	cub3d->game->mlx = mlx_init();
	if (cub3d->game->mlx == NULL)
		print_error(cub3d, "mlx malloc error.");
	cub3d->game->window = mlx_new_window(cub3d->game->mlx, w, h, "Cub3D");
	if (cub3d->game->window == NULL)
		print_error(cub3d, "window malloc error.");
}

void	free_mlx(t_cub3d *cub3d)
{
	if (cub3d->game->mlx == NULL)
		return ;
	if (cub3d->game->window != NULL)
		mlx_destroy_window(cub3d->game->mlx, cub3d->game->window);
	mlx_destroy_display(cub3d->game->mlx);
	free(cub3d->game->mlx);
}
