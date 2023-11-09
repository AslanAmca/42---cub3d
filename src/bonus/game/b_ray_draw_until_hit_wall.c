/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ray_draw_until_hit_wall.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:59:55 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/09 03:49:10 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_cub3d.h"

void	b_ray_draw_until_hit_wall(t_ray *ray, t_map *map)
{
	while (ray->hit_wall == 0)
	{
		if (ray->initial_hit_dist.x < ray->initial_hit_dist.y)
		{
			ray->initial_hit_dist.x += ray->next_hit_dist.x;
			ray->map_position.x += ray->map_step.x;
			ray->hit_wall_side = 'x';
		}
		else
		{
			ray->initial_hit_dist.y += ray->next_hit_dist.y;
			ray->map_position.y += ray->map_step.y;
			ray->hit_wall_side = 'y';
		}
		if (map->text[ray->map_position.y] == NULL)
			break ;
		if (map->text[ray->map_position.y][ray->map_position.x] == '1'
			|| map->text[ray->map_position.y][ray->map_position.x] == 'D')
			ray->hit_wall = 1;
	}
}
