/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_walls.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:03:12 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/16 23:55:02 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static void print_error_and_free(t_data *data, char *line)
{
	free(line);
	print_error(data, "The map must be closed/surrounded by walls. (1)");
}

static void validate_map_border(t_data *data)
{
	char *line;
	int last_row_index;
	int last_col_index;
	int row;
	int col;

	last_row_index = data->map->row_count - 1;
	row = 0;
	while (data->map->text[row] != NULL)
	{
		line = ft_strtrim(data->map->text[row], " ");
		last_col_index = ft_strlen(line) - 1;
		col = 0;
		while (line[col] != '\0')
		{
			if ((row == 0 || row == last_row_index) && line[col] == '0')
				print_error_and_free(data, line);
			else if (line[0] == '0' || line[last_col_index] == '0')
				print_error_and_free(data, line);
			col++;
		}
		free(line);
		row++;
	}
}

static void dfs_algorithm(t_data *data, char **map, int row, int col)
{
	if (row < 0 || row >= data->map->row_count ||
		col < 0 || col >= data->map->col_count)
	{
		clear_double_pointer(map);
		print_error(data, "The map must be closed/surrounded by walls. (1)");
	}
	if (map[row][col] == '1' || map[row][col] == '.')
		return;
	map[row][col] = '.';
	dfs_algorithm(data, map, row, col + 1);
	dfs_algorithm(data, map, row, col - 1);
	dfs_algorithm(data, map, row + 1, col);
	dfs_algorithm(data, map, row - 1, col);
}

void validate_map_walls(t_data *data)
{
	char **map;

	map = create_map_same_row_len(data);
	dfs_algorithm(data, map, data->player->row, data->player->col);
	clear_double_pointer(map);
	validate_map_border(data);
}
