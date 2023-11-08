/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:38:43 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/09 02:51:42 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_cub3d.h"

int	main(int argc, char **argv)
{
	t_cub3d	*cub3d;

	cub3d = b_init_cub3d(argc, argv[1]);
	b_validate_argument(cub3d);
	b_validate_config_is_non_empty(cub3d);
	b_set_config_line_count(cub3d);
	b_set_config_text(cub3d);
	b_validate_elements(cub3d);
	b_validate_map(cub3d);
	b_init_game(cub3d);
	b_raycasting(cub3d);
	mlx_put_image_to_window(cub3d->game->mlx, cub3d->game->window,
		cub3d->game->screen->img, 0, 0);
	mlx_hook(cub3d->game->window, ON_DESTROY, 0, b_destroy_handler, cub3d);
	mlx_hook(cub3d->game->window, ON_KEYDOWN, 1L << 0,
		b_keydown_handler, cub3d);
	mlx_hook(cub3d->game->window, ON_KEYUP, 1L << 1,
		b_keyup_handler, cub3d);
	mlx_hook(cub3d->game->window, ON_MOUSEMOVE, 1L << 6,
		b_mouse_handler, cub3d);
	mlx_loop_hook(cub3d->game->mlx, b_loop_handler, cub3d);
	mlx_loop(cub3d->game->mlx);
	return (0);
}
