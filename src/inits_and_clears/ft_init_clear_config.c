/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_clear_config.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:19:06 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/14 20:26:34 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void ft_init_config(t_data *data)
{
	data->config = malloc(sizeof(t_config));
	if (data->config == NULL)
		ft_print_error(data, "t_data->config is null.");
	data->config->text = NULL;
	data->config->total_line_count = 0;
	data->config->full_line_count = 0;
	data->config->empty_line_count = 0;
}

void ft_clear_config(t_data *data)
{
	if (data->config == NULL)
		return;
	ft_clear_double_pointer(data->config->text);
	free(data->config);
}
