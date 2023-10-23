/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 23:30:11 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/24 00:10:13 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void print_error(t_cub3d *cub3d, char *message)
{
	printf("Error!\n%s\n", message);
	free_cub3d(cub3d);
	exit(EXIT_FAILURE);
}
