/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map_characters.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:33:22 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/14 12:29:14 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int ft_character_is_valid(char chr)
{
	if (chr != '0' && chr != '1' &&
		chr != 'N' && chr != 'S' && chr != 'W' && chr != 'E' &&
		chr != ' ')
	{
		return 0;
	}
	return 1;
}

static int ft_character_is_player(char chr)
{
	if (chr == 'N' || chr == 'S' || chr == 'W' || chr == 'E')
	{
		return 1;
	}
	return 0;
}

void ft_validate_map_characters(t_data *data)
{
	int player_count;
	int i;
	int j;

	player_count = 0;
	i = 6;
	while (data->config->lines[i] != NULL)
	{
		j = 0;
		while (data->config->lines[i][j] != '\0')
		{
			if (!ft_character_is_valid(data->config->lines[i][j]))
				ft_print_error(data, "Haritada sadece 0,1,N,S,W,E veya Space olabilir");
			if (ft_character_is_player(data->config->lines[i][j]))
				player_count++;
			if (player_count > 1)
				ft_print_error(data, "Harita da sadece 1 player olabilir.");
			j++;
		}
		i++;
	}
}
