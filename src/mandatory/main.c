/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:38:43 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/24 01:03:43 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int on_destroy_handler(t_config *config)
// {
// 	free_config(config);
// 	exit(EXIT_SUCCESS);
// }

// int on_keydown_handler(int key, t_config *config)
// {
// 	if (key == KEY_ESC)
// 	{
// 		on_destroy_handler(config);
// 	}
// 	return (0);
// }

// void start_game(t_cub3d *cub3d)
// {
// 	cub3d->game->mlx = mlx_init();

// 	if (cub3d->game->mlx == NULL)
// 		print_error(cub3d, "config->game->mlx malloc error.");

// 	cub3d->game->mlx_window = mlx_new_window(cub3d->game->mlx, 500, 500, "Cub3D");
// 	if (cub3d->game->mlx_window == NULL)
// 		print_error(cub3d, "config->game->mlx_window malloc error.");

// 	mlx_hook(cub3d->game->mlx_window, ON_DESTROY, 0, on_destroy_handler, data);
// 	mlx_hook(cub3d->game->mlx_window, ON_KEYDOWN, 1L << 0, on_keydown_handler, data);
// 	mlx_loop(cub3d->game->mlx);
// }

int main(int argc, char **argv)
{
	t_cub3d *cub3d;

	cub3d = init_cub3d(argc, argv[1]);


	validate_argument(cub3d);
	validate_config_is_non_empty(cub3d);
	set_config_line_count(cub3d);
	set_config_text(cub3d);
	validate_elements(cub3d);
	validate_map(cub3d);

	free_cub3d(cub3d);

	// game
	//start_game(config);

	return 0;
}
