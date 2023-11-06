/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:38:43 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/06 16:55:49 by aaslan           ###   ########.fr       */
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

typedef struct s_screen
{
	int wall_height;
	int wall_start_point;
	int wall_end_point;
	int hit_point_in_wall_texture;
} t_screen;

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

	// Oyuncunun bulunduğu düzlemden duvara olan dik mesafedir.
	// Oyuncunun bulunduğu pozisyona göre hesap yapılmaz çünkü öklid uzaklığı nedeniyle balık gözü efekti oluşur.
	double wall_perpendicular_distance;

	// Bundan sonrası ekrana çizdirmek ile ilgili olduğu için screen adında bir struct içerisinde tutmak istedik.
	t_screen screen;

	// Işının 2D haritada duvar olan bir karenin hangi noktasına çarptığını temsil eder.
	// Burada duvar olan karenin başlangıcı 0, sonu 1'dir. Dolayısıyla 0-1 arası bir değer alır.
	// Bu oran ile duvarın ekranda gösterilecek pikseli hesaplanır.
	double hit_point_in_wall_square;
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

static void ray_direction_and_distances(t_ray *ray, t_player *player, int x)
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

	initial_hit_distance_and_step(ray);
}

static void ray_draw_until_hit_wall(t_ray *ray, t_map *map)
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
		else if (map->text[ray->map_position.y][ray->map_position.x] == '1')
			ray->hit_wall = 1;
	}
}

static void ray_wall_height_and_wall_points(t_ray *ray)
{
	// Işın duvara çarptığına göre artık mesafeyi bulmalıyız, bu sayede duvarı doğru büyüklükte çizebileceğiz.
	// initial_hit_distance her adımda next_hit_distance kadar arttığı için son hali oyuncudan duvarın sonuna kadar olan uzaklıktır.
	// Duvarın sonuna kadardır çünkü duvarı geçtikten sonra çarpışmayı tespit edebiliyoruz.
	// Bu nedenle 1 adım geriye giderek duvarın başlangıcına dönmeliyiz.
	// Her adımda ilerlenen mesafe next_hit_distance ile temsil edildiği için toplam mesafeden 1 kere çıkarmak yeterlidir.
	if (ray->hit_wall_side == 'x')
		ray->wall_perpendicular_distance = ray->initial_hit_distance.x - ray->next_hit_distance.x;
	else if (ray->hit_wall_side == 'y')
		ray->wall_perpendicular_distance = ray->initial_hit_distance.y - ray->next_hit_distance.y;

	// Duvara olan uzaklığı bulduk ancak bu uzaklığın ekranda da ne kadar yüksek olacağını, yani kaç piksel olacağını da bulmalıyız.
	ray->screen.wall_height = (int)(SCREEN_HEIGHT / ray->wall_perpendicular_distance);

	// Ekranda duvar tam ortada olmalıdır, duvar dışında gökyüzü ve zemin de olacak.
	// Bu nedenle duvarın ekranda ki başlangıç ve bitiş noktasını bulmamız gerekiyor.

	// Ekranın yarısına inmek aslında duvarın da yarısına inmek demektir çünkü duvar tam ortada duruyor.
	// Tam ortadan duvarın yüksekliğinin yarısı kadar yukarıya çıkarsak, duvarın başlangıcına gelmiş oluruz.
	ray->screen.wall_start_point = SCREEN_HEIGHT / 2 - ray->screen.wall_height / 2;

	// Ekrandan taşma durumunu kontrol etmekte fayda var.
	// Eğer wall_start_point negatifse, duvarın çizimi ekranın üstünden taşıyor demektir, bunu düzeltmeliyiz.
	if (ray->screen.wall_start_point < 0)
		ray->screen.wall_start_point = 0;

	// Tam ortadan duvarın yüksekliğinin yarısı kadar aşağıya inersek, duvarın sonuna gelmiş oluruz
	ray->screen.wall_end_point = SCREEN_HEIGHT / 2 + ray->screen.wall_height / 2;

	// Eğer wall_end_point ekran yükseliğine eşit veya büyükse, duvarın çizimi ekranın altından taşıyor demektir, bunu düzeltmeliyiz.
	// NOT : Index mantığına göre çalıştığımız için ekran yüksekliğine eşit olsa taşar.
	if (ray->screen.wall_end_point >= SCREEN_HEIGHT)
		ray->screen.wall_end_point = SCREEN_HEIGHT - 1;
}

