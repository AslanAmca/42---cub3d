/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map_walls.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:03:12 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/15 17:37:26 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char **ft_create_map_temp_text(t_data *data)
{
	char **map;
	int i;

	map = malloc(sizeof(char *) * (data->map->row_count + 1));
	if (map == NULL)
		ft_print_error(data, "ft_create_map_temp_text malloc error.");
	i = 0;
	while (data->map->text[i] != NULL)
	{
		map[i] = malloc(data->map->col_count + 1);
		if (map[i] == NULL)
		{
			ft_clear_double_pointer(map);
			ft_print_error(data, "ft_create_map_temp_text malloc error.");
		}
		ft_strncpy(map[i], data->map->text[i], data->map->col_count);
		i++;
	}
	map[i] = NULL;
	return (map);
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

static void ft_dfs_algorithm_for_space(t_data *data, int row, int col)
{
	char **map;

	map = data->map->temp_text2;

	if (map[row][col] == ' ')
		ft_print_error(data, "Space karakterine geldi.");

	if (map[row][col] == '1' || map[row][col] == '.')
		return;
	map[row][col] = '.';
	ft_dfs_algorithm_for_space(data, row, col + 1);
	ft_dfs_algorithm_for_space(data, row, col - 1);
	ft_dfs_algorithm_for_space(data, row + 1, col);
	ft_dfs_algorithm_for_space(data, row - 1, col);
}

static void ft_validate_map_border(t_data *data)
{
	char **map;
	char *message;
	int row;
	int col;
	int last_col;

	map = data->map->text;
	message = "The map must be closed/surrounded by walls. (1)";
	row = 0;
	while (map[row] != NULL)
	{
		last_col = ft_strlen(map[row]) - 1;
		col = 0;
		while (map[row][col] != '\0')
		{
			if ((row == 0 || row == data->map->row_count - 1) && map[row][col] == '0')
				ft_print_error(data, message);
			else if (map[row][0] == '0' || map[row][last_col] == '0')
				ft_print_error(data, message);
			col++;
		}
		row++;
	}
}

void ft_validate_map_walls(t_data *data)
{
	data->map->temp_text = ft_create_map_temp_text(data);
	ft_dfs_algorithm(data, data->player->row, data->player->col);

	ft_validate_map_border(data);

	// buraya geliyorsa duvarlarda bir problem yok demektir.
	// harita içerisinde ki space kontrolünü yapabiliriz.
	data->map->temp_text2 = ft_create_map_temp_text(data);

	// eğer player'ın ulaşabileceği bir space boştaysa hata veriyor.
	// ama duvarlar nedeniyle player o space'e gidemeyecekse, dfs algoritması o space'i görmediği için hata vermiyor.
	// böyle mi kalmalı yoksa başka bir şeyler mi düşünmeliyiz?
	ft_dfs_algorithm_for_space(data, data->player->row, data->player->col);
}
