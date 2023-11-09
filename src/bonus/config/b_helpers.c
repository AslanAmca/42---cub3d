/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_helpers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 03:15:13 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/09 03:17:36 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../b_cub3d.h"

int	b_not_wall(char character)
{
	if (character == '0' || character == 'D')
	{
		return (1);
	}
	return (0);
}

void	b_get_player_position(t_cub3d *cub3d, int *row, int *col)
{
	char	chr;
	int		r;
	int		c;

	chr = '\0';
	r = 0;
	while (cub3d->config->map->text[r] != NULL)
	{
		c = 0;
		while (cub3d->config->map->text[r][c] != '\0')
		{
			chr = cub3d->config->map->text[r][c];
			if (chr == 'N' || chr == 'S' || chr == 'W' || chr == 'E')
			{
				*row = r;
				*col = c;
				return ;
			}
			c++;
		}
		r++;
	}
}
