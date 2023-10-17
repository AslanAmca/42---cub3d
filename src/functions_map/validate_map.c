/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 23:59:35 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/17 00:40:46 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void validate_map(t_data *data, char *filename)
{
	set_map_text(data);
	check_map_empty_line(data, filename);
	validate_map_characters(data);
	validate_map_walls(data);
	validate_map_spaces(data);
}
