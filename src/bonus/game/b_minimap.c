/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_minimap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:35:57 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/11 23:08:46 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_cub3d.h"

static void	b_draw_border(t_cub3d *cub3d)
{
	t_mlx_image	*minimap;
	int			x;
	int			y;

	minimap = cub3d->game->minimap_image;
	y = 0;
	while (y < MINIMAP_HEIGHT)
	{
		x = 0;
		while (x < MINIMAP_WIDTH)
		{
			if (y == 0 || y == MINIMAP_HEIGHT - 1)
				b_put_pixel_to_mlx_image(minimap, x, y, 0);
			else if (x == 0 || x == MINIMAP_WIDTH - 1)
				b_put_pixel_to_mlx_image(minimap, x, y, 0);
			x++;
		}
		y++;
	}
}

static void	b_draw_player(t_cub3d *cub3d)
{
	t_player		*player;
	t_vector_double	distance;
	t_vector_double	player_minimap_position;

	player = cub3d->game->player;
	distance.x = player->position.x - (int)player->position.x;
	distance.y = player->position.y - (int)player->position.y;
	player_minimap_position.x = 36 * 2 + distance.x * 36;
	player_minimap_position.y = 36 * 2 + distance.y * 36;
	b_put_pixel_to_mlx_image(cub3d->game->minimap_image,
		player_minimap_position.x,
		player_minimap_position.y,
		0x00ff00);
}

static void	b_draw_square(t_mlx_image *minimap_image,
	t_vector_int minimap_position, unsigned int color)
{
	int	x;
	int	y;

	minimap_position.x = minimap_position.x * 36;
	minimap_position.y = minimap_position.y * 36;
	x = 0;
	while (x < 36)
	{
		y = 0;
		while (y < 36)
		{
			b_put_pixel_to_mlx_image(minimap_image,
				minimap_position.x + x, minimap_position.y + y, color);
			y++;
		}
		x++;
	}
}

static void	b_draw_assets(t_cub3d *cub3d,
	t_vector_int map_position, t_vector_int minimap_position)
{
	t_mlx_image	*minimap_image;
	t_map		*map;

	minimap_image = cub3d->game->minimap_image;
	map = cub3d->config->map;
	if (map_position.y < 0 || map_position.y >= map->row_count)
		b_draw_square(minimap_image, minimap_position, 0);
	else if (map_position.x < 0
		|| map_position.x >= ft_strlen(map->text[map_position.y]))
		b_draw_square(minimap_image, minimap_position, 0);
	else if (map->text[map_position.y][map_position.x] == ' ')
		b_draw_square(minimap_image, minimap_position, 0);
	else if (map->text[map_position.y][map_position.x] == '1')
		b_draw_square(minimap_image, minimap_position, 0x808080);
	else if (map->text[map_position.y][map_position.x] == 'D')
		b_draw_square(minimap_image, minimap_position, 0x5D3FD3);
	else if (map->text[map_position.y][map_position.x] == 'X')
		b_draw_square(minimap_image, minimap_position, 0x722F37);
	else if (map->text[map_position.y][map_position.x] == '0')
		b_draw_square(minimap_image, minimap_position, 0x6F4E37);
	else
		b_draw_square(minimap_image, minimap_position, 0x6F4E37);
}

void	b_minimap(t_cub3d *cub3d)
{
	t_player		*player;
	t_vector_int	map_position;
	t_vector_int	minimap_position;

	player = cub3d->game->player;
	minimap_position.y = 0;
	map_position.y = (int)player->position.y - 2;
	while (map_position.y <= (int)player->position.y + 2)
	{
		minimap_position.x = 0;
		map_position.x = (int)player->position.x - 2;
		while (map_position.x <= (int)player->position.x + 2)
		{
			b_draw_assets(cub3d, map_position, minimap_position);
			map_position.x++;
			minimap_position.x++;
		}
		map_position.y++;
		minimap_position.y++;
	}
	b_draw_player(cub3d);
	b_draw_border(cub3d);
	mlx_put_image_to_window(cub3d->game->mlx, cub3d->game->window,
		cub3d->game->minimap_image->img, 1, 1);
}
