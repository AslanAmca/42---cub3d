/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_elements_count.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 22:18:44 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/14 20:07:47 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void set_elements_count(t_data *data)
{
	char *line;
	int i;

	line = NULL;
	i = 0;
	while (i < 6)
	{
		line = data->config->text[i];
		if (ft_strncmp("NO", line, 2) == 0)
			data->texture->north_count++;
		if (ft_strncmp("SO", line, 2) == 0)
			data->texture->south_count++;
		if (ft_strncmp("WE", line, 2) == 0)
			data->texture->west_count++;
		if (ft_strncmp("EA", line, 2) == 0)
			data->texture->east_count++;
		if (ft_strncmp("F", line, 1) == 0)
			data->floor_color->count++;
		if (ft_strncmp("C", line, 1) == 0)
			data->ceiling_color->count++;
		i++;
	}
}