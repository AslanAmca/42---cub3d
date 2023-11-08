/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:08:32 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/08 10:08:47 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void raycasting(t_cub3d *cub3d)
{
	t_ray ray;
	int x;

	ray.real_position.x = cub3d->game->player->position.x;
	ray.real_position.y = cub3d->game->player->position.y;
	x = 0;

	// Ekranın her pikseli için bir hesaplama yapmak yerine, yalnızca her dikey şerit için bir hesaplama yapar. Bu, çok daha verimli bir yaklaşımdır.
	// Raycasting döngüsü bu şekilde her dikey şerit için çalışır ve her bir şerit için ışının başlangıç konumu ve yönü hesaplanır.
	while (x < SCREEN_WIDTH)
	{
		ray_properties(&ray, cub3d->game->player, x);
		ray_draw_until_hit_wall(&ray, cub3d->config->map);
		ray_wall_properties(&ray, cub3d->game->player);
		ray_texture_properties(&ray);
		ray_fill_screen(&ray, cub3d->game, x);
		x++;
	}
}
