/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_clear_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:05:16 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/14 20:26:41 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_data *init_data(void)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		print_error(data, "t_data is null.");
	init_config(data);
	init_textures(data);
	init_colors(data);
	init_map(data);
	init_player(data);
	return data;
}

void clear_data(t_data *data)
{
	clear_config(data);
	clear_textures(data);
	clear_colors(data);
	clear_map(data);
	clear_player(data);
	free(data);
}
