/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_clear_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:23:19 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/18 20:45:06 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void init_game(t_data *data)
{
	data->game = malloc(sizeof(t_game));
	if (data->game == NULL)
		print_error(data, "t_data->game malloc error.");
	data->game->mlx = NULL;
	data->game->mlx_window = NULL;
}

void clear_game(t_data *data)
{
	if (data->game == NULL)
		return;
	if (data->game->mlx != NULL)
	{
		mlx_destroy_window(data->game->mlx, data->game->mlx_window);
		mlx_destroy_display(data->game->mlx); // linux'ta bu lazım diye hatırlıyorum.
		free(data->game->mlx);
	}
	free(data->game);
}
