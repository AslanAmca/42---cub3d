/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:32:26 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/23 20:43:00 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int ft_strlcpy(char *dest, char *src, int n)
{
	int src_length;

	src_length = ft_strlen(src);
	while (*src != '\0' && 1 < n)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	if (n != 0)
		*dest = '\0';
	return (src_length);
}