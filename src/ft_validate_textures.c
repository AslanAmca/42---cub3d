/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_textures.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:26:26 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/10 13:12:28 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void ft_validate_north_texture(t_data *data, char *line, int space)
{
	if (space == 1 && ft_strncmp("NO ", line, 3) == 0)
	{
		if (data->texture->north != NULL)
			ft_print_error(data, "There can't be more than one NO element.");
		data->texture->north = ft_strtrim(line + 3, " \t");
		if (data->texture->north[0] == '\0')
			ft_print_error(data, "North Texture cant' be empty.");
		if (ft_strcmp(data->texture->north + ft_strlen(data->texture->north) - 4, ".xpm") != 0)
			ft_print_error(data, "North Texture must end with the .xpm extension.");
	}
	if (space == 0 && ft_strncmp("NO", line, 2) == 0 && line[2] != ' ')
	{
		ft_print_error(data, "The NO identifier must be followed by a space character.");
	}
}

static void ft_validate_south_texture(t_data *data, char *line, int space)
{
	if (space == 1 && ft_strncmp("SO ", line, 3) == 0)
	{
		if (data->texture->south != NULL)
			ft_print_error(data, "There can't be more than one SO element.");
		data->texture->south = ft_strtrim(line + 3, " \t");
		if (data->texture->south[0] == '\0')
			ft_print_error(data, "South Texture cant' be empty.");
		if (ft_strcmp(data->texture->south + ft_strlen(data->texture->south) - 4, ".xpm") != 0)
			ft_print_error(data, "South Texture must end with the .xpm extension.");
	}
	if (space == 0 && ft_strncmp("SO", line, 2) == 0 && line[2] != ' ')
	{
		ft_print_error(data, "The SO identifier must be followed by a space character.");
	}
}

static void ft_validate_west_texture(t_data *data, char *line, int space)
{
	if (space == 1 && ft_strncmp("WE ", line, 3) == 0)
	{
		if (data->texture->west != NULL)
			ft_print_error(data, "There can't be more than one WE element.");
		data->texture->west = ft_strtrim(line + 3, " \t");
		if (data->texture->west[0] == '\0')
			ft_print_error(data, "West Texture cant' be empty.");
		if (ft_strcmp(data->texture->west + ft_strlen(data->texture->west) - 4, ".xpm") != 0)
			ft_print_error(data, "West Texture must end with the .xpm extension.");
	}
	if (space == 0 && ft_strncmp("WE", line, 2) == 0 && line[2] != ' ')
	{
		ft_print_error(data, "The WE identifier must be followed by a space character.");
	}
}

static void ft_validate_east_texture(t_data *data, char *line, int space)
{
	int fd;

	fd = -1;
	if (space == 1 && ft_strncmp("EA ", line, 3) == 0)
	{
		if (data->texture->east != NULL)
			ft_print_error(data, "There can't be more than one EA element.");

		data->texture->east = ft_strtrim(line + 3, " \t");

		if (data->texture->east[0] == '\0')
			ft_print_error(data, "East Texture cant' be empty.");

		if (ft_strcmp(data->texture->east + ft_strlen(data->texture->east) - 4, ".xpm") != 0)
			ft_print_error(data, "East Texture must end with the .xpm extension.");

		fd = open(data->texture->east, O_RDONLY);
		if (fd == -1)
			ft_print_error(data, "EA xpm file not found or can't be opened.");
		close(fd);
	}

	// Seviye 2
	// burada data->texture->east != NULL olmalı gibi duruyor.
	// çünkü eğer hem doğru EA hem yanlış EA varsa, doğruyu bulmuş olmasına rağmen yanlış EA için space uyarısı vermemli.
	// bu durumda space olmayan EA'yı sanki alakasız bir şey girmiş gibi kabul etmeli.
	if (space == 0 && ft_strncmp("EA", line, 2) == 0 && line[2] != ' ')
		ft_print_error(data, "The EA identifier must be followed by a space character.");
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

2. Seviye : Eğer 1. Seviyeyi geçtiyse 2 ihtimal vardır. Ya ID bulunmuştur ve validasyonları geçmiştir ya da ID sonrasında space girilmemiştir.
Bunu anlamak için texture değerine bakabiliriz. Eğer 1. seviyeyi geçmesine rağmen NULL değilse demek ki hiçbir sorun yok.
	- ID değerinden sonra mutlaka en az 1 space girilmesini istiyoruz.

3. Seviye : Eğer 2. Seviyeyi geçtiyse 3 ihtimal vardır.
	1 - Texture değeri NULL değilse ID bulunmuştur ve validasyonları geçmiştir.
	2 - Texture değeri NULL ise ID değeri dosya da yok.

*/
void ft_validate_textures(t_data *data)
{
	char *line;
	int i;

	line = NULL;
	i = 0;
	while (i < 6)
	{
		line = data->config->lines[i];
		ft_validate_north_texture(data, line, 1);
		ft_validate_south_texture(data, line, 1);
		ft_validate_west_texture(data, line, 1);
		ft_validate_east_texture(data, line, 1);
		i++;
	}
	line = NULL;
	i = 0;
	while (i < 6)
	{
		line = data->config->lines[i];
		ft_validate_north_texture(data, line, 0);
		ft_validate_south_texture(data, line, 0);
		ft_validate_west_texture(data, line, 0);
		ft_validate_east_texture(data, line, 0);
		i++;
	}
}