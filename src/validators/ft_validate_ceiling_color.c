/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_ceiling_color.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:20:46 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/12 15:47:06 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void ft_validate_comma(t_data *data)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (data->ceiling_color->string[i] != '\0')
	{
		if (data->ceiling_color->string[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		ft_print_error(data, "C take a value in RGB format. \
The RGB value consists of 3 parts separated by 2 commas.");
}

static void ft_validate_red_color(t_data *data)
{
	char *red_string;
	int red;
	int red_len;
	int i;

	red_string = data->ceiling_color->red_string;
	red_len = ft_strlen(red_string);
	if (red_len == 0)
		ft_print_error(data, "Red color of C can't be empty.");
	if (red_len > 3)
		ft_print_error(data, "Red color of C must be between 1-3 characters. (1 - 10 - 100).");
	i = 0;
	while (i < red_len)
	{
		if (!ft_is_digit(red_string[i]))
			ft_print_error(data, "Red color of C must consist of digit only. (0 - 9)");
		i++;
	}
	red = ft_atoi(red_string);
	if (red < 0 || red > 255)
		ft_print_error(data, "Red color of C must be a value between 0-255.");
	data->ceiling_color->red = red;
}

static void ft_validate_green_color(t_data *data)
{
	char *green_string;
	int green;
	int green_len;
	int i;

	green_string = data->ceiling_color->green_string;
	green_len = ft_strlen(green_string);
	if (green_len == 0)
		ft_print_error(data, "Green color of C can't be empty.");
	if (green_len > 3)
		ft_print_error(data, "Green color of C must be between 1-3 characters. (1 - 10 - 100).");
	i = 0;
	while (i < green_len)
	{
		if (!ft_is_digit(green_string[i]))
			ft_print_error(data, "Green color of C must consist of digit only. (0 - 9)");
		i++;
	}
	green = ft_atoi(green_string);
	if (green < 0 || green > 255)
		ft_print_error(data, "Green color of C must be a value between 0-255.");
	data->ceiling_color->green = green;
}

static void ft_validate_blue_color(t_data *data)
{
	char *blue_string;
	int blue;
	int blue_len;
	int i;

	blue_string = data->ceiling_color->blue_string;
	blue_len = ft_strlen(blue_string);
	if (blue_len == 0)
		ft_print_error(data, "Blue color of C can't be empty.");
	if (blue_len > 3)
		ft_print_error(data, "Blue color of C must be between 1-3 characters. (1 - 10 - 100).");
	i = 0;
	while (i < blue_len)
	{
		if (!ft_is_digit(blue_string[i]))
			ft_print_error(data, "Blue color of C must consist of digit only. (0 - 9)");
		i++;
	}
	blue = ft_atoi(blue_string);
	if (blue < 0 || blue > 255)
		ft_print_error(data, "Blue color of C must be a value between 0-255.");
	data->ceiling_color->blue = blue;
}

void ft_validate_ceiling_color(t_data *data, char *line)
{
	char **rgb;

	rgb = NULL;
	if (line[0] == 'F')
	{
		data->ceiling_color->string = ft_strtrim_start(line + 1, " \t");
		if (*data->ceiling_color->string == '\0')
			ft_print_error(data, "C element cant' be empty.");
		ft_validate_comma(data);
		rgb = ft_split(data->ceiling_color->string, ',');
		data->ceiling_color->red_string = ft_strdup(rgb[0]);
		data->ceiling_color->green_string = ft_strdup(rgb[1]);
		data->ceiling_color->blue_string = ft_strdup(rgb[2]);
		ft_clear_double_pointer(rgb);
		ft_validate_red_color(data);
		ft_validate_green_color(data);
		ft_validate_blue_color(data);
	}
}
