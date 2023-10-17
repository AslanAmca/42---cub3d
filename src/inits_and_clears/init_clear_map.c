/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_clear_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:09:13 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/16 23:48:20 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void init_map(t_data *data)
{
	data->map = malloc(sizeof(t_map));
	if (data->map == NULL)
		print_error(data, "t_data->map is null.");
	data->map->text = NULL;
	data->map->starting_line = 0;
	data->map->row_count = 0;
	data->map->col_count = 0;
}

void clear_map(t_data *data)
{
	if (data->map == NULL)
		return;
	clear_double_pointer(data->map->text);
	free(data->map);
}
