/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_colors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:29:58 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/11 20:22:22 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void ft_validate_comma(t_data *data, char *string)
{
	int count;

	count = 0;
	while (*string != '\0')
	{
		if (*string == ',')
			count++;
		string++;
	}
	if (count != 2)
		ft_print_error(data, "The RGB (255,255,255) value must consist of 3 parts separated by commas.");
}
/*
F 220,100,0
C 225, 30, 0

Bakılması gerekenler:
1 - Daha önce bulundu mu? Burada NULL ile kontrol edemeyiz, red üzerinden - değilse diye bakabiliriz çünkü varsayılan değer -1
2 - Değeri trimleme işlemini burada da yapalım.
3 - Değer boş mu diye kontrol edelim.
4 - Değer virgül ile ayrılmış toplam 3 bölümden oluşmalıdır. Yani 2 virgül olmalıdır. Eğer yoksa 3 bölüm yoktur demektir.
5 - Değeri split ile bölmeliyiz. Her string'in karakter sayısına bakabiliriz. String boş olabilir veya karakter sayısı uyumsuz olabilir.
	Çünkü her string 1 veya 2 veya 3 karakterden oluşablir, (1 | 10 | 100) gibi tek haneli, çift haneli veya üç haneli olabilir. (0 - 255)
6 - 3 string'in de karakter sayısında problem yoksa, karakterler sayısal bir değer mi diye bakmalıyız (0-9).
7 - 3 string'in karakterleri sayısal olsa bile, 0-255 arasında olmalıdır, bunu kontrol etmeliyiz.
Tüm bu şartlardan geçiyorsa değerleri set edebiliriz.
-----> Peki Zemin ve Yerin renkleri birbirinden ayrı olmak zorunda mı? <-----
*/
static void ft_validate_floor_color(t_data *data, char *line)
{
	char *value;

	value = NULL;
	if (line[0] == 'F' && line[1] == ' ')
	{
		// 1
		if (data->floor_color->red >= 0)
			ft_print_error(data, "There can't be more than one F element.");

		// 2
		value = ft_strtrim(line + 2, " \t");

		// 3
		if (*value == '\0')
			ft_print_error(data, "F element cant' be empty.");

		// 4
		ft_validate_comma(data, value);

		// 5
		char **rgb = ft_split(value, ',');

		char *red = rgb[0];
		printf("F red len : %d\n", ft_strlen(red));
	}
}



void ft_validate_colors(t_data *data, char *line)
{
	ft_validate_floor_color(data, line);
}