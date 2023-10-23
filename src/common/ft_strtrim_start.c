/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft_strtrim_start.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:24:20 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/17 13:11:25 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

char *ft_ft_strtrim_start(char *s1, char *set)
{
	if (s1 == NULL || set == NULL)
		return NULL;
	while (ft_strchr(set, *s1) && *s1 != '\0')
		s1++;
	return ft_strdup(s1);
}
