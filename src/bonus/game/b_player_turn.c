/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_player_turn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:07:43 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/09 04:01:59 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_cub3d.h"

void	b_player_turn_left(t_player *player)
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

void	b_player_turn_right(t_player *player)
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

void	b_cursor_left(t_player *player)
{
	double	old_player_direction_x;
	double	old_camera_plane_x;

	old_player_direction_x = player->direction.x;
	old_camera_plane_x = player->camera_plane.x;
	player->direction.x = old_player_direction_x * cos(-CURSOR_SPEED)
		- player->direction.y * sin(-CURSOR_SPEED);
	player->direction.y = old_player_direction_x * sin(-CURSOR_SPEED)
		+ player->direction.y * cos(-CURSOR_SPEED);
	player->camera_plane.x = old_camera_plane_x * cos(-CURSOR_SPEED)
		- player->camera_plane.y * sin(-CURSOR_SPEED);
	player->camera_plane.y = old_camera_plane_x * sin(-CURSOR_SPEED)
		+ player->camera_plane.y * cos(-CURSOR_SPEED);
}

void	b_cursor_right(t_player *player)
{
	double	old_player_direction_x;
	double	old_camera_plane_x;

	old_player_direction_x = player->direction.x;
	old_camera_plane_x = player->camera_plane.x;
	player->direction.x = old_player_direction_x * cos(CURSOR_SPEED)
		- player->direction.y * sin(CURSOR_SPEED);
	player->direction.y = old_player_direction_x * sin(CURSOR_SPEED)
		+ player->direction.y * cos(CURSOR_SPEED);
	player->camera_plane.x = old_camera_plane_x * cos(CURSOR_SPEED)
		- player->camera_plane.y * sin(CURSOR_SPEED);
	player->camera_plane.y = old_camera_plane_x * sin(CURSOR_SPEED)
		+ player->camera_plane.y * cos(CURSOR_SPEED);
}
