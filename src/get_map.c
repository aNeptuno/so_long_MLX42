/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:43:20 by adiban-i          #+#    #+#             */
/*   Updated: 2024/07/02 16:58:31 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	close_and_check_errors(t_game_data *game_data, ssize_t	bytes_read)
{
	if (bytes_read == -1)
		error_and_free(game_data, "Error reading file");
	if (close(game_data->fd) == -1)
		error_and_free(game_data, "Error closing the file");
}

// Read the file and save it to a string
static void	read_file(t_game_data *game_data)
{
	ssize_t	bytes_read;
	char	buffer[BUFFER_SIZE];
	size_t	content_size;
	char	*new_file_content;

	if (game_data->fd != -1)
	{
		content_size = 0;
		game_data->file_content = NULL;
		bytes_read = 1;
		while (bytes_read > 0)
		{
			bytes_read = read(game_data->fd, buffer, BUFFER_SIZE);
			new_file_content = my_realloc(game_data->file_content,
					content_size + bytes_read + 1, content_size);
			if (new_file_content == NULL)
				error_and_free(game_data, "Error allocating memory");
			game_data->file_content = new_file_content;
			ft_memcpy(game_data->file_content + content_size,
				buffer, bytes_read);
			content_size += bytes_read;
			game_data->file_content[content_size] = '\0';
		}
		close_and_check_errors(game_data, bytes_read);
	}
}

static int	is_valid_file_name(char *file_path)
{
	char	*last_is_ber_ext;
	int		not_just_dotber;
	char	*first_ber_ext;

	last_is_ber_ext = ft_strstr(file_path + (ft_strlen(file_path) - 4), ".ber");
	not_just_dotber = ft_strlen(file_path) != ft_strlen(".ber");
	if (last_is_ber_ext && not_just_dotber)
	{
		first_ber_ext = ft_strstr(file_path, ".ber");
		if (ft_strlen(first_ber_ext) != ft_strlen(last_is_ber_ext))
			return (0);
		else
			return (1);
	}
	else
		return (0);
}

static void	open_file(char	*file_path, t_game_data *game_data)
{
	int	fd;

	if (is_valid_file_name(file_path))
	{
		fd = open(file_path, O_RDONLY);
		if (fd == -1)
		{
			perror("Error\nError opening the file");
			exit(EXIT_FAILURE);
		}
		game_data->fd = fd;
	}
	else
	{
		ft_putstr("Error\nIncorrect file extension (extension must be .ber)\n");
		exit(EXIT_FAILURE);
		game_data->fd = -1;
	}
	return ;
}

void	get_map(t_game_data *game_data, char *file_content)
{
	open_file(file_content, game_data);
	read_file(game_data);
	if (game_data->file_content)
	{
		validate_map(game_data);
		if (game_data->is_map_valid)
		{
			game_data->size_x = game_data->cols * PIXELS;
			game_data->size_y = game_data->rows * PIXELS + HEADER_HEIGHT;
		}
	}
}
