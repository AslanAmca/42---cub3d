/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_colors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:29:58 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/10 11:59:44 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void ft_validate_floor_color(t_data *data, char *line, int space)
{
	if (space == 1 && line[0] == 'F' && line[1] == ' ')
	{
		if (data->floor_color->blue)
			ft_print_error(data, "There can't be more than one F element.");
		data->texture->east = ft_strtrim(line + 3, " \t");
		if (data->texture->east[0] == '\0')
			ft_print_error(data, "Floor Color cant' be empty.");
		if (ft_strcmp(data->texture->east + ft_strlen(data->texture->east) - 4, ".xpm") != 0)
			ft_print_error(data, "Floor Color must end with the .xpm extension.");
	}
	if (space == 0 && line[0] == 'F' && line[1] != ' ')
	{
		ft_print_error(data, "The F identifier must be followed by a space character.");
	}
}

// F 220,100,0
// C 225, 30, 0

	void
	ft_validate_colors(t_data *data)
{
	char *line;
	int i;

	line = NULL;
	i = 0;
	while (i < 6)
	{
		line = data->config->lines[i];
		ft_validate_floor_color(data, line, 1);
		i++;
	}
}