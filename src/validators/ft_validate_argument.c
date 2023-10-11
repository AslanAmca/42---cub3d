/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_argument.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:18:48 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/11 20:19:31 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void ft_validate_argument(t_data *data, int argument_count)
{
	if (argument_count == 1)
		ft_print_error(data, "Map name not entered. You must enter the map name for the program to work.");
	if (argument_count > 2)
		ft_print_error(data, "Only the map name should be entered as an argument.");
	if (data->config->filename == NULL || *data->config->filename == '\0')
		ft_print_error(data, "Map name cannot be null or empty.");
	if (ft_strcmp(data->config->filename + ft_strlen(data->config->filename) - 4, ".cub") != 0)
		ft_print_error(data, "Map name does not end with the .cub extension.");
}
