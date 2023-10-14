/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_clear_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:09:13 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/14 20:26:46 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void ft_init_map(t_data *data)
{
	data->map = malloc(sizeof(t_map));
	if (data->map == NULL)
		ft_print_error(data, "t_data->map is null.");
	data->map->text = NULL;
	data->map->temp_text = NULL;
	data->map->starting_line = 0;
}

void ft_clear_map(t_data *data)
{
	if (data->map == NULL)
		return;
	ft_clear_double_pointer(data->map->text);
	ft_clear_double_pointer(data->map->temp_text);
	free(data->map);
}
