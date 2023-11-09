/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_mlx_event_handlers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:48:03 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/10 00:49:09 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_cub3d.h"

int	b_destroy_handler(t_cub3d *cub3d)
{
	b_free_cub3d(cub3d);
	exit(EXIT_SUCCESS);
	return (0);
}

int	b_keydown_handler(int key, t_cub3d *cub3d)
{
	if (key == KEY_ESC)
		b_destroy_handler(cub3d);
	else if (key == KEY_E)
		b_open_close_door(cub3d);
	else if (key == KEY_W)
		cub3d->game->keys.w = 1;
	else if (key == KEY_S)
		cub3d->game->keys.s = 1;
	else if (key == KEY_A)
		cub3d->game->keys.a = 1;
	else if (key == KEY_D)
		cub3d->game->keys.d = 1;
	else if (key == KEY_LEFT)
		cub3d->game->keys.left = 1;
	else if (key == KEY_RIGHT)
		cub3d->game->keys.right = 1;
	return (0);
}

int	b_keyup_handler(int key, t_cub3d *cub3d)
{
	if (key == KEY_W)
		cub3d->game->keys.w = 0;
	else if (key == KEY_S)
		cub3d->game->keys.s = 0;
	else if (key == KEY_A)
		cub3d->game->keys.a = 0;
	else if (key == KEY_D)
		cub3d->game->keys.d = 0;
	else if (key == KEY_LEFT)
		cub3d->game->keys.left = 0;
	else if (key == KEY_RIGHT)
		cub3d->game->keys.right = 0;
	return (0);
}

int	b_mouse_handler(int x, int y, t_cub3d *cub3d)
{
	t_game	*game;

	game = cub3d->game;
	if (x < game->cursor_x)
		b_cursor_left(game->player);
	else if (x > game->cursor_x)
		b_cursor_right(game->player);
	else if (x == game->cursor_x)
	{
		if (x < SCREEN_WIDTH / 2)
			b_cursor_left(game->player);
		else
			b_cursor_right(game->player);
	}
	game->cursor_x = x;
	y = 1;
	(void)y;
	return (0);
}
