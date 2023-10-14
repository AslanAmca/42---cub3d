/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_clear_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:05:16 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/14 20:26:41 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_data *ft_init_data(void)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		ft_print_error(data, "t_data is null.");
	ft_init_config(data);
	ft_init_textures(data);
	ft_init_colors(data);
	ft_init_map(data);
	ft_init_player(data);
	return data;
}

void ft_clear_data(t_data *data)
{
	ft_clear_config(data);
	ft_clear_textures(data);
	ft_clear_colors(data);
	ft_clear_map(data);
	ft_clear_player(data);
	free(data);
}
