/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_floor_color.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:29:58 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/12 10:22:26 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void ft_validate_comma(t_data *data, char *string)
{
	int count;

	count = 0;
	while (*string != '\0')
	{
		if (*string == ',')
			count++;
		string++;
	}
	if (count != 2)
		ft_print_error(data, "F take a value in RGB format. \
The RGB value consists of 3 parts separated by commas.");
}

static void ft_validate_red_color(t_data *data, char *red_string)
{
	int red;
	int red_len;
	int i;

	red_len = ft_strlen(red_string);
	if (red_len == 0)
		ft_print_error(data, "Red color of F can't be empty.");
	if (red_len > 3)
		ft_print_error(data, "Red color of F must be between 1-3 characters. (1 - 10 - 100).");
	i = 0;
	while (i < red_len)
	{
		if (!ft_is_digit(red_string[i]))
			ft_print_error(data, "Red color of F must consist of digit only. (0 - 9)");
		i++;
	}
	red = ft_atoi(red_string);
	if (red < 0 || red > 255)
		ft_print_error(data, "Red color of F must be a value between 0-255.");
	data->floor_color->red = red;
}

static void ft_validate_green_color(t_data *data, char *green_string)
{
	int green;
	int green_len;
	int i;

	green_len = ft_strlen(green_string);
	if (green_len == 0)
		ft_print_error(data, "Green color of F can't be empty.");
	if (green_len > 3)
		ft_print_error(data, "Green color of F must be between 1-3 characters. (1 - 10 - 100).");
	i = 0;
	while (i < green_len)
	{
		if (!ft_is_digit(green_string[i]))
			ft_print_error(data, "Green color of F must consist of digit only. (0 - 9)");
		i++;
	}
	green = ft_atoi(green_string);
	if (green < 0 || green > 255)
		ft_print_error(data, "Green color of F must be a value between 0-255.");
	data->floor_color->green = green;
}

static void ft_validate_blue_color(t_data *data, char *blue_string)
{
	int blue;
	int blue_len;
	int i;

	blue_len = ft_strlen(blue_string);
	if (blue_len == 0)
		ft_print_error(data, "Blue color of F can't be empty.");
	if (blue_len > 3)
		ft_print_error(data, "Blue color of F must be between 1-3 characters. (1 - 10 - 100).");
	i = 0;
	while (i < blue_len)
	{
		if (!ft_is_digit(blue_string[i]))
			ft_print_error(data, "Blue color of F must consist of digit only. (0 - 9)");
		i++;
	}
	blue = ft_atoi(blue_string);
	if (blue < 0 || blue > 255)
		ft_print_error(data, "Blue color of F must be a value between 0-255.");
	data->floor_color->blue = blue;
}

void ft_validate_floor_color(t_data *data, char *line)
{
	char **rgb;
	char *value;

	value = NULL;
	if (line[0] == 'F')
	{
		value = ft_strtrim_start(line + 1, " \t");
		if (*value == '\0')
			ft_print_error(data, "F element cant' be empty.");
		ft_validate_comma(data, value);
		rgb = ft_split(value, ',');
		ft_validate_red_color(data, rgb[0]);
		ft_validate_green_color(data, rgb[1]);
		ft_validate_blue_color(data, rgb[2]);
	}
}

// -----> Peki Zemin ve Yerin renkleri birbirinden ayrı olmak zorunda mı? <-----
void ft_validate_colors(t_data *data, char *line)
{
	ft_validate_floor_color(data, line);
	ft_validate_ceiling_color(data, line);
}