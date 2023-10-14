/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_map_text.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:33:24 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/15 01:19:50 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void ft_set_map_text(t_data *data)
{
	int map_index;
	int col_count;
	int i;

	map_index = 6;
	data->map->row_count = data->config->full_line_count - map_index;
	data->map->text = malloc(sizeof(char *) * (data->map->row_count + 1));
	if (data->map->text == NULL)
		ft_print_error(data, "data->map->text is null.");
	col_count = 0;
	i = 0;
	while (data->config->text[map_index] != NULL)
	{
		data->map->text[i] = ft_strdup(data->config->text[map_index]);
		col_count = ft_strlen(data->config->text[map_index]);
		if (col_count > data->map->col_count)
			data->map->col_count = col_count;
		i++;
		map_index++;
	}
	data->map->text[i] = NULL;
}
