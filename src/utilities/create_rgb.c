/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 04:30:08 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/04 04:30:42 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

int create_rgb(int red, int green, int blue)
{
	int rgb;

	rgb = (red << 16 | green << 8 | blue);
	return (rgb);
}
