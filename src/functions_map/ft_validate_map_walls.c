/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map_walls.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:03:12 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/16 00:18:11 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void ft_print_error_and_free(t_data *data, char *line)
{
	free(line);
	ft_print_error(data, "The map must be closed/surrounded by walls. (1)");
}

static void ft_dfs_algorithm(t_data *data, int row, int col)
{
	char **map;

	map = data->map->temp_text;
	if (row < 0 || row >= data->map->row_count ||
		col < 0 || col >= data->map->col_count)
	{
		ft_print_error(data, "The map must be closed/surrounded by walls. (1)");
	}
	if (map[row][col] == '1' || map[row][col] == '.')
		return;
	map[row][col] = '.';
	ft_dfs_algorithm(data, row, col + 1);
	ft_dfs_algorithm(data, row, col - 1);
	ft_dfs_algorithm(data, row + 1, col);
	ft_dfs_algorithm(data, row - 1, col);
}

static void ft_validate_map_border(t_data *data)
{
	char *line;
	int row;
	int col;

	row = 0;
	while (data->map->text[row] != NULL)
	{
		line = ft_strtrim(data->map->text[row], " ");
		col = 0;
		while (line[col] != '\0')
		{
			if ((row == 0 || row == data->map->row_count - 1) && line[col] == '0')
				ft_print_error_and_free(data, line);
			else if (line[0] == '0' || line[ft_strlen(line) - 1] == '0')
				ft_print_error_and_free(data, line);
			col++;
		}
		free(line);
		row++;
	}
}

void ft_validate_map_walls(t_data *data)
{
	data->map->temp_text = ft_create_map_temp_text(data);
	ft_dfs_algorithm(data, data->player->row, data->player->col);
	ft_validate_map_border(data);
}
