/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_print_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 23:30:11 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/09 01:33:24 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_cub3d.h"

void	b_print_error(t_cub3d *cub3d, char *message)
{
	printf("Error!\n%s\n", message);
	b_free_cub3d(cub3d);
	exit(EXIT_FAILURE);
}
