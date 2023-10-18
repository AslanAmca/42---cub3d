/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:33:12 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/18 14:01:16 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

char *ft_strtrim(char *s1, char *set)
{
	int size;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while (ft_strchr(set, *s1) && *s1 != '\0')
		s1++;
	size = ft_strlen(s1);
	while (ft_strchr(set, s1[size]) && size != 0)
		size--;
	return (ft_substr(s1, 0, size + 1));
}
