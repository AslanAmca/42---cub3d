/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map_walls.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:03:12 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/14 20:38:36 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void ft_dfs_algorithm(t_data *data, int row, int col)
{
	char **temp_text;

	temp_text = data->map->temp_text;

	if (row == 0)
	{
		printf("row 0\n");
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

	len = data->config->full_line_count - 6;
	data->map->temp_text = malloc(sizeof(char *) * (len + 1));
	if (data->map->temp_text == NULL)
		ft_print_error(data, "data->map->temp_text is null.");
	i = 0;
	while (data->map->text[i] != NULL)
	{
		data->map->temp_text[i] = ft_strdup(data->map->text[i]);
		i++;
	}
	data->map->temp_text[i] = NULL;
}

// haritanın duvar durumunu ve harita içerisinde ki space durumunu kontrol etmeliyiz.

void ft_validate_map_walls(t_data *data)
{
	ft_create_map_temp_text(data);

	int i = 0;
	while (data->map->temp_text[i] != NULL)
	{
		printf("%s\n", data->map->temp_text[i]);
		i++;
	}

	// printf("dfs öncesine geliyor\n");

	// ft_dfs_algorithm(data, data->player->row, data->player->col);

	// printf("dfs sonrasına geliyor\n");
}
