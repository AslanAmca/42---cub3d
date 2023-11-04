/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 04:13:28 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/04 05:20:53 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

size_t get_mlx_image_color(t_mlx_image *image, int x, int y)
{
	return (*(size_t *)((image->addr + (y * image->size_line) + (x * image->bits_per_pixel / 8))));
}

void put_pixel_to_mlx_image(t_mlx_image *image, int x, int y, int color)
{
	char *dst;

	if (x < 0 || x > SCREEN_WIDTH)
		return;
	if (y < 0 || y > SCREEN_HEIGHT)
		return;
	if (image->addr == NULL)
		return;
	dst = image->addr + (y * image->size_line + x * (image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

