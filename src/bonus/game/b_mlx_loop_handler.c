/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_mlx_loop_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:52:29 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/11 20:27:06 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_cub3d.h"

static void	b_player_move(t_cub3d *cub3d)
{
	if (cub3d->game->keys.w == 1)
		b_player_move_up(cub3d->config->map, cub3d->game->player);
	if (cub3d->game->keys.s == 1)
		b_player_move_down(cub3d->config->map, cub3d->game->player);
	if (cub3d->game->keys.a == 1)
		b_player_move_left(cub3d->config->map, cub3d->game->player);
	if (cub3d->game->keys.d == 1)
		b_player_move_right(cub3d->config->map, cub3d->game->player);
	if (cub3d->game->keys.left == 1)
		b_player_turn_left(cub3d->game->player);
	if (cub3d->game->keys.right == 1)
		b_player_turn_right(cub3d->game->player);
}

int	b_loop_handler(t_cub3d *cub3d)
{
	t_game	*game;

	game = cub3d->game;
	game->counter++;
	if (game->counter % 50 == 0)
	{
		if (game->counter == 0)
			game->door_image = game->door0_image;
		else if (game->counter == 1500)
			game->door_image = game->door1_image;
		else if (game->counter == 3000)
			game->door_image = game->door2_image;
		else if (game->counter == 4500)
			game->door_image = game->door3_image;
		else if (game->counter == 6000)
			game->counter = -1;
		b_player_move(cub3d);
		b_raycasting(cub3d);
		b_minimap(cub3d);
	}
	return (0);
}
