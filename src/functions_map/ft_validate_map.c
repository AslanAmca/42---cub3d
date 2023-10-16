/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 23:59:35 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/17 00:40:46 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void ft_validate_map(t_data *data, char *filename)
{
	ft_set_map_text(data);
	ft_check_map_empty_line(data, filename);
	ft_validate_map_characters(data);
	ft_validate_map_walls(data);
	ft_validate_map_spaces(data);
}
