/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_init_free_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 23:24:22 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/11 12:14:56 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_cub3d.h"

static void	b_init_game_null(t_cub3d *cub3d)
{
	cub3d->game->mlx = NULL;
	cub3d->game->window = NULL;
	cub3d->game->screen = NULL;
	cub3d->game->player = NULL;
	cub3d->game->north_image = NULL;
	cub3d->game->south_image = NULL;
	cub3d->game->west_image = NULL;
	cub3d->game->east_image = NULL;
	cub3d->game->ceiling_rgb = 0;
	cub3d->game->floor_rgb = 0;
	cub3d->game->door_image = NULL;
	cub3d->game->door0_image = NULL;
	cub3d->game->door1_image = NULL;
	cub3d->game->door2_image = NULL;
	cub3d->game->door3_image = NULL;
}

static void	b_init_keys(t_cub3d *cub3d)
{
	cub3d->game->keys.w = 0;
	cub3d->game->keys.s = 0;
	cub3d->game->keys.a = 0;
	cub3d->game->keys.d = 0;
	cub3d->game->keys.left = 0;
	cub3d->game->keys.right = 0;
}

static void	b_init_bonus_props(t_cub3d *cub3d)
{
	b_init_door0_image(cub3d);
	b_init_door1_image(cub3d);
	b_init_door2_image(cub3d);
	b_init_door3_image(cub3d);
	cub3d->game->door_image = cub3d->game->door0_image;
	cub3d->game->counter = -1;
	cub3d->game->cursor_x = SCREEN_WIDTH / 2;
}

void	b_init_game(t_cub3d *cub3d)
{
	cub3d->game = malloc(sizeof(t_game));
	if (cub3d->game == NULL)
		b_print_error(cub3d, "game malloc error.");
	b_init_game_null(cub3d);
	b_init_mlx(cub3d);
	b_init_screen(cub3d);
	b_init_north_mlx_image(cub3d);
	b_init_south_mlx_image(cub3d);
	b_init_west_mlx_image(cub3d);
	b_init_east_mlx_image(cub3d);
	b_init_ceiling_rgb(cub3d);
	b_init_floor_rgb(cub3d);
	b_init_player(cub3d);
	b_init_keys(cub3d);
	b_init_bonus_props(cub3d);
}

void	b_free_game(t_cub3d *cub3d)
{
	if (cub3d->game == NULL)
		return ;
	b_free_player(cub3d);
	b_free_xpm_images(cub3d);
	b_free_door_images(cub3d);
	b_free_screen(cub3d);
	b_free_mlx(cub3d);
	free(cub3d->game);
}
