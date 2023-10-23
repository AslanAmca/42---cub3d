/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_double_pointer.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:16:40 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/14 14:16:42 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void free_double_pointer(char **pointer)
{
	int i;

	if (pointer == NULL)
		return;
	i = 0;
	while (pointer[i] != NULL)
	{
		free(pointer[i]);
		i++;
	}
	free(pointer);
}