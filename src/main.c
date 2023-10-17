/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:38:43 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/17 17:32:29 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#ifdef __linux__
#include "../mlx_linux/mlx.h"
#endif

#ifdef __APPLE__
#include "../mlx_macos/mlx.h"
#endif

void validate_argument(int argument_count, char *filename)
{
	if (argument_count == 1)
	{
		printf("Map name not entered. You must enter the map name for the program to work.\n");
		exit(EXIT_FAILURE);
	}
	if (argument_count > 2)
	{
		printf("Only the map name should be entered as an argument.\n");
		exit(EXIT_FAILURE);
	}
	if (filename == NULL || *filename == '\0')
	{
		printf("Map name cannot be null or empty.\n");
		exit(EXIT_FAILURE);
	}
	if (ft_strcmp(filename + ft_strlen(filename) - 4, ".cub") != 0)
	{
		printf("Map name does not end with the .cub extension.\n");
		exit(EXIT_FAILURE);
	}
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
	void *mlx = mlx_init();
	void *mlx_window = mlx_new_window(mlx, 500, 500, "Cub3D");
	mlx_loop(mlx);
	printf("mlx : %p", mlx_window);

	// buraya kadar hata olmazsa print_error üzerinden clear_data çalışmıyor.
	// dolayısıyla memory leak oluyor. şimdilik burada manuel clear yapalım.
	clear_data(data);

	return 0;
}
