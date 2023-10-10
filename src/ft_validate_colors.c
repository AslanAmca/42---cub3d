/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_colors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:29:58 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/10 18:05:46 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
F 220,100,0
C 225, 30, 0

Bakılması gerekenler:
1 - Daha önce bulundu mu? Burada NULL ile kontrol edemeyiz, red üzerinden - değilse diye bakabiliriz çünkü varsayılan değer -1
2 - Değeri trimleme işlemini burada da yapalım.
3 - Değer boş mu diye kontrol edelim.
4 - Değeri virgül karakteri üzerinden bölelim. Eğer elde ettiğimiz string sayısı 3 değilse RGB değerleri eksik veya fazladır. (R, G, B)
5 - 3 string elde edersek, her bir string'in karakter sayısına bakabiliriz. String boş olabilir veya karakter sayısı uyumsuz olabilir.
	Çünkü her string 1 veya 2 veya 3 karakterden oluşablir, (1 | 10 | 100) gibi tek haneli, çift haneli veya üç haneli olabilir. (0 - 255)
6 - 3 string'in de karakter sayısında problem yoksa, karakterler sayısal bir değer mi diye bakmalıyız (0-9).
7 - 3 string'in karakterleri sayısal olsa bile, 0-255 arasında olmalıdır, bunu kontrol etmeliyiz.
Tüm bu şartlardan geçiyorsa değerleri set edebiliriz.
*/
static void ft_validate_floor_color(t_data *data, char *line)
{
	if (line[0] == 'F' && line[1] == ' ')
	{
		if (data->floor_color->red >= 0)
			ft_print_error(data, "There can't be more than one F element.");
	}
}



void ft_validate_colors(t_data *data, char *line)
{
	ft_validate_floor_color(data, line);
}