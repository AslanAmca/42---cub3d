/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:32:58 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/17 13:11:40 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char *ft_substr(char *s, int start, int len)
{
	char *string;
	int size;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) - 1 < start)
		return (ft_strdup(""));
	s = s + start;
	size = ft_strlen(s);
	if (size < len)
		len = size;
	string = malloc(sizeof(char) * (len + 1));
	ft_strlcpy(string, s, len + 1);
	return (string);
}