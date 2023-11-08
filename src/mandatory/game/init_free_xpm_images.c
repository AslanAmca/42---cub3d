/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_xpm_images.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 02:26:23 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/08 10:58:47 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_north_mlx_image(t_cub3d *cub3d)
{
	int	size;

	size = 64;
	cub3d->game->north_image = malloc(sizeof(t_mlx_image));
	if (cub3d->game->north_image == NULL)
		print_error(cub3d, "north_image malloc error.");
	cub3d->game->north_image->img = mlx_xpm_file_to_image(cub3d->game->mlx,
			cub3d->config->xpm_files->north, &size, &size);
	if (cub3d->game->north_image->img == NULL)
		print_error(cub3d, "north_image->img malloc error.");
	cub3d->game->north_image->addr = mlx_get_data_addr(
			cub3d->game->north_image->img,
			&cub3d->game->north_image->bits_per_pixel,
			&cub3d->game->north_image->size_line,
			&cub3d->game->north_image->endian);
	if (cub3d->game->north_image->addr == NULL)
		print_error(cub3d, "north_image->addr malloc error.");
}

void	init_south_mlx_image(t_cub3d *cub3d)
{
	int	size;

	size = 64;
	cub3d->game->south_image = malloc(sizeof(t_mlx_image));
	if (cub3d->game->south_image == NULL)
		print_error(cub3d, "south_image malloc error.");
	cub3d->game->south_image->img = mlx_xpm_file_to_image(cub3d->game->mlx,
			cub3d->config->xpm_files->south, &size, &size);
	if (cub3d->game->south_image->img == NULL)
		print_error(cub3d, "south_image->img malloc error.");
	cub3d->game->south_image->addr = mlx_get_data_addr(
			cub3d->game->south_image->img,
			&cub3d->game->south_image->bits_per_pixel,
			&cub3d->game->south_image->size_line,
			&cub3d->game->south_image->endian);
	if (cub3d->game->south_image->addr == NULL)
		print_error(cub3d, "south_image->addr malloc error.");
}

void	init_west_mlx_image(t_cub3d *cub3d)
{
	int	size;

	size = 64;
	cub3d->game->west_image = malloc(sizeof(t_mlx_image));
	if (cub3d->game->west_image == NULL)
		print_error(cub3d, "west_image malloc error.");
	cub3d->game->west_image->img = mlx_xpm_file_to_image(cub3d->game->mlx,
			cub3d->config->xpm_files->west, &size, &size);
	if (cub3d->game->west_image->img == NULL)
		print_error(cub3d, "west_image->img malloc error.");
	cub3d->game->west_image->addr = mlx_get_data_addr(
			cub3d->game->west_image->img,
			&cub3d->game->west_image->bits_per_pixel,
			&cub3d->game->west_image->size_line,
			&cub3d->game->west_image->endian);
	if (cub3d->game->west_image->addr == NULL)
		print_error(cub3d, "west_image->addr malloc error.");
}

void	init_east_mlx_image(t_cub3d *cub3d)
{
	int	size;

	size = 64;
	cub3d->game->east_image = malloc(sizeof(t_mlx_image));
	if (cub3d->game->east_image == NULL)
		print_error(cub3d, "east_image malloc error.");
	cub3d->game->east_image->img = mlx_xpm_file_to_image(cub3d->game->mlx,
			cub3d->config->xpm_files->east, &size, &size);
	if (cub3d->game->east_image->img == NULL)
		print_error(cub3d, "east_image->img malloc error.");
	cub3d->game->east_image->addr = mlx_get_data_addr(
			cub3d->game->east_image->img,
			&cub3d->game->east_image->bits_per_pixel,
			&cub3d->game->east_image->size_line,
			&cub3d->game->east_image->endian);
	if (cub3d->game->east_image->addr == NULL)
		print_error(cub3d, "east_image->addr malloc error.");
}

void	free_xpm_images(t_cub3d *cub3d)
{
	if (cub3d->game->north_image != NULL)
	{
		if (cub3d->game->north_image->img != NULL)
			mlx_destroy_image(cub3d->game->mlx, cub3d->game->north_image->img);
		free(cub3d->game->north_image);
	}
	if (cub3d->game->south_image != NULL)
	{
		if (cub3d->game->south_image->img != NULL)
			mlx_destroy_image(cub3d->game->mlx, cub3d->game->south_image->img);
		free(cub3d->game->south_image);
	}
	if (cub3d->game->west_image != NULL)
	{
		if (cub3d->game->west_image->img != NULL)
			mlx_destroy_image(cub3d->game->mlx, cub3d->game->west_image->img);
		free(cub3d->game->west_image);
	}
	if (cub3d->game->east_image != NULL)
	{
		if (cub3d->game->east_image->img != NULL)
			mlx_destroy_image(cub3d->game->mlx, cub3d->game->east_image->img);
		free(cub3d->game->east_image);
	}
}
