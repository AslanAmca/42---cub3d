/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_wall_properties.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:01:49 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/08 10:02:07 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void ray_wall_properties(t_ray *ray, t_player *player)
{
	// Işın duvara çarptığına göre artık mesafeyi bulmalıyız, bu sayede duvarı doğru büyüklükte çizebileceğiz.
	// initial_hit_distance her adımda next_hit_distance kadar arttığı için son hali oyuncudan duvarın sonuna kadar olan uzaklıktır.
	// Duvarın sonuna kadardır çünkü duvarı geçtikten sonra çarpışmayı tespit edebiliyoruz.
	// Bu nedenle 1 adım geriye giderek duvarın başlangıcına dönmeliyiz.
	// Her adımda ilerlenen mesafe next_hit_distance ile temsil edildiği için toplam mesafeden 1 kere çıkarmak yeterlidir.
	if (ray->hit_wall_side == 'x')
		ray->wall_perpendicular_distance = ray->initial_hit_distance.x - ray->next_hit_distance.x;
	else
		ray->wall_perpendicular_distance = ray->initial_hit_distance.y - ray->next_hit_distance.y;

	// Duvara olan uzaklığı bulduk ancak bu uzaklığın ekranda da ne kadar yüksek olacağını, yani kaç piksel olacağını da bulmalıyız.
	ray->screen.wall_height = (long)(SCREEN_HEIGHT / ray->wall_perpendicular_distance);

	// Ekranda duvar tam ortada olmalıdır, duvar dışında gökyüzü ve zemin de olacak.
	// Bu nedenle duvarın ekranda ki başlangıç ve bitiş noktasını bulmamız gerekiyor.

	// Ekranın yarısına inmek aslında duvarın da yarısına inmek demektir çünkü duvar tam ortada duruyor.
	// Tam ortadan duvarın yüksekliğinin yarısı kadar yukarıya çıkarsak, duvarın başlangıcına gelmiş oluruz.
	ray->screen.wall_start_point = SCREEN_HEIGHT / 2 - ray->screen.wall_height / 2;

	// Tam ortadan duvarın yüksekliğinin yarısı kadar aşağıya inersek, duvarın sonuna gelmiş oluruz
	ray->screen.wall_end_point = SCREEN_HEIGHT / 2 + ray->screen.wall_height / 2;

	// Işının duvarın neresine çarptığını buluyoruz. (2D Haritada 1x1 boyutunda)
	if (ray->hit_wall_side == 'x')
		ray->hit_point_in_wall_square = player->position.y + ray->wall_perpendicular_distance * ray->direction.y;
	else
		ray->hit_point_in_wall_square = player->position.x + ray->wall_perpendicular_distance * ray->direction.x;
	ray->hit_point_in_wall_square -= floor(ray->hit_point_in_wall_square);

	// 1*1 boyutunda ışının nereye çarptığını bulmuştuk.
	// Burada gerçek texture boyutunda nereye çarptığını buluyoruz.
	ray->screen.hit_point_in_wall_texture = (int)(ray->hit_point_in_wall_square * (double)64);

	// Oyuncunun açısına göre texture'ın yanlış yerini görmemesi için ters çeviriyoruz.
	if (ray->hit_wall_side == 'x' && ray->direction.x > 0)
		ray->screen.hit_point_in_wall_texture = 64 - ray->screen.hit_point_in_wall_texture - 1;

	if (ray->hit_wall_side == 'y' && ray->direction.y < 0)
		ray->screen.hit_point_in_wall_texture = 64 - ray->screen.hit_point_in_wall_texture - 1;
}
