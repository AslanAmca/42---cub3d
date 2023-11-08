/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_text.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:33:24 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/15 01:19:50 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_map_text(t_cub3d *cub3d)
{
	t_config	*config;
	int			map_index;
	int			col_count;
	int			i;

	config = cub3d->config;
	map_index = 6;
	config->map->row_count = config->full_line_count - map_index;
	config->map->text = malloc(sizeof(char *) * (config->map->row_count + 1));
	if (config->map->text == NULL)
		print_error(cub3d, "config->map->text malloc error.");
	col_count = 0;
	i = 0;
	while (config->text[map_index] != NULL)
	{
		config->map->text[i] = ft_strdup(config->text[map_index]);
		col_count = ft_strlen(config->text[map_index]);
		if (col_count > config->map->col_count)
			config->map->col_count = col_count;
		i++;
		map_index++;
	}
	config->map->text[i] = NULL;
}
