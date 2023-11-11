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

#include "../b_cub3d.h"

static int	character_is_valid(char chr)
{
	if (chr != '0' && chr != '1'
		&& chr != 'N' && chr != 'S' && chr != 'W' && chr != 'E'
		&& chr != ' '
		&& chr != 'D')
	{
		return (0);
	}
	return (1);
}

static int	character_is_player(char chr)
{
	if (chr == 'N' || chr == 'S' || chr == 'W' || chr == 'E')
	{
		return (1);
	}
	return (0);
}

static void	validate_player_and_door(t_cub3d *cub3d)
{
	t_map	*map;

	map = cub3d->config->map;
	if (map->player_count < 1)
		b_print_error(cub3d, "There is no Player on the map. (N,S,W,E)");
	if (map->player_count > 1)
		b_print_error(cub3d, "There can only be 1 Player on \
the map. (N,S,W,E)");
	if (map->player_row == 0)
		b_print_error(cub3d, "Player can't be on the first row. (N,S,W,E)");
	if (map->player_row == map->row_count - 1)
		b_print_error(cub3d, "Player can't be on the last row. (N,S,W,E)");
	if (map->player_col == 0)
		b_print_error(cub3d, "Player can't be on the first column. (N,S,W,E)");
	if (map->player_col == map->col_count - 1)
		b_print_error(cub3d, "Player can't be on the last column. (N,S,W,E)");
	if (map->door_count < 1)
		b_print_error(cub3d, "There is no Door on the map. (D)");
}

static void	player_found_handler(t_map *map, int row, int col)
{
	map->player_count++;
	map->player_row = row;
	map->player_col = col;
}

void	b_validate_map_characters(t_cub3d *cub3d)
{
	t_map	*map;
	int		row;
	int		col;

	map = cub3d->config->map;
	row = 0;
	while (map->text[row] != NULL)
	{
		col = 0;
		while (map->text[row][col] != '\0')
		{
			if (!character_is_valid(map->text[row][col]))
				b_print_error(cub3d, "There can only be \
0, 1, N, S, W, E, D or Space on the map.");
			if (character_is_player(map->text[row][col]))
				player_found_handler(map, row, col);
			if (map->text[row][col] == 'D')
				map->door_count++;
			col++;
		}
		row++;
	}
	validate_player_and_door(cub3d);
}
