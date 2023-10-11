/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_start.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:24:20 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/11 18:24:33 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char *ft_strtrim_start(char *s1, char *set)
{
	if (s1 == NULL || set == NULL)
		return NULL;
	while (ft_strchr(set, *s1) && *s1 != '\0')
		s1++;
	return ft_strdup(s1);
}