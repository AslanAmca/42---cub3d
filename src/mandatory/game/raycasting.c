/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:08:32 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/08 11:37:24 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	raycasting(t_cub3d *cub3d)
{
	t_ray	ray;
	int		x;

	ray.real_position.x = cub3d->game->player->position.x;
	ray.real_position.y = cub3d->game->player->position.y;
	x = 0;
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
