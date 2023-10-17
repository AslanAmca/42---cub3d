/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_same_row_len.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 23:50:27 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/16 23:51:21 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char **create_map_same_row_len(t_data *data)
{
	char **map;
	int i;

	map = malloc(sizeof(char *) * (data->map->row_count + 1));
	if (map == NULL)
		print_error(data, "create_map_same_row_len malloc error.");
	i = 0;
	while (data->map->text[i] != NULL)
	{
		map[i] = malloc(data->map->col_count + 1);
		if (map[i] == NULL)
		{
			clear_double_pointer(map);
			print_error(data, "create_map_same_row_len[i] malloc error.");
		}
		ft_strncpy(map[i], data->map->text[i], data->map->col_count);
		i++;
	}
	map[i] = NULL;
	return (map);
}
