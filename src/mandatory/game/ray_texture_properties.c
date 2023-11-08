/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_texture_properties.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:05:36 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/08 10:05:54 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void ray_texture_properties(t_ray *ray)
{
	// Örneğin lineheight 128 olsun. Texture 64 piksel ekranda ki duvar 128 piksel.
	// 64 pikseli doğru bir şekilde 128 piksele dağıtmalıyız ki duvar düzgün gözüksün.
	// 1'e 1 dağıtım yaparsak, ekranın ilk 64 pikseli duvar olur ve son 64 pikseli boş kalır. Düzgün dağıtım yapmalıyız.
	// 64 / 128 = 0.5, yani texture'ın 0.5 pikseli duvarın 1 pikseline karşılık gelir.
	// duvarın her 1 pikseline texture'ın 0.5 yani yarım pikselini koyarsak 64 pikseli 128 piksele doğru bir şekilde dağıtmış oluruz.
	// böylelikle oran korunur ve ekranda düzgün bir duvar gözükür.
	// TANIM YAPMAMIZ GEREKİRSE AŞAĞIDAKİLERE BENZER BİR ŞEY DİYEBİLİRİZ :
	// Ekranda ki her 1 piksele texture'dan kaç piksel gelmeli.
	// Veya texture'dan kaç pikseli ekranda ki 1 piksele koyacağız?
	ray->texture_pixel_for_one_pixel = 1.0 * 64 / ray->screen.wall_height;

	ray->screen.texture_start_point_y = 0;

	// ekrandan taşma durumu var mı?
	if (ray->screen.wall_height > SCREEN_HEIGHT)
	{
		// ekranın üst tarafında kalan taşmayı hesapla.
		double overflow_pixel_on_top_screen = (ray->screen.wall_height - SCREEN_HEIGHT) / 2;

		// ekranın üst tarafında kalan taşmanın texture karşılığını hesapla.
		// texture'ın bu taşma sonrası noktasından çizdirmeye başlayacağız.
		// yami texture'ın başlangıç noktası diyebiliriz.
		ray->screen.texture_start_point_y = overflow_pixel_on_top_screen * ray->texture_pixel_for_one_pixel;

		// duvar taştığı için duvarın başlangıç ve bitiş pozisyonunu ayarla.
		ray->screen.wall_start_point = 0;
		ray->screen.wall_end_point = SCREEN_HEIGHT;
	}
}
