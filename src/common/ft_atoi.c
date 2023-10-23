/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:09:14 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/23 20:43:00 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int ft_atoi(char *nptr)
{
	int sign;
	int result;

	sign = 1;
	result = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '+')
		nptr++;
	else if (*nptr == '-')
	{
		sign = sign * -1;
		nptr++;
	}
	while (ft_is_digit(*nptr))
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (result * sign);
}
