/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:38:43 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/18 21:04:36 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/cub3d.h"

int on_destroy_handler(t_data *data)
{
	clear_data(data);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}


int main(int argc, char **argv)
{
	t_data *data;
	char *filename;

	filename = argv[1];
	validate_argument(argc, filename);
	validate_config_is_non_empty(filename);
	data = init_data();
	set_config_line_count(data, filename);
	set_config_text(data, filename);
	validate_elements(data);
	validate_map(data, filename);

	// mlx
	data->game->mlx = mlx_init();
	if (data->game->mlx == NULL)
		print_error(data, "data->game->mlx malloc error.");

	data->game->mlx_window = mlx_new_window(data->game->mlx, 500, 500, "Cub3D");
	if (data->game->mlx_window == NULL)
		print_error(data, "data->game->mlx_window malloc error.");

	mlx_hook(data->game->mlx_window, ON_DESTROY, 0, on_destroy_handler, data);
	mlx_loop(data->game->mlx);

	return 0;
}
