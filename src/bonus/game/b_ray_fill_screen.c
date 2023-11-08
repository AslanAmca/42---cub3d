/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ray_fill_screen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:07:10 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/09 01:33:05 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_cub3d.h"

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

void	b_ray_fill_screen(t_ray *ray, t_game *game, int x)
{
	t_mlx_image	*wall_texture;
	double		texture_offset_y;
	double		texture_offset_x;
	int			texture_color;
	int			y;

	wall_texture = get_wall_texture(ray, game);
	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		if (y < ray->screen.wall_start_point)
			b_put_pixel_to_mlx_image(game->screen, x, y, game->ceiling_rgb);
		else if (y > ray->screen.wall_end_point)
			b_put_pixel_to_mlx_image(game->screen, x, y, game->floor_rgb);
		else
		{
			texture_offset_y = (int)ray->screen.texture_offset_y & (64 - 1);
			texture_offset_x = ray->screen.hit_point_wall_texture;
			texture_color = b_get_image_color(wall_texture,
					texture_offset_x, texture_offset_y);
			b_put_pixel_to_mlx_image(game->screen, x, y, texture_color);
			ray->screen.texture_offset_y += ray->screen.texture_pixel_ratio;
		}
		y++;
	}
}
