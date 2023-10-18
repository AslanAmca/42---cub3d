/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_clear_textures.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:08:29 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/14 20:26:55 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void init_textures(t_data *data)
{
	data->texture = malloc(sizeof(t_texture));
	if (data->texture == NULL)
		print_error(data, "t_data->texture malloc error.");
	data->texture->north = NULL;
	data->texture->south = NULL;
	data->texture->west = NULL;
	data->texture->east = NULL;
	data->texture->north_count = 0;
	data->texture->south_count = 0;
	data->texture->west_count = 0;
	data->texture->east_count = 0;
}

void clear_textures(t_data *data)
{
	if (data->texture == NULL)
		return;
	if (data->texture->north != NULL)
		free(data->texture->north);
	if (data->texture->south != NULL)
		free(data->texture->south);
	if (data->texture->west != NULL)
		free(data->texture->west);
	if (data->texture->east != NULL)
		free(data->texture->east);
	free(data->texture);
}
