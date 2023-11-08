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

void	validate_map(t_cub3d *cub3d)
{
	set_map_text(cub3d);
	check_map_empty_line(cub3d);
	validate_map_characters(cub3d);
	validate_map_walls(cub3d);
	validate_map_spaces(cub3d);
}
