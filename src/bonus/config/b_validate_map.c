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

#include "../b_cub3d.h"

void	b_validate_map(t_cub3d *cub3d)
{
	b_set_map_text(cub3d);
	b_check_map_empty_line(cub3d);
	b_validate_map_characters(cub3d);
	b_validate_map_walls(cub3d);
	b_validate_map_spaces(cub3d);
}
