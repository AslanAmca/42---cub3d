/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_argument.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:04:21 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/18 21:04:40 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

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
