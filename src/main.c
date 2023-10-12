/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:38:43 by aaslan            #+#    #+#             */
/*   Updated: 2023/10/12 17:05:31 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_check_map_empty_line(t_data *data)
{
	char *line;
	int i;
	int fd;

	fd = open(data->config->filename, O_RDONLY);
	if (fd == -1)
		ft_print_error(data, "An error occurred while opening the map file.");
	line = NULL;
	i = 1;
	while (i <= data->config->total_line_count)
	{
		line = ft_get_next_line(data, fd);
		if (ft_is_empty_line(line) && i > data->map_starting_line)
		{
			free(line);
			line = NULL;
			ft_print_error(data, "There can't be empty line within or after the map.");
		}
		free(line);
		line = NULL;
		i++;
	}
	close(fd);
}

void ft_set_lines(t_data *data)
{
	int fd = open(data->config->filename, O_RDONLY);
	if (fd == -1)
		ft_print_error(data, "An error occurred while opening the map file.");

	data->config->lines = (char **)malloc(sizeof(char *) * (data->config->full_line_count + 1));
	if (data->config->lines == NULL)
		ft_print_error(data, "malloc error");
	data->config->lines[data->config->full_line_count] = NULL;

	int i = 0;
	char *line = NULL;
	while (i < data->config->full_line_count)
	{
		line = ft_get_next_line(data, fd);

		if (!ft_is_empty_line(line))
		{
			data->config->lines[i] = line;
			i++;
		}
		else
		{
			free(line);
			line = NULL;
		}
	}
	close(fd);
}

int main(int argc, char **argv)
{
	t_data *data;

	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		ft_print_error(data, "t_data is null.");
	ft_init_data(data, argv[1]);
	ft_validate_argument(data, argc);
	ft_validate_config_is_empty(data);

	ft_set_line_count(data);
	ft_set_lines(data);

	ft_set_elements_count(data);
	ft_validate_elements(data);

	// buna texture ve color sonrasında bakacağız.
	// ft_check_map_empty_line(data);

	// buraya kadar hata olmazsa ft_print_error üzerinden clear_data çalışmıyor.
	// dolayısıyla memory leak oluyor. şimdilik burada manuel clear yapalım.
	ft_clear_data(data);

	return 0;
}
