/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_turn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:07:43 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/08 23:52:35 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	player_turn_left(t_player *player)
{
	double	old_player_direction_x;
	double	old_camera_plane_x;

	old_player_direction_x = player->direction.x;
	old_camera_plane_x = player->camera_plane.x;
	player->direction.x = old_player_direction_x * cos(-TURN_SPEED)
		- player->direction.y * sin(-TURN_SPEED);
	player->direction.y = old_player_direction_x * sin(-TURN_SPEED)
		+ player->direction.y * cos(-TURN_SPEED);
	player->camera_plane.x = old_camera_plane_x * cos(-TURN_SPEED)
		- player->camera_plane.y * sin(-TURN_SPEED);
	player->camera_plane.y = old_camera_plane_x * sin(-TURN_SPEED)
		+ player->camera_plane.y * cos(-TURN_SPEED);
}

void	player_turn_right(t_player *player)
{
	double	old_player_direction_x;
	double	old_camera_plane_x;

	old_player_direction_x = player->direction.x;
	old_camera_plane_x = player->camera_plane.x;
	player->direction.x = old_player_direction_x * cos(TURN_SPEED)
		- player->direction.y * sin(TURN_SPEED);
	player->direction.y = old_player_direction_x * sin(TURN_SPEED)
		+ player->direction.y * cos(TURN_SPEED);
	player->camera_plane.x = old_camera_plane_x * cos(TURN_SPEED)
		- player->camera_plane.y * sin(TURN_SPEED);
	player->camera_plane.y = old_camera_plane_x * sin(TURN_SPEED)
		+ player->camera_plane.y * cos(TURN_SPEED);
}
