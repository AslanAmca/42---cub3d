/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_characters.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:33:22 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/15 15:03:22 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int character_is_valid(char chr)
{
	if (chr != '0' && chr != '1' &&
		chr != 'N' && chr != 'S' && chr != 'W' && chr != 'E' &&
		chr != ' ')
	{
		return 0;
	}
	return 1;
}

static int character_is_player(char chr)
{
	if (chr == 'N' || chr == 'S' || chr == 'W' || chr == 'E')
	{
		return 1;
	}
	return 0;
}

static void validate_player_position(t_data *data)
{
	if (data->player->count < 1)
		print_error(data, "There is no Player on the map. (N,S,W,E)");
	if (data->player->count > 1)
		print_error(data, "There can only be 1 Player on the map. (N,S,W,E)");
	if (data->player->row == 0)
		print_error(data, "Player can't be on the first row. (N,S,W,E)");
	if (data->player->row == data->map->row_count - 1)
		print_error(data, "Player can't be on the last row. (N,S,W,E)");
	if (data->player->col == 0)
		print_error(data, "Player can't be on the first column. (N,S,W,E)");
	if (data->player->col == data->map->col_count - 1)
		print_error(data, "Player can't be on the last column. (N,S,W,E)");
}

void validate_map_characters(t_data *data)
{
	int row;
	int col;

	row = 0;
	while (data->map->text[row] != NULL)
	{
		col = 0;
		while (data->map->text[row][col] != '\0')
		{
			if (!character_is_valid(data->map->text[row][col]))
				print_error(data, "There can only be 0,1,N,S,W,E or Space on the map.");
			if (character_is_player(data->map->text[row][col]))
			{
				data->player->count++;
				data->player->row = row;
				data->player->col = col;
			}
			col++;
		}
		row++;
	}
	validate_player_position(data);
}