static void ray_hit_point_in_wall_texture(t_ray *ray, t_player *player)
{
	// Işının duvarın neresine çarptığını buluyoruz. (2D Haritada 1x1 boyutunda)
	if (ray->hit_wall_side == 'x')
		ray->hit_point_in_wall_square = player->position.y + ray->wall_perpendicular_distance * ray->direction.y;
	else if (ray->hit_wall_side == 'y')
		ray->hit_point_in_wall_square = player->position.x + ray->wall_perpendicular_distance * ray->direction.x;
	ray->hit_point_in_wall_square -= floor(ray->hit_point_in_wall_square);

	// 1*1 boyutunda ışının nereye çarptığını bulmuştuk.
	// Burada gerçek texture boyutunda nereye çarptığını buluyoruz.
	ray->screen.hit_point_in_wall_texture = (int)(ray->hit_point_in_wall_square * 64.0);

	// Oyuncunun açısına göre texture'ın yanlış yerini görmemesi için ters çeviriyoruz.
	if (ray->hit_wall_side == 'x' && ray->direction.x > 0)
		ray->screen.hit_point_in_wall_texture = 64 - ray->screen.hit_point_in_wall_texture - 1;

	if (ray->hit_wall_side == 'y' && ray->direction.y < 0)
		ray->screen.hit_point_in_wall_texture = 64 - ray->screen.hit_point_in_wall_texture - 1;
}

static void raycasting(t_cub3d *cub3d)
{
	t_ray ray;
	int x;

	ray = init_ray(cub3d);
	x = 0;

	// Ekranın her pikseli için bir hesaplama yapmak yerine, yalnızca her dikey şerit için bir hesaplama yapar. Bu, çok daha verimli bir yaklaşımdır.
	// Raycasting döngüsü bu şekilde her dikey şerit için çalışır ve her bir şerit için ışının başlangıç konumu ve yönü hesaplanır.
	while (x < SCREEN_WIDTH)
	{
		ray_direction_and_distances(&ray, cub3d->game->player, x);
		ray_draw_until_hit_wall(&ray, cub3d->config->map);
		ray_wall_height_and_wall_points(&ray);
		ray_hit_point_in_wall_texture(&ray, cub3d->game->player);

		x++;
	}
}

static t_mlx_image *get_wall_texture(t_ray *ray, t_player *player, t_game *game)
{
	t_mlx_image *wall_texture;

	wall_texture = NULL;

	// Işının çarptığı duvarın düzlemine (x veya y) göre texture belirlenir.
	// Daha önce ki hesaplarda map_position duvara çarpana kadar ilerletilmişti.
	// Dolayısıyla burada ki map_position aslında 2D haritada duvarın konumudur.
	// Oyuncu duvarın hangi yönünü görüyorsa texture ona göre seçilir.
	if (ray->hit_wall_side == 'x')
	{
		// Duvarın x düzleminde ki pozisyonu oyuncunun x düzleminde ki pozisyonundan küçükse, duvar oyuncunun sol tarafında kalıyor demektir.
		// Sola doğru bakan oyuncu duvarın sağ tarafını görür, yani east olmalıdır.
		if (ray->map_position.x < player->position.x)
			wall_texture = game->east_image;
		else
			wall_texture = game->west_image;
	}
	else if (ray->hit_wall_side == 'y')
	{
		// Duvarın y düzleminde ki pozisyonu oyuncunun y düzleminde ki pozisyonundan küçükse, duvar oyuncunun üst tarafında kalıyor demektir.
		// Yukarıya doğru bakan oyuncu duvarın arkasını görür, yani south olmalıdır.
		if (ray->map_position.y < player->position.y)
			wall_texture = game->south_image;
		else
			wall_texture = game->north_image;
	}
	return (wall_texture);
}

/*
if (ray->side == 0)
	{
		// ray hit point in wall square
		// Işının 2d haritada ki duvar olan karenin neresini çarptığını temsil eder.
		// Burada duvar olan karenin başlangıcı 0, sonu 1'dir. wallX, 0-1 arası değer alarak ışının bu kare içerisinde hangi noktaya çarptığını gösterir.
		ray->draw.wallx = game->player->pos.y + ray->draw.perpwalldist * ray->raydir.y;
		if (ray->map.x < game->player->pos.x)
			ray->draw.wall = 3;
		else
			ray->draw.wall = 2;
	}
	else
	{
		ray->draw.wallx = game->player->pos.x + ray->draw.perpwalldist * ray->raydir.x;
		if (ray->map.y < game->player->pos.y)
			ray->draw.wall = 1;
		else
			ray->draw.wall = 0;
	}
	return (*ray);
*/

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
	raycasting(cub3d);

	mlx_hook(cub3d->game->mlx_window, ON_DESTROY, 0, on_destroy_handler, cub3d);
	mlx_hook(cub3d->game->mlx_window, ON_KEYDOWN, 1L << 0, on_keydown_handler, cub3d);
	mlx_loop(cub3d->game->mlx);

	return 0;
}
