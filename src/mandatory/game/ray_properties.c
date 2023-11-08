/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_properties.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:54:48 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/08 11:35:08 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	initial_hit_distance_and_step(t_ray *ray)
{
	if (ray->direction.x < 0)
	{
		ray->map_step.x = -1;
		ray->initial_hit_distance.x = (ray->real_position.x - ray->map_position.x) * ray->next_hit_distance.x;
	}
	else
	{
		ray->map_step.x = 1;
		ray->initial_hit_distance.x = (ray->map_position.x + 1.0 - ray->real_position.x) * ray->next_hit_distance.x;
	}
	if (ray->direction.y < 0)
	{
		ray->map_step.y = -1;
		ray->initial_hit_distance.y = (ray->real_position.y - ray->map_position.y) * ray->next_hit_distance.y;
	}
	else
	{
		ray->map_step.y = 1;
		ray->initial_hit_distance.y = (ray->map_position.y + 1.0 - ray->real_position.y) * ray->next_hit_distance.y;
	}
}

void	ray_properties(t_ray *ray, t_player *player, int x)
{
	double	normalized_camera_x;

	normalized_camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	ray->direction.x = player->direction.x + player->camera_plane.x * normalized_camera_x;
	ray->direction.y = player->direction.y + player->camera_plane.y * normalized_camera_x;
	ray->next_hit_distance.x = fabs(1 / ray->direction.x);
	ray->next_hit_distance.y = fabs(1 / ray->direction.y);
	ray->map_position.x = (int)player->position.x;
	ray->map_position.y = (int)player->position.y;
	ray->hit_wall = 0;
	initial_hit_distance_and_step(ray);
}
