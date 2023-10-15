/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map_walls.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:03:12 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/15 15:12:22 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void ft_create_map_temp_text(t_data *data)
{
	int len;
	int i;

	len = data->map->row_count;
	data->map->temp_text = malloc(sizeof(char *) * (len + 1));
	if (data->map->temp_text == NULL)
		ft_print_error(data, "data->map->temp_text is null.");
	i = 0;
	while (data->map->text[i] != NULL)
	{
		data->map->temp_text[i] = malloc(data->map->col_count + 1);
		if (data->map->temp_text[i] == NULL)
			ft_print_error(data, "data->map->temp_text row is null.");
		ft_strncpy(data->map->temp_text[i], data->map->text[i], data->map->col_count);
		i++;
	}
	data->map->temp_text[i] = NULL;
}

static void ft_dfs_algorithm(t_data *data, int row, int col)
{
	char **temp_text;

	temp_text = data->map->temp_text;

	if (row < 0 || row >= data->map->row_count ||
		col < 0 || col >= data->map->col_count)
	{
		ft_print_error(data, "The map must be closed/surrounded by walls. (1)");
	}

	if (temp_text[row][col] == '1' || temp_text[row][col] == '.')
		return;

	temp_text[row][col] = '.';

	ft_dfs_algorithm(data, row, col + 1);
	ft_dfs_algorithm(data, row, col - 1);
	ft_dfs_algorithm(data, row + 1, col);
	ft_dfs_algorithm(data, row - 1, col);
}

static void ft_validate_map_border(t_data *data)
{
	char **map;
	int last_col;
	int last_row;
	int row;
	int col;

	map = data->map->temp_text;
	last_col = data->map->col_count - 1;
	row = 0;
	while (row < data->map->row_count)
	{
		if (map[row][0] == '0' || map[row][last_col] == '0')
			ft_print_error(data, "The map must be closed/surrounded by walls. (1)");
		row++;
	}
	last_row = data->map->row_count - 1;
	col = 0;
	while (col < data->map->col_count)
	{
		if (map[0][col] == '0' || map[last_row][col] == '0')
			ft_print_error(data, "The map must be closed/surrounded by walls. (1)");
		col++;
	}
}

void ft_validate_map_walls(t_data *data)
{
	ft_create_map_temp_text(data);

	ft_dfs_algorithm(data, data->player->row, data->player->col);

	// haritanın en uzun kolonuna göre çalıştığı için sadece son kolona bakıyor.
	// daha kısa satırın sonunda 0 olursa hata vermiyor çünkü haritaya göre son kolon değil.
	// illa bu özelliği uygulamak istiyorsak her satırın orjinal uzunluğuna göre yapabiliriz.
	ft_validate_map_border(data);
}
