/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_draw_until_hit_wall.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:59:55 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/08 10:00:12 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void ray_draw_until_hit_wall(t_ray *ray, t_map *map)
{
	// Işın duvara çarpmadığı sürece ışını ilerletmeye devam et.
	// Işını x yönünde veya y yönünde sonraki harita karesine atlatıyoruz.
	while (ray->hit_wall == 0)
	{
		// initial_hit_distance.x, initial_hit_distance.y'den küçükse,
		// ışının yatay hareket etmesi gerektiği anlamına gelir ve ışın yatay hareket eder.
		if (ray->initial_hit_distance.x < ray->initial_hit_distance.y)
		{
			// Her adımda, ışın bir sonraki çarpışmaya kadar mesafe kat eder.
			// Bu mesafe yeni başlangıç konumu olsun diye initial_hit_distance değişkenine eklenir.
			ray->initial_hit_distance.x += ray->next_hit_distance.x;

			// Işını ekranda ilerletirken aynı zamanda 2D harita üzerinde de ilerletiyoruz.
			ray->map_position.x += ray->map_step.x;

			// Bu bölümde ışın yatay olarak hareket etti.
			// Dolayısıyla ışın duvara çarpmışsa, x düzleminde çarptı demektir.
			ray->hit_wall_side = 'x';
		}
		else
		{
			ray->initial_hit_distance.y += ray->next_hit_distance.y;
			ray->map_position.y += ray->map_step.y;
			ray->hit_wall_side = 'y';
		}

		// Işının harita sınırlarının dışına çıkıp çıkmadığını kontrol eder. Eğer ışın haritanın dışına çıkarsa döngüyü sonlandırır.
		// Haritanın etrafı duvarlar ile çevrili olacağı için bu gereksiz olaiblir.
		if (map->text[ray->map_position.y] == NULL)
			break;

		// Işının son çarptığı yeri 2D haritada kontrol et.
		// Eğer duvara veya kapıya çarptıysa işaretle ve döngüyü bitir.
		if (map->text[ray->map_position.y][ray->map_position.x] == '1')
			ray->hit_wall = 1;
	}
}
