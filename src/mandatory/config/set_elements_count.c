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

void set_elements_count(t_cub3d *cub3d)
{
	char *line;
	int i;

	line = NULL;
	i = 0;
	while (i < 6)
	{
		line = cub3d->config->text[i];
		if (ft_strncmp("NO", line, 2) == 0)
			cub3d->config->xpm_files->north_count++;
		if (ft_strncmp("SO", line, 2) == 0)
			cub3d->config->xpm_files->south_count++;
		if (ft_strncmp("WE", line, 2) == 0)
			cub3d->config->xpm_files->west_count++;
		if (ft_strncmp("EA", line, 2) == 0)
			cub3d->config->xpm_files->east_count++;
		if (ft_strncmp("F", line, 1) == 0)
			cub3d->config->floor_color->count++;
		if (ft_strncmp("C", line, 1) == 0)
			cub3d->config->ceiling_color->count++;
		i++;
	}
}