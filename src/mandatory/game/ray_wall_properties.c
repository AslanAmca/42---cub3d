/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_wall_properties.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:01:49 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/08 12:23:13 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ray_wall_properties(t_ray *ray, t_player *player)
{
	t_screen	*screen;

	screen = &ray->screen;
	if (ray->hit_wall_side == 'x')
		ray->wall_perp_dist = ray->initial_hit_dist.x - ray->next_hit_dist.x;
	else
		ray->wall_perp_dist = ray->initial_hit_dist.y - ray->next_hit_dist.y;
	screen->wall_height = (long)(SCREEN_HEIGHT / ray->wall_perp_dist);
	screen->wall_start_point = SCREEN_HEIGHT / 2 - screen->wall_height / 2;
	screen->wall_end_point = SCREEN_HEIGHT / 2 + screen->wall_height / 2;
	if (ray->hit_wall_side == 'x')
		ray->hit_point_wall = player->position.y
			+ ray->wall_perp_dist * ray->direction.y;
	else
		ray->hit_point_wall = player->position.x
			+ ray->wall_perp_dist * ray->direction.x;
	ray->hit_point_wall -= floor(ray->hit_point_wall);
	screen->hit_point_wall_texture = (int)(ray->hit_point_wall * (double)64);
	if (ray->hit_wall_side == 'x' && ray->direction.x > 0)
		screen->hit_point_wall_texture = 64
			- screen->hit_point_wall_texture - 1;
	if (ray->hit_wall_side == 'y' && ray->direction.y < 0)
		screen->hit_point_wall_texture = 64
			- screen->hit_point_wall_texture - 1;
}
