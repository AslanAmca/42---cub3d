/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:00:52 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/09 15:07:01 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void ft_clear_map(char **map)
{
	int i;

	i = 0;
	if (map == NULL)
		return;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

void ft_clear_data(t_data *data)
{
	ft_clear_map(data->config_lines);
	free(data);
	data = NULL;
}
