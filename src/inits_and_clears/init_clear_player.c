/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_clear_player.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:06:16 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/14 20:26:51 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void init_player(t_data *data)
{
	data->player = malloc(sizeof(t_color));
	if (data->player == NULL)
		print_error(data, "t_data->player malloc error.");
	data->player->count = 0;
	data->player->row = -1;
	data->player->col = -1;
}

void clear_player(t_data *data)
{
	if (data->player == NULL)
		return;
	free(data->player);
}
