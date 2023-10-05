/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:38:43 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/05 13:17:58 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

void ft_print_error(char *message)
{
	printf("Error!\n%s\n", message);
	exit(EXIT_FAILURE);
}

// 1 - Argüman sayısını kontrol et. Proje adı ve harita adı olacağı için argüman sayısı 2 olmalıdır.
// 2 - Argüman .cub uzantılı harita adı olmalıdır.
void ft_validate_argument(int argument_count, char *map_name)
{
	if (argument_count == 1)
		ft_print_error("Map name not entered. You must enter the map name for the program to work.");
	if (argument_count > 2)
		ft_print_error("Only the map name should be entered as an argument.");
	if (map_name == NULL || *map_name == '\0')
		ft_print_error("Map name cannot be null or empty.");
	if (ft_strcmp(map_name + ft_strlen(map_name) - 4, ".cub") != 0)
		ft_print_error("Map name does not end with the .cub extension.");
}

int main(int argc, char **argv)
{
	ft_validate_argument(argc, argv[1]);

	// harita dosyası var mı yok mu diye kontrol etmek gerekiyor.
	char *map_name = argv[1];
	int map_fd = open(map_name, O_RDONLY);
	if (map_fd < 3)
		ft_print_error("Map file not found.");
}
