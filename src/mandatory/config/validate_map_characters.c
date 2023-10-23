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

static void validate_player_position(t_cub3d *cub3d, int count, int row, int col)
{
	if (count < 1)
		print_error(cub3d, "There is no Player on the map. (N,S,W,E)");
	if (count > 1)
		print_error(cub3d, "There can only be 1 Player on the map. (N,S,W,E)");
	if (row == 0)
		print_error(cub3d, "Player can't be on the first row. (N,S,W,E)");
	if (row == cub3d->config->map->row_count - 1)
		print_error(cub3d, "Player can't be on the last row. (N,S,W,E)");
	if (col == 0)
		print_error(cub3d, "Player can't be on the first column. (N,S,W,E)");
	if (col == cub3d->config->map->col_count - 1)
		print_error(cub3d, "Player can't be on the last column. (N,S,W,E)");
}

void validate_map_characters(t_cub3d *cub3d)
{
	t_config *config;
	int player_count;
	int row;
	int col;

	config = cub3d->config;
	player_count = 0;
	row = 0;
	while (config->map->text[row] != NULL)
	{
		col = 0;
		while (config->map->text[row][col] != '\0')
		{
			if (!character_is_valid(config->map->text[row][col]))
				print_error(cub3d, "There can only be 0,1,N,S,W,E or Space on the map.");
			if (character_is_player(config->map->text[row][col]))
			{
				player_count++;
				validate_player_position(cub3d, player_count, row, col);
			}
			col++;
		}
		row++;
	}
}
