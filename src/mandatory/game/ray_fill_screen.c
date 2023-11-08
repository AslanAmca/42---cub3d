/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_fill_screen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:07:10 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/08 10:07:29 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static t_mlx_image *get_wall_texture(t_ray *ray, t_game *game)
{
	t_mlx_image *wall_texture;
	t_player *player;

	player = game->player;
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

void ray_fill_screen(t_ray *ray, t_game *game, int x)
{
	// ekrana çizilecek duvar'ı al
	t_mlx_image *wall_texture = get_wall_texture(ray, game);

	int y = 0;
	while (y < SCREEN_HEIGHT)
	{
		// duvardan önceyse gökyüzünü çiz.
		if (y < ray->screen.wall_start_point)
		{
			put_pixel_to_mlx_image(game->screen, x, y, game->ceiling_rgb);
		}
		// duvardan sonraysa zemini çiz.
		else if (y > ray->screen.wall_end_point)
		{
			put_pixel_to_mlx_image(game->screen, x, y, game->floor_rgb);
		}
		else
		{
			// texture 64 bit olduğu için texture_start_point_y her zaman 0-63 arasında olmaldıır.
			// eğer 63'den daha büyük olursa, örneğin 66, bu durumda başa dönmeli ve 3. pikseli seçmelidir. (66 - 63)
			// bu güvenlik nedeniyle ne olur ne olmaz diye konulmuş bir kontroldür.
			double overflow_control_texture_start_point_y = (int)ray->screen.texture_start_point_y & (64 - 1);

			// texX diye geçen şey. Aslında texture'ın x düzlemi gibi bir şey.
			double texture_start_point_x = ray->screen.hit_point_in_wall_texture;

			// texture'ın istenen pikselinde ki rengi getir.
			int texture_pixel_color = get_pixel_color_from_texture(wall_texture, texture_start_point_x, overflow_control_texture_start_point_y);

			// ekranda ki koordinata duvar texture'nın rengini bas, yani pikseli bas.
			put_pixel_to_mlx_image(game->screen, x, y, texture_pixel_color);

			// bir sonra ki piksele geçerken texture'ın sonra ki pikseline geç.
			// ışığını sanalda ilerletirken aynı zamanda 2D map'te ilerletmek gibi.
			ray->screen.texture_start_point_y += ray->texture_pixel_for_one_pixel;
		}
		y++;
	}
}
