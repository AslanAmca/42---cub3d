/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_raycasting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:08:32 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/10 00:45:04 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_cub3d.h"

void	b_raycasting(t_cub3d *cub3d)
{
	t_ray	ray;
	int		x;

	ray.real_position.x = cub3d->game->player->position.x;
	ray.real_position.y = cub3d->game->player->position.y;
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		b_ray_properties(&ray, cub3d->game->player, x);
		b_ray_draw_until_hit_wall(&ray, cub3d->config->map);
		b_ray_wall_properties(&ray, cub3d->game->player);
		b_ray_texture_properties(&ray);
		b_ray_fill_screen(&ray, cub3d->game, cub3d->config->map, x);
		x++;
	}
	mlx_put_image_to_window(cub3d->game->mlx, cub3d->game->window,
		cub3d->game->screen->img, 0, 0);
}
