/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_open_close_door.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 04:10:43 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/09 09:05:30 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_cub3d.h"

static int	is_door(char character)
{
	if (character == 'D' || character == 'X')
	{
		return (1);
	}
	return (0);
}

static void	open_close_door(t_map *map, int y, int x)
{
	if (map->text[y][x] == 'D')
		map->text[y][x] = 'X';
	else if (map->text[y][x] == 'X')
		map->text[y][x] = 'D';
}

void	b_open_close_door(t_cub3d *cub3d)
{
	t_map			*map;
	t_vector_int	player_position;

	map = cub3d->config->map;
	player_position.x = cub3d->game->player->position.x;
	player_position.y = cub3d->game->player->position.y;
	if (map->text[player_position.y + 1] != NULL
		&& is_door(map->text[player_position.y + 1][player_position.x]))
		open_close_door(map, player_position.y + 1, player_position.x);
	if (map->text[player_position.y - 1] != NULL
		&& is_door(map->text[player_position.y - 1][player_position.x]))
		open_close_door(map, player_position.y - 1, player_position.x);
	if (map->text[player_position.y][player_position.x + 1] != '\0'
		&& is_door(map->text[player_position.y][player_position.x + 1]))
		open_close_door(map, player_position.y, player_position.x + 1);
	if (map->text[player_position.y][player_position.x - 1] != '\0'
		&& is_door(map->text[player_position.y][player_position.x - 1]))
		open_close_door(map, player_position.y, player_position.x - 1);
	b_raycasting(cub3d);
	mlx_put_image_to_window(cub3d->game->mlx,
		cub3d->game->window, cub3d->game->screen->img, 0, 0);
}
