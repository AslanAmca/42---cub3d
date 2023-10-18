/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_spaces.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 00:06:59 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/17 00:34:14 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static void	print_error_and_free(t_data *data, char **map)
{
	clear_double_pointer(map);
	print_error(data, "There is Space on the map \
that is not surrounded by walls. (1)");
}

static int	valid_char(char chr)
{
	if (chr == '1' || chr == ' ' || chr == '\0')
	{
		return (1);
	}
	return (0);
}

static void	validate_row_spaces(t_data *data, char **map, int last_row_index)
{
	int	row;
	int	col;

	row = 0;
	while (map[row] != NULL)
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			if (map[row][col] == ' ')
			{
				if (row == 0 && !valid_char(map[row + 1][col]))
					print_error_and_free(data, map);
				if (row == last_row_index && !valid_char(map[row - 1][col]))
					print_error_and_free(data, map);
				if (row > 0 && row < last_row_index
					&& (!valid_char(map[row - 1][col])
					|| !valid_char(map[row + 1][col])))
					print_error_and_free(data, map);
			}
			col++;
		}
		row++;
	}
}

static void	validate_col_spaces(t_data *data, char **map, int last_col_index)
{
	int	row;
	int	col;

	row = 0;
	while (map[row] != NULL)
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			if (map[row][col] == ' ')
			{
				if (col == 0 && !valid_char(map[row][col + 1]))
					print_error_and_free(data, map);
				if (col == last_col_index && !valid_char(map[row][col - 1]))
					print_error_and_free(data, map);
				if (col > 0 && col < last_col_index
					&& (!valid_char(map[row][col - 1])
					|| !valid_char(map[row][col + 1])))
					print_error_and_free(data, map);
			}
			col++;
		}
		row++;
	}
}

void	validate_map_spaces(t_data *data)
{
	char	**map;
	int		last_row_index;
	int		last_col_index;

	map = create_map_same_row_len(data);
	last_row_index = data->map->row_count - 1;
	last_col_index = data->map->col_count - 1;
	validate_row_spaces(data, map, last_row_index);
	validate_col_spaces(data, map, last_col_index);
	clear_double_pointer(map);
}
