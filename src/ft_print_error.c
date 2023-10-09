/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 23:04:48 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/06 23:05:07 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_print_error(t_data *data, char *message)
{
	printf("Error!\n%s\n", message);
	ft_clear_data(data);
	exit(EXIT_FAILURE);
}
