/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_clear_colors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:07:02 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/14 20:26:27 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void init_colors(t_data *data)
{
	data->floor_color = malloc(sizeof(t_color));
	if (data->floor_color == NULL)
		print_error(data, "t_data->floor_color malloc error.");
	data->ceiling_color = malloc(sizeof(t_color));
	if (data->ceiling_color == NULL)
		print_error(data, "t_data->ceiling_color malloc error.");
	data->floor_color->red = -1;
	data->floor_color->green = -1;
	data->floor_color->blue = -1;
	data->floor_color->count = 0;
	data->floor_color->string = NULL;
	data->floor_color->red_string = NULL;
	data->floor_color->green_string = NULL;
	data->floor_color->blue_string = NULL;
	data->ceiling_color->red = -1;
	data->ceiling_color->green = -1;
	data->ceiling_color->blue = -1;
	data->ceiling_color->count = 0;
	data->ceiling_color->string = NULL;
	data->ceiling_color->red_string = NULL;
	data->ceiling_color->green_string = NULL;
	data->ceiling_color->blue_string = NULL;
}

void clear_colors(t_data *data)
{
	if (data->floor_color != NULL)
	{
		if (data->floor_color->string != NULL)
			free(data->floor_color->string);
		if (data->floor_color->red_string != NULL)
			free(data->floor_color->red_string);
		if (data->floor_color->green_string != NULL)
			free(data->floor_color->green_string);
		if (data->floor_color->blue_string != NULL)
			free(data->floor_color->blue_string);
		free(data->floor_color);
	}
	if (data->ceiling_color != NULL)
	{
		if (data->ceiling_color->string != NULL)
			free(data->ceiling_color->string);
		if (data->ceiling_color->red_string != NULL)
			free(data->ceiling_color->red_string);
		if (data->ceiling_color->green_string != NULL)
			free(data->ceiling_color->green_string);
		if (data->ceiling_color->blue_string != NULL)
			free(data->ceiling_color->blue_string);
		free(data->ceiling_color);
	}
}
