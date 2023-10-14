/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:38:43 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/14 20:33:11 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_validate_argument(int argument_count, char *filename)
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
	ft_validate_argument(argc, filename);
	ft_validate_config_is_non_empty(filename);
	data = ft_init_data();
	ft_set_config_line_count(data, filename);
	ft_set_config_text(data, filename);
	ft_validate_elements(data);

	// map validation
	ft_set_map_text(data);
	ft_check_map_empty_line(data, filename);
	ft_validate_map_characters(data);
	ft_validate_map_walls(data);

	// buraya kadar hata olmazsa ft_print_error üzerinden clear_data çalışmıyor.
	// dolayısıyla memory leak oluyor. şimdilik burada manuel clear yapalım.
	ft_clear_data(data);

	return 0;
}
