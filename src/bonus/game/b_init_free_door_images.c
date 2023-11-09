/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_init_free_door_images.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 03:32:31 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/09 04:07:07 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_cub3d.h"

void	b_init_door0_image(t_cub3d *cub3d)
{
	int	size;

	size = 64;
	cub3d->game->door0_image = malloc(sizeof(t_mlx_image));
	if (cub3d->game->door0_image == NULL)
		b_print_error(cub3d, "door0_image malloc error.");
	cub3d->game->door0_image->img = mlx_xpm_file_to_image(cub3d->game->mlx,
			"./textures/door0.xpm", &size, &size);
	if (cub3d->game->door0_image->img == NULL)
		b_print_error(cub3d, "door0_image->img malloc error.");
	cub3d->game->door0_image->addr = mlx_get_data_addr(
			cub3d->game->door0_image->img,
			&cub3d->game->door0_image->bits_per_pixel,
			&cub3d->game->door0_image->size_line,
			&cub3d->game->door0_image->endian);
	if (cub3d->game->door0_image->addr == NULL)
		b_print_error(cub3d, "door0_image->addr malloc error.");
}

void	b_init_door1_image(t_cub3d *cub3d)
{
	int	size;

	size = 64;
	cub3d->game->door1_image = malloc(sizeof(t_mlx_image));
	if (cub3d->game->door1_image == NULL)
		b_print_error(cub3d, "door1_image malloc error.");
	cub3d->game->door1_image->img = mlx_xpm_file_to_image(cub3d->game->mlx,
			"./textures/door1.xpm", &size, &size);
	if (cub3d->game->door1_image->img == NULL)
		b_print_error(cub3d, "door1_image->img malloc error.");
	cub3d->game->door1_image->addr = mlx_get_data_addr(
			cub3d->game->door1_image->img,
			&cub3d->game->door1_image->bits_per_pixel,
			&cub3d->game->door1_image->size_line,
			&cub3d->game->door1_image->endian);
	if (cub3d->game->door1_image->addr == NULL)
		b_print_error(cub3d, "door1_image->addr malloc error.");
}

void	b_init_door2_image(t_cub3d *cub3d)
{
	int	size;

	size = 64;
	cub3d->game->door2_image = malloc(sizeof(t_mlx_image));
	if (cub3d->game->door2_image == NULL)
		b_print_error(cub3d, "door2_image malloc error.");
	cub3d->game->door2_image->img = mlx_xpm_file_to_image(cub3d->game->mlx,
			"./textures/door2.xpm", &size, &size);
	if (cub3d->game->door2_image->img == NULL)
		b_print_error(cub3d, "door2_image->img malloc error.");
	cub3d->game->door2_image->addr = mlx_get_data_addr(
			cub3d->game->door2_image->img,
			&cub3d->game->door2_image->bits_per_pixel,
			&cub3d->game->door2_image->size_line,
			&cub3d->game->door2_image->endian);
	if (cub3d->game->door2_image->addr == NULL)
		b_print_error(cub3d, "door2_image->addr malloc error.");
}

void	b_init_door3_image(t_cub3d *cub3d)
{
	int	size;

	size = 64;
	cub3d->game->door3_image = malloc(sizeof(t_mlx_image));
	if (cub3d->game->door3_image == NULL)
		b_print_error(cub3d, "door3_image malloc error.");
	cub3d->game->door3_image->img = mlx_xpm_file_to_image(cub3d->game->mlx,
			"./textures/door3.xpm", &size, &size);
	if (cub3d->game->door3_image->img == NULL)
		b_print_error(cub3d, "door3_image->img malloc error.");
	cub3d->game->door3_image->addr = mlx_get_data_addr(
			cub3d->game->door3_image->img,
			&cub3d->game->door3_image->bits_per_pixel,
			&cub3d->game->door3_image->size_line,
			&cub3d->game->door3_image->endian);
	if (cub3d->game->door3_image->addr == NULL)
		b_print_error(cub3d, "door3_image->addr malloc error.");
}

void	b_free_door_images(t_cub3d *cub3d)
{
	if (cub3d->game->door0_image != NULL)
	{
		if (cub3d->game->door0_image->img != NULL)
			mlx_destroy_image(cub3d->game->mlx, cub3d->game->door0_image->img);
		free(cub3d->game->door0_image);
	}
	if (cub3d->game->door1_image != NULL)
	{
		if (cub3d->game->door1_image->img != NULL)
			mlx_destroy_image(cub3d->game->mlx, cub3d->game->door1_image->img);
		free(cub3d->game->door1_image);
	}
	if (cub3d->game->door2_image != NULL)
	{
		if (cub3d->game->door2_image->img != NULL)
			mlx_destroy_image(cub3d->game->mlx, cub3d->game->door2_image->img);
		free(cub3d->game->door2_image);
	}
	if (cub3d->game->door3_image != NULL)
	{
		if (cub3d->game->door3_image->img != NULL)
			mlx_destroy_image(cub3d->game->mlx, cub3d->game->door3_image->img);
		free(cub3d->game->door3_image);
	}
}
