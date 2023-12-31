/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:38:43 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/08 23:53:36 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cub3d	*cub3d;

	cub3d = init_cub3d(argc, argv[1]);
	validate_argument(cub3d);
	validate_config_is_non_empty(cub3d);
	set_config_line_count(cub3d);
	set_config_text(cub3d);
	validate_elements(cub3d);
	validate_map(cub3d);
	init_game(cub3d);
	raycasting(cub3d);
	mlx_put_image_to_window(cub3d->game->mlx, cub3d->game->window,
		cub3d->game->screen->img, 0, 0);
	mlx_hook(cub3d->game->window, ON_DESTROY, 0, destroy_handler, cub3d);
	mlx_hook(cub3d->game->window, ON_KEYDOWN, 1L << 0, keydown_handler, cub3d);
	mlx_hook(cub3d->game->window, ON_KEYUP, 1L << 1, keyup_handler, cub3d);
	mlx_loop_hook(cub3d->game->mlx, loop_handler, cub3d);
	mlx_loop(cub3d->game->mlx);
	return (0);
}
