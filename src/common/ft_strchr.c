/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:32:00 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/23 20:43:00 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

char *ft_strchr(char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
			return (s);
		s++;
	}
	if (c == '\0')
		return (s);
	return (NULL);
}