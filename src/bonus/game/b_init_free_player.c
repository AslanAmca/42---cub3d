/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_init_free_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:50:39 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/09 00:55:22 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_cub3d.h"

static int	character_is_player(char chr)
{
	if (chr == 'N' || chr == 'S' || chr == 'W' || chr == 'E')
	{
		return (1);
	}
	return (0);
}

static void	set_player_direction(t_player *player, char player_direction)
{
	if (player_direction == 'N')
	{
		player->direction.y = -1;
		player->camera_plane.x = 0.66;
	}
	else if (player_direction == 'S')
	{
		player->direction.y = 1;
		player->camera_plane.x = -0.66;
	}
	else if (player_direction == 'W')
	{
		player->direction.x = -1;
		player->camera_plane.y = -0.66;
	}
	else if (player_direction == 'E')
	{
		player->direction.x = 1;
		player->camera_plane.y = 0.66;
	}
}

static void	set_player_properties(t_cub3d *cub3d)
{
	t_map	*map;
	int		row;
	int		col;

	map = cub3d->config->map;
	row = 0;
	while (map->text[row] != NULL)
	{
		col = 0;
		while (map->text[row][col] != '\0')
		{
			if (character_is_player(map->text[row][col]))
			{
				cub3d->game->player->position.x = (double)col + 0.5;
				cub3d->game->player->position.y = (double)row + 0.5;
				set_player_direction(cub3d->game->player, map->text[row][col]);
			}
			col++;
		}
		row++;
	}
}

void	b_init_player(t_cub3d *cub3d)
{
	cub3d->game->player = malloc(sizeof(t_player));
	if (cub3d->game->player == NULL)
		b_print_error(cub3d, "player malloc error.");
	cub3d->game->player->position.x = 0;
	cub3d->game->player->position.y = 0;
	cub3d->game->player->direction.x = 0;
	cub3d->game->player->direction.y = 0;
	cub3d->game->player->camera_plane.x = 0;
	cub3d->game->player->camera_plane.y = 0;
	set_player_properties(cub3d);
}

void	b_free_player(t_cub3d *cub3d)
{
	if (cub3d->game->player == NULL)
		return ;
	free(cub3d->game->player);
}
