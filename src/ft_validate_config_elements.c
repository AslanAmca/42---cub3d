/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_config_elements.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:53:10 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/10 18:07:22 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void ft_validate_identity_space(t_data *data)
{
	char *line;
	int i;

	line = NULL;
	i = 0;
	while (i < 6)
	{
		line = data->config->lines[i];
		if (data->texture->north == NULL && ft_strncmp("NO", line, 2) == 0 && line[2] != ' ')
			ft_print_error(data, "NO identifier must be followed by a space character.");
		if (data->texture->south == NULL && ft_strncmp("SO", line, 2) == 0 && line[2] != ' ')
			ft_print_error(data, "SO identifier must be followed by a space character.");
		if (data->texture->west == NULL && ft_strncmp("WE", line, 2) == 0 && line[2] != ' ')
			ft_print_error(data, "WE identifier must be followed by a space character.");
		if (data->texture->east == NULL && ft_strncmp("EA", line, 2) == 0 && line[2] != ' ')
			ft_print_error(data, "EA identifier must be followed by a space character.");
		if (data->floor_color->red == -1 && line[0] == 'F' && line[1] != ' ')
			ft_print_error(data, "F identifier must be followed by a space character.");
		if (data->ceiling_color->red == -1 && line[0] == 'C' && line[1] != ' ')
			ft_print_error(data, "C identifier must be followed by a space character.");
		i++;
	}
}

static void ft_handle_element_not_found(t_data *data)
{
	if (data->texture->north == NULL)
		ft_print_error(data, "NO identifier was not found or was not written in required format. Example of correct format: NO ./path.");
	if (data->texture->south == NULL)
		ft_print_error(data, "SO identifier was not found or was not written in required format. Example of correct format: SO ./path.");
	if (data->texture->west == NULL)
		ft_print_error(data, "WE identifier was not found or was not written in required format. Example of correct format: WE ./path.");
	if (data->texture->east == NULL)
		ft_print_error(data, "EA identifier was not found or was not written in required format. Example of correct format: EA ./path.");
	if (data->floor_color->red == -1)
		ft_print_error(data, "F identifier was not found or was not written in required format. Example of correct format: F 1,1,1");
	if (data->ceiling_color->red == -1)
		ft_print_error(data, "C identifier was not found or was not written in required format. Example of correct format: C 1,1,1");
}

void ft_validate_config_elements(t_data *data)
{
	char *line;
	int i;

	line = NULL;
	i = 0;
	while (i < 6) // 1.seviye
	{
		line = data->config->lines[i];
		ft_validate_textures(data, line);
		ft_validate_colors(data, line);
		i++;
	}

	// 1.seviye kontrolden sonra tüm elemanlar bulunduysa sorun yok.
	if (data->texture->north != NULL && data->texture->south != NULL
		&& data->texture->west != NULL && data->texture->east != NULL
		&& data->floor_color->red != -1 && data->ceiling_color->red != -1)
	{
		return;
	}

	// buraya kadar geldiyse 2 ihtimal var;
	// 1 - space sorunu var
	// 2 - dosyada elemanlar yok. (istediğimiz formatta yok)

	// space sorunu var mı diye bakacak olan fonksiyon
	ft_validate_identity_space(data);

	// space sorunu da yoksa o zaman elemanlar bulunamadı.
	// Ya hiç yok ya da formatları doğru değil.
	ft_handle_element_not_found(data);
}