/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_fill_screen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:07:10 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/08 11:33:02 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static t_mlx_image	*get_wall_texture(t_ray *ray, t_game *game)
{
	t_mlx_image	*wall_texture;
	t_player	*player;

	player = game->player;
	wall_texture = NULL;
	if (ray->hit_wall_side == 'x')
	{
		if (ray->map_position.x < player->position.x)
			wall_texture = game->east_image;
		else
			wall_texture = game->west_image;
	}
	else if (ray->hit_wall_side == 'y')
	{
		if (ray->map_position.y < player->position.y)
			wall_texture = game->south_image;
		else
			wall_texture = game->north_image;
	}
	return (wall_texture);
}

void	ray_fill_screen(t_ray *ray, t_game *game, int x)
{
	t_mlx_image	*wall_texture;
	int			y;

	wall_texture = get_wall_texture(ray, game);
	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		if (y < ray->screen.wall_start_point)
			put_pixel_to_mlx_image(game->screen, x, y, game->ceiling_rgb);
		else if (y > ray->screen.wall_end_point)
			put_pixel_to_mlx_image(game->screen, x, y, game->floor_rgb);
		else
		{
			double overflow_control_texture_start_point_y = (int)ray->screen.texture_start_point_y & (64 - 1);
			double texture_start_point_x = ray->screen.hit_point_in_wall_texture;
			int texture_pixel_color = get_pixel_color_from_texture(wall_texture, texture_start_point_x, overflow_control_texture_start_point_y);
			put_pixel_to_mlx_image(game->screen, x, y, texture_pixel_color);
			ray->screen.texture_start_point_y += ray->texture_pixel_for_one_pixel;
		}
		y++;
	}
}
