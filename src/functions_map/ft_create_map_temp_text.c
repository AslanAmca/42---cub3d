/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map_temp_text.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 23:57:27 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/15 23:57:43 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char **ft_create_map_temp_text(t_data *data)
{
	char **map;
	int i;

	map = malloc(sizeof(char *) * (data->map->row_count + 1));
	if (map == NULL)
		ft_print_error(data, "ft_create_map_temp_text malloc error.");
	i = 0;
	while (data->map->text[i] != NULL)
	{
		map[i] = malloc(data->map->col_count + 1);
		if (map[i] == NULL)
		{
			ft_clear_double_pointer(map);
			ft_print_error(data, "ft_create_map_temp_text malloc error.");
		}
		ft_strncpy(map[i], data->map->text[i], data->map->col_count);
		i++;
	}
	map[i] = NULL;
	return (map);
}
