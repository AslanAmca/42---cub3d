/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map_characters.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:33:22 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/14 20:32:13 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int ft_character_is_valid(char chr)
{
	if (chr != '0' && chr != '1' &&
		chr != 'N' && chr != 'S' && chr != 'W' && chr != 'E' &&
		chr != ' ')
	{
		return 0;
	}
	return 1;
}

static int ft_character_is_player(char chr)
{
	if (chr == 'N' || chr == 'S' || chr == 'W' || chr == 'E')
	{
		return 1;
	}
	return 0;
}

void ft_validate_map_characters(t_data *data)
{
	int row;
	int col;

	row = 0;
	while (data->map->text[row] != NULL)
	{
		col = 0;
		while (data->map->text[row][col] != '\0')
		{
			if (!ft_character_is_valid(data->map->text[row][col]))
				ft_print_error(data, "There can only be 0,1,N,S,W,E or Space on the map.");
			if (ft_character_is_player(data->map->text[row][col]))
			{
				data->player->count++;
				data->player->row = row;
				data->player->col = col;
			}
			col++;
		}
		row++;
	}
	if (data->player->count < 1)
		ft_print_error(data, "There is no Player on the map. (N,S,W,E)");
	if (data->player->count > 1)
		ft_print_error(data, "There can only be 1 Player on the map. (N,S,W,E)");
}
