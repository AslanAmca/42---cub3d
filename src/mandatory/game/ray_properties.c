/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_properties.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:54:48 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/08 09:55:12 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void initial_hit_distance_and_step(t_ray *ray)
{
	// Işın yönünün x bileşeni negatifse, yani ışın sola doğru gidiyorsa, ray.map_step.x değişkeni -1 olarak ayarlanır.
	if (ray->direction.x < 0)
	{
		// haritada x ekseninde sola gidecek.
		ray->map_step.x = -1;

		// parantez içinde ki hesaba inceleyelim ;
		// diyelim ki map.x 2 yani ışık 2. kutuda ancak pos.x küsüratıda verdiği için 2.5 olsun yani kutunun tam ortasında.
		// bu aşamada ışın sol tarafa gitmeli, bu nedenle map.x'in en başına gitmeli, burası aynı zamanda bir önceki kutunun sonu oluyor.
		// bu nedenle pos.x'den map.x'i çıkartarak sol tarafa ne kadar mesafe olduğunu direk buluyoruz.
		// Bulunan mesafe dik mesafedir, bize ışın yönünde yatay mesafe lazım, yani öklid uzaklığı lazım.
		// Bu nedenle next_hit_distance ile çarpıyoruz.
		ray->initial_hit_distance.x = (ray->real_position.x - ray->map_position.x) * ray->next_hit_distance.x;
	}
	/*
	ışının x bileşeni pozitifse, yani sağa doğru gidiyorsa, ray.map_step.x değişkeni 1 olarak ayarlanır.
	ray.initial_hit_distance.x hesaplaması, ışının bir sonraki hücreye gitme mesafesini hesaplar.
	Bu hesaplamalar, ışının yatay duvarlara olan mesafesini hesaplamak için kullanılır.
	*/
	else
	{
		// haritada x ekseninde sağa gidecek.
		ray->map_step.x = 1;

		// parantez içinde ki hesaba inceleyelim ;
		// diyelim ki map.x 2 yani ışık 2. kutuda ancak pos.x küsüratıda verdiği için 2.5 olsun yani kutunun tam ortasında.
		// bu aşamada ışın sağ tarafa gitmeli, bu nedenle map.x olan kutuya değil bir sonra ki kutuya değmeli,
		// bu nedenle map.x + 1 yapıp bir sonraki kutuya gidiyoruz,
		// daha sonra mevcut pos.x'den çıkararak bir sonra ki kutuya ne kadar mesafe kaldığıı buluyoruz.
		ray->initial_hit_distance.x = (ray->map_position.x + 1.0 - ray->real_position.x) * ray->next_hit_distance.x;
	}

	/*
	Eğer ray.direction.y negatifse, yani yukarı doğru gidiyorsa, ray.map_step.y -1 olarak ayarlanır ve ray.initial_hit_distance.y hesaplaması yapılır.
	Eğer ray.direction.y pozitifse, yani aşağı doğru gidiyorsa, ray.map_step.y 1 olarak ayarlanır ve ray.initial_hit_distance.y hesaplaması yapılır.
	*/
	if (ray->direction.y < 0)
	{
		// haritada y ekseninde yukarı gidecek.
		ray->map_step.y = -1;
		ray->initial_hit_distance.y = (ray->real_position.y - ray->map_position.y) * ray->next_hit_distance.y;
	}
	else
	{
		// haritada y ekseninde aşağı gidecek.
		ray->map_step.y = 1;
		ray->initial_hit_distance.y = (ray->map_position.y + 1.0 - ray->real_position.y) * ray->next_hit_distance.y;
	}
}

void ray_properties(t_ray *ray, t_player *player, int x)
{
	double normalized_camera_x;
	/*
		ekranın x koordinatları üzerindeki her dikey çizginin normalize olmuş halini temsil eder.
		Ekranın en sol tarafı -1, en sağ tarafı +1 ve tam ortası 0 değerini alır.
		Arada kalan şeritler de bulundukları yöne göre - veya + bir double değer alırlar.
		Normalizasyon işlemi her dikey çizginin yönünü belirler.
		*/
	normalized_camera_x = 2 * x / (double)SCREEN_WIDTH - 1;

	// Bu iki satır, her dikey şerit için bir ışının yönünü hesaplar.
	ray->direction.x = player->direction.x + player->camera_plane.x * normalized_camera_x;
	ray->direction.y = player->direction.y + player->camera_plane.y * normalized_camera_x;

	// Işın kendi yolunda ilerlerken bir sonra ki çarpma noktasına kadar ne kadar yol alacağını temsil eder.
	ray->next_hit_distance.x = fabs(1 / ray->direction.x);
	ray->next_hit_distance.y = fabs(1 / ray->direction.y);

	// bu değerler her döngüde resetlenmeli, bu nedenle burada hesaplanması uygun.
	ray->map_position.x = (int)player->position.x;
	ray->map_position.y = (int)player->position.y;
	ray->hit_wall = 0;

	initial_hit_distance_and_step(ray);
}
