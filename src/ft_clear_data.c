/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:00:52 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/09 21:37:21 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void ft_clear_config_lines(t_data *data)
{
	char **lines;
	int i;

	lines = data->config_lines;
	i = 0;
	if (lines == NULL)
		return;
	while (lines[i] != NULL)
	{
		free(lines[i]);
		i++;
	}
	free(lines);
	lines = NULL;
}

static void ft_clear_textures(t_data *data)
{
	if (data->north_texture != NULL)
		free(data->north_texture);

	if (data->south_texture != NULL)
		free(data->south_texture);

	if (data->west_texture != NULL)
		free(data->west_texture);

	if (data->east_texture != NULL)
		free(data->east_texture);
}

void ft_clear_data(t_data *data)
{
	ft_clear_config_lines(data);
	ft_clear_textures(data);
	free(data);
	data = NULL;
}
