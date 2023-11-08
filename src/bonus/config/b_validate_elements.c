/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_elements.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:53:10 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/14 20:07:20 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_cub3d.h"

static void	check_unknown_element_type(t_cub3d *cub3d)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	while (i < 6)
	{
		line = cub3d->config->text[i];
		if (ft_strncmp("NO", line, 2) != 0 && ft_strncmp("SO", line, 2) != 0
			&& ft_strncmp("WE", line, 2) != 0 && ft_strncmp("EA", line, 2) != 0
			&& ft_strncmp("F", line, 1) != 0 && ft_strncmp("C", line, 1) != 0)
		{
			b_print_error(cub3d, "Only NO, SO, WE, EA, F and C element types \
			can be in the first 6 filled text.");
		}
		i++;
	}
}

static void	check_multiple_element_type(t_cub3d *cub3d)
{
	t_config	*config;

	config = cub3d->config;
	if (config->xpm_files->north_count > 1)
		b_print_error(cub3d, "NO element type cannot be more than 1.");
	if (config->xpm_files->south_count > 1)
		b_print_error(cub3d, "SO element type cannot be more than 1.");
	if (config->xpm_files->west_count > 1)
		b_print_error(cub3d, "WE element type cannot be more than 1.");
	if (config->xpm_files->east_count > 1)
		b_print_error(cub3d, "EA element type cannot be more than 1.");
	if (config->floor_color->count > 1)
		b_print_error(cub3d, "F element type cannot be more than 1.");
	if (config->ceiling_color->count > 1)
		b_print_error(cub3d, "C element type cannot be more than 1.");
}

static void	validate_different_xpm_files(t_cub3d *cub3d)
{
	t_config	*config;

	config = cub3d->config;
	if (ft_strcmp(config->xpm_files->north, config->xpm_files->south) == 0
		|| ft_strcmp(config->xpm_files->north, config->xpm_files->west) == 0
		|| ft_strcmp(config->xpm_files->north, config->xpm_files->east) == 0)
		b_print_error(cub3d, "NO texture can't be used for other textures.");
	if (ft_strcmp(config->xpm_files->south, config->xpm_files->north) == 0
		|| ft_strcmp(config->xpm_files->south, config->xpm_files->west) == 0
		|| ft_strcmp(config->xpm_files->south, config->xpm_files->east) == 0)
		b_print_error(cub3d, "SO texture can't be used for other textures.");
	if (ft_strcmp(config->xpm_files->west, config->xpm_files->north) == 0
		|| ft_strcmp(config->xpm_files->west, config->xpm_files->south) == 0
		|| ft_strcmp(config->xpm_files->west, config->xpm_files->east) == 0)
		b_print_error(cub3d, "WE texture can't be used for other textures.");
	if (ft_strcmp(config->xpm_files->east, config->xpm_files->south) == 0
		|| ft_strcmp(config->xpm_files->east, config->xpm_files->north) == 0
		|| ft_strcmp(config->xpm_files->east, config->xpm_files->west) == 0)
		b_print_error(cub3d, "EA texture can't be used for other textures.");
}

static void	validate_different_color(t_cub3d *cub3d)
{
	t_config	*config;

	config = cub3d->config;
	if (config->floor_color->red == config->ceiling_color->red
		&& config->floor_color->green == config->ceiling_color->green
		&& config->floor_color->blue == config->ceiling_color->blue)
	{
		b_print_error(cub3d, "Floor and ceiling color should not be the same.");
	}
}

void	b_validate_elements(t_cub3d *cub3d)
{
	char	*line;
	int		i;

	b_set_elements_count(cub3d);
	check_unknown_element_type(cub3d);
	check_multiple_element_type(cub3d);
	line = NULL;
	i = 0;
	while (i < 6)
	{
		line = cub3d->config->text[i];
		b_validate_xpm_files(cub3d, line);
		b_validate_floor_color(cub3d, line);
		b_validate_ceiling_color(cub3d, line);
		i++;
	}
	validate_different_xpm_files(cub3d);
	validate_different_color(cub3d);
}
