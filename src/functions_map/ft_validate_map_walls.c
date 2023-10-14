/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map_walls.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:03:12 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/15 02:45:47 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void ft_dfs_algorithm(t_data *data, int row, int col)
{
	char **temp_text;

	temp_text = data->map->temp_text;

	if (row < 0 || row >= data->map->row_count ||
		col < 0 || temp_text[row][col] == '\0')
	{
		ft_print_error(data, "zort");
	}

	if (temp_text[row][col] == '1' || temp_text[row][col] == '.')
		return;

	temp_text[row][col] = '.';

	ft_dfs_algorithm(data, row, col + 1);
	ft_dfs_algorithm(data, row, col - 1);
	ft_dfs_algorithm(data, row + 1, col);
	ft_dfs_algorithm(data, row - 1, col);
}

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
		data->map->temp_text[i] = malloc(data->map->col_count + 1); // +1'e gerek var mı?

		if (data->map->temp_text[i] == NULL)
			ft_print_error(data, "data->map->temp_text row is null.");

		ft_strncpy(data->map->temp_text[i], data->map->text[i], data->map->col_count); // burada n için verilen değer doğru mu?

		i++;
	}
	data->map->temp_text[i] = NULL;
}

// haritanın duvar durumunu ve harita içerisinde ki space durumunu kontrol etmeliyiz.

void ft_validate_map_walls(t_data *data)
{
	ft_create_map_temp_text(data);

	ft_dfs_algorithm(data, data->player->row, data->player->col);
}
