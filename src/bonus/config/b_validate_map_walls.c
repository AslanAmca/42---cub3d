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

#include "../b_cub3d.h"

static void	error_and_free(t_cub3d *cub3d, char *line)
{
	free(line);
	b_print_error(cub3d, "The map must be closed/surrounded by walls. (1)");
}

static void	validate_map_border(t_cub3d *cub3d)
{
	char	*line;
	int		last_row_index;
	int		last_col_index;
	int		row;
	int		col;

	last_row_index = cub3d->config->map->row_count - 1;
	row = 0;
	while (cub3d->config->map->text[row] != NULL)
	{
		line = ft_strtrim(cub3d->config->map->text[row], " ");
		last_col_index = ft_strlen(line) - 1;
		col = 0;
		while (line[col] != '\0')
		{
			if ((row == 0 || row == last_row_index) && b_not_wall(line[col]))
				error_and_free(cub3d, line);
			else if (b_not_wall(line[0]) || b_not_wall(line[last_col_index]))
				error_and_free(cub3d, line);
			col++;
		}
		free(line);
		row++;
	}
}

static void	dfs_algorithm(t_cub3d *cub3d, char **map, int row, int col)
{
	if (row < 0 || row >= cub3d->config->map->row_count
		|| col < 0 || col >= cub3d->config->map->col_count)
	{
		free_double_pointer(map);
		b_print_error(cub3d, "The map must be closed/surrounded by walls. (1)");
	}
	if (map[row][col] == '1' || map[row][col] == '.')
		return ;
	map[row][col] = '.';
	dfs_algorithm(cub3d, map, row, col + 1);
	dfs_algorithm(cub3d, map, row, col - 1);
	dfs_algorithm(cub3d, map, row + 1, col);
	dfs_algorithm(cub3d, map, row - 1, col);
}

void	b_validate_map_walls(t_cub3d *cub3d)
{
	char	**map;
	int		player_row;
	int		player_col;

	map = b_create_map_same_row_len(cub3d);
	b_get_player_position(cub3d, &player_row, &player_col);
	dfs_algorithm(cub3d, map, player_row, player_col);
	free_double_pointer(map);
	validate_map_border(cub3d);
}
