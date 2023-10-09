/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:02:53 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/06 23:26:02 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char *ft_fill_string(char *string, int fd)
{
	char *buffer;
	int readed_byte;

	buffer = ft_create_empty_string(2);
	if (buffer == NULL)
		return (NULL);
	readed_byte = 61;
	while (readed_byte != 0 && ft_has_line_feed(buffer) == 0)
	{
		readed_byte = read(fd, buffer, 1);
		if (readed_byte == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[readed_byte] = '\0';
		string = ft_add_buffer_to_string(string, buffer);
	}
	free(buffer);
	return (string);
}

char *ft_get_first_line(char *string)
{
	char *line;
	int len;

	len = 0;
	while (string[len] != '\0' && string[len] != '\n')
		len++;
	line = (char *)malloc(sizeof(char) * (len + 2));
	if (line == NULL)
		return (NULL);
	len = 0;
	while (string[len] != '\0' && string[len] != '\n')
	{
		line[len] = string[len];
		len++;
	}
	if (string[len] == '\n')
	{
		line[len] = string[len];
		len++;
	}
	line[len] = '\0';
	return (line);
}

char *ft_delete_first_line(char *string)
{
	char *new_str;
	int line_len;
	int i;

	line_len = 0;
	while (string[line_len] != '\0' && string[line_len] != '\n')
		line_len++;
	if (string[line_len] == '\0')
	{
		free(string);
		return (NULL);
	}
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(string) - line_len + 1));
	if (new_str == NULL)
		return (NULL);
	line_len++;
	i = 0;
	while (string[line_len] != '\0')
		new_str[i++] = string[line_len++];
	new_str[i] = '\0';
	free(string);
	return (new_str);
}

char *get_next_line(int fd)
{
	static char *string;
	char *line;

	if (fd < 0)
		return (NULL);
	string = ft_fill_string(string, fd);
	printf("String : %s\n", string);
	if (string == NULL)
		return (NULL);
	if (*string == '\0')
	{
		free(string);
		string = NULL;
		return (NULL);
	}
	line = ft_get_first_line(string);
	string = ft_delete_first_line(string);

	printf("Line : %s\n", line);
	printf("String : %s\n", string);

	return (line);
}
