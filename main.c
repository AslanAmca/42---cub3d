/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakbulak <oakbulak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:38:43 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/03 16:08:47 by oakbulak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int on_destroy_handler(t_cub3d *cub3d)
{
	free_cub3d(cub3d);
	exit(EXIT_SUCCESS);
}

int on_keydown_handler(int key, t_cub3d *cub3d)
{
	if (key == KEY_ESC)
	{
		on_destroy_handler(cub3d);
	}
	return (0);
}

typedef struct s_ray
{
	// Işının 2d haritada ki hangi hücrede olduğunu temsil eden konumudur.
	// Gerçek konumu bu değildir çünkü ışık kutunun içerisinde herhangi bir bölgede olabilir, bu nedenle double bir sayı olacaktır.
	t_vector_int map_position;

	// Gerçek konumunu temsil eder, yani içinde bulunduğu hücrenin de neresinde olduğunu belirtir.
	t_vector_double real_position;

	// Ekran genişliğinde ki her bir dikey şerit için ışının yönünü temsil eder.
	// Bu yön, oyuncunun bakış yönü ve kameranın düzlemi kullanılarak hesaplanır.
	t_vector_double direction;

	// Işının gerçek konumundan en yakın x veya y tarafına çarpana kadar kat etmesi gereken mesafedir.
	t_vector_double initial_hit_distance;

	// Işın initial_hit_distance ile yakın ilk düzleme çarpar. Bu ilk çarpışmadan sonra gerçekleşecek her çapışmayı next_hit_distance temsil eder.
	// initial_hit_distance sadece bir kere gerçekleşen çarpmadır, geriye kalan her her çarpma sabit boyutludur ve next_hit_distance ile temsil edilir.
	// Yani bir sonra ki çarpma noktasına gitmek için kaç birim ilerlemesi gerektiğininin hesabıdır.
	t_vector_double next_hit_distance;

	// Işının 2D harita üzerinde atacağı bir sonra ki adımı temsil eder.
	// Işının yönüne bağlı olarak +1 veya -1 değerini alır.
	t_vector_int map_step;

	// Işın duvara çarptı mı? 0 (false) veya 1 (true) değerini alır.
	int hit_wall;

	// Işının bir duvarın x kenarına mı yoksa y kenarına mı çarptığını belirler. x veya y değerini alır.
	char hit_wall_side;

	//Işının öklit mesafesi
	int perpWallDist;

	// çizilecek duvarın uzunluğu,başlangıç ve bitiş pixelli
	int wallHeight;
	int startWall;
	int endWall;
} t_ray;

static t_ray init_ray(t_cub3d *cub3d)
{
	t_ray ray;
	t_player *player;

	player = cub3d->game->player;
	ray.map_position.x = (int)player->position.x;
	ray.map_position.y = (int)player->position.y;
	ray.real_position.x = player->position.x;
	ray.real_position.y = player->position.y;
	ray.hit_wall = 0;
	return (ray);
}

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
		// sağ tarafta özel bir durum var onu aşağıda açıkladık.
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

static void ray_direction_and_distances(t_ray *ray, t_player *player, int x)
{
	double normalized_camera_x;
	/*
		ekranın x koordinatları üzerindeki her dikey çizginin normalize olmuş halini temsil eder.
		Ekranın en sol tarafı -1, en sağ tarafı +1 ve tam ortası 0 değerini alır.
		Arada kalan şeritler de bulundukları yöne göre - veya + bir double değer alırlar.
		Normalizasyon işlemi her dikey çizginin yönünü belirler.
		*/
	normalized_camera_x = 2 * x / (double)1920 - 1;

	// Bu iki satır, her dikey şerit için bir ışının yönünü hesaplar.
	ray->direction.x = player->direction.x + player->camera_plane.x * normalized_camera_x;
	ray->direction.y = player->direction.y + player->camera_plane.y * normalized_camera_x;

	// Işın kendi yolunda ilerlerken bir sonra ki çarpma noktasına kadar ne kadar yol alacağını temsil eder.
	ray->next_hit_distance.x = fabs(1 / ray->direction.x);
	ray->next_hit_distance.y = fabs(1 / ray->direction.y);

	initial_hit_distance_and_step(ray);
}

static void ray_draw_until_hit_wall(t_ray *ray, t_map *map)
{
	// ışın duvara çarpmadığı sürece ışını ilerletmeye devam et.
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
		else if (map->text[ray->map_position.y][ray->map_position.x] == '1' /*|| map->text[ray->map_position.y][ray->map_position.x] == 'C'*/)
			ray->hit_wall = 1;
	}
}

static void ray_wall_size(t_ray *ray)
{
	//ışın x ekseninde mi veya y ekseninde mi duvara çarptı. Bu duruma göre çarptığı yer ile arasındaki öklit uzunluğu hesaplanıyor
	if (ray->hit_wall_side == 'x')
		ray->perpWallDist = ray->initial_hit_distance.x - ray->next_hit_distance.x;
	else
		ray->perpWallDist = ray->initial_hit_distance.y - ray->next_hit_distance.y;
	//Balık gözü olayını yapmak için her bir ışına denk gelen duvarın o pixelde ki duvar uzunluğu
	ray->wallHeight = WIN_HIGHT / ray->perpWallDist;
	//Ekrana basılacak duvarın başlangıç ve bitiş pixellerini buluyoruz
	ray->startWall = WIN_HIGHT / 2 - ray->wallHeight / 2;
	if (ray->startWall < 0)
		ray->startWall = 0;
	ray->endWall = WIN_HIGHT / 2 + ray->wallHeight / 2;
}

static void raycasting(t_cub3d *cub3d)
{
	t_ray ray;
	int x;

	ray = init_ray(cub3d);
	x = 0;

	// Ekranın her pikseli için bir hesaplama yapmak yerine, yalnızca her dikey şerit için bir hesaplama yapar. Bu, çok daha verimli bir yaklaşımdır.
	// Raycasting döngüsü bu şekilde her dikey şerit için çalışır ve her bir şerit için ışının başlangıç konumu ve yönü hesaplanır.
	while (x < 1920)
	{
		ray_direction_and_distances(&ray, cub3d->game->player, x);
		ray_draw_until_hit_wall(&ray, cub3d->config->map);
		ray_wall_size(&ray);
		x++;
	}
}

int main(int argc, char **argv)
{
	t_cub3d *cub3d;

	cub3d = init_cub3d(argc, argv[1]);
	validate_argument(cub3d);
	validate_config_is_non_empty(cub3d);
	set_config_line_count(cub3d);
	set_config_text(cub3d);
	validate_elements(cub3d);
	validate_map(cub3d);

	init_game(cub3d);

	// raycasting hesabı yapılmalı ve ekrana çizilmeli.

	mlx_hook(cub3d->game->mlx_window, ON_DESTROY, 0, on_destroy_handler, cub3d);
	mlx_hook(cub3d->game->mlx_window, ON_KEYDOWN, 1L << 0, on_keydown_handler, cub3d);
	mlx_loop(cub3d->game->mlx);
	raycasting(cub3d);

	return 0;
}
