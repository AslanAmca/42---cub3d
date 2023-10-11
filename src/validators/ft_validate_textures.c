/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_textures.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:26:26 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/11 20:22:09 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void ft_validate_north_texture(t_data *data, char *line)
{
	int fd;

	fd = -1;
	if (ft_strncmp("NO ", line, 3) == 0)
	{
		if (data->texture->north != NULL)
			ft_print_error(data, "There can't be more than one NO element.");
		data->texture->north = ft_strtrim_start(line + 3, " \t");

		printf("nort : %s\n", data->texture->north);

		if (data->texture->north[0] == '\0')
			ft_print_error(data, "NO element cant' be empty.");
		if (ft_strcmp(data->texture->north + ft_strlen(data->texture->north) - 4, ".xpm") != 0)
			ft_print_error(data, "NO element must end with the .xpm extension.");
		fd = open(data->texture->north, O_RDONLY);
		if (fd == -1)
			ft_print_error(data, "NO xpm file not found or can't be opened.");
		close(fd);
	}
}

static void ft_validate_south_texture(t_data *data, char *line)
{
	int fd;

	fd = -1;
	if (ft_strncmp("SO ", line, 3) == 0)
	{
		if (data->texture->south != NULL)
			ft_print_error(data, "There can't be more than one SO element.");
		data->texture->south = ft_strtrim(line + 3, " \t");
		if (data->texture->south[0] == '\0')
			ft_print_error(data, "SO element cant' be empty.");
		if (ft_strcmp(data->texture->south + ft_strlen(data->texture->south) - 4, ".xpm") != 0)
			ft_print_error(data, "SO element must end with the .xpm extension.");
		fd = open(data->texture->south, O_RDONLY);
		if (fd == -1)
			ft_print_error(data, "SO xpm file not found or can't be opened.");
		close(fd);
	}
}

static void ft_validate_west_texture(t_data *data, char *line)
{
	int fd;

	fd = -1;
	if (ft_strncmp("WE ", line, 3) == 0)
	{
		if (data->texture->west != NULL)
			ft_print_error(data, "There can't be more than one WE element.");
		data->texture->west = ft_strtrim(line + 3, " \t");
		if (data->texture->west[0] == '\0')
			ft_print_error(data, "WE element cant' be empty.");
		if (ft_strcmp(data->texture->west + ft_strlen(data->texture->west) - 4, ".xpm") != 0)
			ft_print_error(data, "WE element must end with the .xpm extension.");
		fd = open(data->texture->west, O_RDONLY);
		if (fd == -1)
			ft_print_error(data, "WE xpm file not found or can't be opened.");
		close(fd);
	}
}

static void ft_validate_east_texture(t_data *data, char *line)
{
	int fd;

	fd = -1;
	if (ft_strncmp("EA ", line, 3) == 0)
	{
		if (data->texture->east != NULL)
			ft_print_error(data, "There can't be more than one EA element.");
		data->texture->east = ft_strtrim(line + 3, " \t");
		if (data->texture->east[0] == '\0')
			ft_print_error(data, "EA element cant' be empty.");
		if (ft_strcmp(data->texture->east + ft_strlen(data->texture->east) - 4, ".xpm") != 0)
			ft_print_error(data, "EA element must end with the .xpm extension.");
		fd = open(data->texture->east, O_RDONLY);
		if (fd == -1)
			ft_print_error(data, "EA xpm file not found or can't be opened.");
		close(fd);
	}
}

/*
Validasyon yaparken önce her texture için seviye 1 kontrolü yapılmalı.
Yani 1 texture için her seviyeye aynı anda bakılmamalı. Önce tüm seviye 1 kontroller bitmeli ardından seviye 2'ye geçilmeli.
Çünkü seviye 1 için doğru girilmiş bir değer daha alt satırlarda olabilir. Bunu örnek ile daha iyi anlarız.

Örneğin NO değerini düşünelim. 3. satırda doğru bir NO değeri varsa fakat 1. satırda NOasdas şeklinde boşluksuz bir değer varsa
tüm seviyelere baktığımız senaryo da boşluk yok diye hata verecektir. Oysa 3. satırda doğru girilmiş hali vardı.
Bu nedenle tüm elemanlar için aynı seviyeye bakmak, daha sonra diğer seviyeye bakmak şeklinde ilerlemeliyiz.

Öncelikle her validasyon için bir seviye belirleyelim.
1. Seviye : ID ve space karakterinin girildiği, ilk 3 karakterin doğru olduğu seviye.
	- Texture daha önce set edilmiş mi? Yani NULL değilse demek ki tekrar ediyor ve hata verilmeli. Bunu en başta kontrol etmeliyiz.
	- Değer boş ise hata basmalıyız.
	- Değer varsa, bu değer .xpm uzantılı bir dosya olmalıdır çünkü texture formatı olarak xpm kullanıyoruz.
	- Burada belirtilen dosyanın gerçekten var olup olmadığını kontrol etmek gerekiyor mu?

2. Seviye : Eğer bu seviyeye geldiyse 2 ihtimal varıdr.
	1 - ID bulunmuştur ve validasyonları geçmiştir. Çünkü ID bulunmasına rağmen validasyonlar da sorun olsa program kapanacak.
	2 - ID bulunamamıştır, dolayısıyla validasyonlara hiç bakılmamıştır.

Hangi ihtimal yüzünden buraya geldiğini anlamak için texture değerine bakabiliriz.
	- Eğer texture NULL değilse demek ki 1. ihtmal gerçekleşti.
	- Eğer texture NULL ise demek ki ID bulunamadı.

3. Seviye : Eğer bu seviyeye geldiyse 3 ihtimal vardır.
	1 - Texture değeri NULL değilse ID bulunmuştur ve validasyonları geçmiştir, işlem tamam.
	2 - Texture değeri NULL ise ID değeri dosya da yok.
NOT : ID değerinin dosyada olması demek, satırda ki ilk 2 karakterin ID değerine eşit olması demektir.
*/
void ft_validate_textures(t_data *data, char *line)
{
	ft_validate_north_texture(data, line);
	ft_validate_south_texture(data, line);
	ft_validate_west_texture(data, line);
	ft_validate_east_texture(data, line);
}
