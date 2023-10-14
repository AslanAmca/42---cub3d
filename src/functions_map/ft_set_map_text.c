/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_map_text.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:33:24 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/14 20:25:04 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void ft_set_map_text(t_data *data)
{
	int len;
	int map_index;
	int i;

	map_index = 6;
	len = data->config->full_line_count - map_index;
	data->map->text = malloc(sizeof(char *) * (len + 1));
	if (data->map->text == NULL)
		ft_print_error(data, "data->map->text is null.");
	i = 0;
	while (data->config->text[map_index] != NULL)
	{
		data->map->text[i] = ft_strdup(data->config->text[map_index]);
		i++;
		map_index++;
	}
	data->map->text[i] = NULL;
}
