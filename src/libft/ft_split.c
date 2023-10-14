/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:21:46 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/14 20:27:11 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void ft_split_clear(char **result)
{
	int i;

	if (result == NULL)
		return;
	i = 0;
	while (result[i] != NULL)
	{
		free(result[i]);
		result[i] = NULL;
		i++;
	}
	free(result);
	result = NULL;
}

static int ft_split_word_count(char *string, char delimiter)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == delimiter)
			count++;
		i++;
	}
	if (count > 0)
		count++;
	return count;
}

static int ft_split_fill(char **result, char *string, char delimiter, int word_count)
{
	char *word_start;
	int word_len;
	int i;

	word_start = string;
	i = 0;
	while (i < word_count)
	{
		while (*string != delimiter && *string != '\0')
			string++;
		word_len = string - word_start;
		result[i] = malloc(word_len + 1);
		if (result[i] == NULL)
			return 0;
		ft_strncpy(result[i], word_start, word_len);
		result[i][word_len] = '\0';
		word_start = ++string;
		i++;
	}
	return 1;
}

char **ft_split(char *string, char delimiter)
{
	char **result;
	int word_count;
	int success_split;

	if (string == NULL)
		return NULL;
	word_count = ft_split_word_count(string, delimiter);
	if (word_count == 0)
		return NULL;
	result = malloc(sizeof(char *) * (word_count + 1));
	if (result == NULL)
		return NULL;
	result[word_count] = NULL;
	success_split = ft_split_fill(result, string, delimiter, word_count);
	if (success_split == 0)
	{
		ft_split_clear(result);
		return NULL;
	}
	return result;
}