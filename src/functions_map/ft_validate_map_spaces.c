/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map_spaces.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 23:55:11 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/15 23:56:36 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void ft_dfs_algorithm_for_space(t_data *data, int row, int col)
{
	char **map;

	map = data->map->temp_text2;
	if (row < 0 || row >= data->map->row_count ||
		col < 0 || col >= data->map->col_count)
	{
		ft_print_error(data, "The map must be closed/surrounded by walls. (1)");
	}
	if (map[row][col] == ' ')
	{
		ft_print_error(data, "There can't be any space in the player section \
that is not surrounded by walls. (1)");
	}
	if (map[row][col] == '1' || map[row][col] == '.')
		return;
	map[row][col] = '.';
	ft_dfs_algorithm_for_space(data, row, col + 1);
	ft_dfs_algorithm_for_space(data, row, col - 1);
	ft_dfs_algorithm_for_space(data, row + 1, col);
	ft_dfs_algorithm_for_space(data, row - 1, col);
}

void ft_validate_map_spaces(t_data *data)
{
	data->map->temp_text2 = ft_create_map_temp_text(data);
	ft_dfs_algorithm_for_space(data, data->player->row, data->player->col);
}
