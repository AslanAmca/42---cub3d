/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_init_free_minimap_image.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 22:36:03 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/11 22:36:06 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_cub3d.h"

void	b_init_minimap_image(t_cub3d *cub3d)
{
	cub3d->game->minimap_image = malloc(sizeof(t_mlx_image));
	if (cub3d->game->minimap_image == NULL)
		b_print_error(cub3d, "minimap_image malloc error.");
	cub3d->game->minimap_image->img = mlx_new_image(
			cub3d->game->mlx, MINIMAP_WIDTH, MINIMAP_HEIGHT);
	if (cub3d->game->minimap_image->img == NULL)
		b_print_error(cub3d, "minimap_image->img malloc error.");
	cub3d->game->minimap_image->addr = mlx_get_data_addr(
			cub3d->game->minimap_image->img,
			&cub3d->game->minimap_image->bits_per_pixel,
			&cub3d->game->minimap_image->size_line,
			&cub3d->game->minimap_image->endian);
	if (cub3d->game->minimap_image->addr == NULL)
		b_print_error(cub3d, "minimap_image->addr malloc error.");
}

void	b_free_minimap_image(t_cub3d *cub3d)
{
	if (cub3d->game->minimap_image != NULL)
	{
		if (cub3d->game->minimap_image->img != NULL)
			mlx_destroy_image(cub3d->game->mlx,
				cub3d->game->minimap_image->img);
		free(cub3d->game->minimap_image);
	}
}
