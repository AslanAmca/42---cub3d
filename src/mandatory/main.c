/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:38:43 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/31 06:43:49 by aaslan           ###   ########.fr       */
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
	// konfigürasyon dosyasında bulunan 2d haritada ki hangi kutuda olduğunu temsil eden konumudur.
	// gerçek konumu bu değildir çünkü ışık kutunun içerisinde herhangi bir bölgede olabilir, bu nedenle double bir sayı olacaktır.
	t_vector_int map_position;

	// gerçek konumunu temsil eder.
	t_vector_double real_position;

	// her bir dikey çizgi için ışının yönünü temsil eder.
	// Bu yön, oyuncunun bakış yönü ve kameranın düzlemi kullanılarak hesaplanır.
	t_vector_double direction;

	// Işının gerçek konumundan en yakın x veya y tarafına çarpana kadar kat etmesi gereken mesafedir.
	// Genellikle içinde bulunduğu kare alanın sonuna veya başlangıcına çarpar. Haritada ki grid yapısını düşünebiliriz.
	t_vector_double distance_first_side;

	// Işının bir hücreden (grid) diğer hücreye geçmek için kat etmesi gereken mesafedir.
	// Düz mantık olarak 1 düşünülse de karmaşık ve çapraz giden ışınlarda daha farklı olur, hesaplanması gerekir.
	t_vector_double distance_per_square;
} t_ray;

int abs(int n)
{
	if (n < 0)
		return (n * -1);
	else
		return (n);
}

double abs_double(double n)
{
	if (n < 0)
		return (n * -1);
	else
		return (n);
}

static void raycasting(t_cub3d *cub3d)
{
	t_player *player;

	player = cub3d->game->player;


	// init ray
	t_ray ray;

	ray.map_position.x = (int)player->position.x;
	ray.map_position.y = (int)player->position.y;
	ray.real_position.x = player->position.x;
	ray.real_position.y = player->position.y;

	// Ekranın her pikseli için bir hesaplama yapmak yerine, yalnızca her dikey şerit için bir hesaplama yapar. Bu, çok daha verimli bir yaklaşımdır.
	// Raycasting döngüsü bu şekilde her dikey şerit için çalışır ve her bir şerit için ışının başlangıç konumu ve yönü hesaplanır.
	int x = 0;
	while (x < 1920)
	{
		/*
		ekranın x koordinatları üzerindeki her dikey çizginin normalize olmuş halini temsil eder.
		Ekranın en sol tarafı -1, en sağ tarafı +1 ve tam ortası 0 değerini alır. Arada kalan şeritler de bulundukları yöne göre - veya + bir double değer alırlar.
		Normalizasyon işlemi her dikey çizginin yönünü belirler.
		*/
		double normalized_camera_x = 2 * x / (double)1920 - 1;

		// Bu iki satır, her dikey şerit için bir ışının yönünü hesaplar.
		ray.direction.x = player->direction.x + player->camera_plane.x * normalized_camera_x;
		ray.direction.y = player->direction.y + player->camera_plane.y * normalized_camera_x;

		// Işının (ray) x ve y düzleminde ilerlemesi için her bir hücreyi geçerken ne kadar yol alacağını belirler.
		ray.distance_per_square.x = abs_double(1 / ray.direction.x);
		ray.distance_per_square.y = abs_double(1 / ray.direction.y);
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

	return 0;
}
