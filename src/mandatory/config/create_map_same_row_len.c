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

char **create_map_same_row_len(t_cub3d *cub3d)
{
	t_config *config;
	char **map;
	int i;

	config = cub3d->config;
	map = malloc(sizeof(char *) * (config->map->row_count + 1));
	if (map == NULL)
		print_error(cub3d, "create_map_same_row_len malloc error.");
	i = 0;
	while (config->map->text[i] != NULL)
	{
		map[i] = malloc(config->map->col_count + 1);
		if (map[i] == NULL)
		{
			free_double_pointer(map);
			print_error(cub3d, "create_map_same_row_len[i] malloc error.");
		}
		ft_strncpy(map[i], config->map->text[i], config->map->col_count);
		i++;
	}
	map[i] = NULL;
	return (map);
}
